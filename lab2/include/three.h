#pragma once

#include <string>
#include <iostream>

class Three {
    private:
        size_t _size;
        unsigned char *_array;
    public:
        Three();
        Three(const size_t &n, unsigned char t = 0);
        Three(const std::initializer_list <unsigned char> &t);
        Three(const std::string &t);
        Three(const Three &other);
        Three(Three&& other) noexcept;

        bool isGreaterThan(const Three &other) const;
        bool isLessThan(const Three &other) const;
        bool isEqualTo(const Three &other) const;

        Three add(const Three &other);
        Three subtract(const Three &other);
        std::ostream& print(std::ostream& os);

        std::string toString();

        virtual ~Three() noexcept;
};