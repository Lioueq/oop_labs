#pragma once
#include <memory_resource>
#include <list>
#include <vector>

class FixedBlockMemoryResource : public std::pmr::memory_resource {
public:
    FixedBlockMemoryResource(size_t blockSize, size_t blockCount)
        : blockSize_(blockSize), blockCount_(blockCount), memory_(blockSize * blockCount) {
        for (size_t i = 0; i < blockCount_; ++i) {
            freeBlocks_.push_back(memory_.data() + i * blockSize_);
        }
    }

    ~FixedBlockMemoryResource() {
        freeBlocks_.clear();
    }

protected:
    void* do_allocate(size_t bytes, size_t alignment) override {
        if (bytes > blockSize_ || freeBlocks_.empty()) {
            throw std::bad_alloc();
        }
        void* ptr = freeBlocks_.back();
        freeBlocks_.pop_back();
        return ptr;
    }

    void do_deallocate(void* p, size_t bytes, size_t alignment) override {
        freeBlocks_.push_back(p);
    }

    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }

private:
    size_t blockSize_;
    size_t blockCount_;
    std::vector<std::byte> memory_;
    std::list<void*> freeBlocks_;
};