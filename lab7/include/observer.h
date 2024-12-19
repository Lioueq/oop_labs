#pragma once
#include <NPC.h>

// Text Observer
class TextObserver : public IFightObserver {
   private:
    TextObserver() {};

   public:
    static std::shared_ptr<IFightObserver> get() noexcept {
        static TextObserver instance;
        return std::shared_ptr<IFightObserver>(&instance,
                                               [](IFightObserver *) {});
    }

    void on_fight(const std::shared_ptr<NPC> attacker,
                  const std::shared_ptr<NPC> defender,
                  bool win) noexcept override {
        if (win) {
            std::cout << "Murder --------" << std::endl;
            attacker->print();
            std::cout << " KILLED BY ";
            defender->print();
            std::cout << '\n';
        }
    }
};

// Log Observer
class LogObserver : public IFightObserver {
   private:
    const std::string filename;
    std::ofstream os;

    LogObserver() : filename("log.txt"), os(filename) {}

   public:
    static std::shared_ptr<IFightObserver> get() noexcept {
        static LogObserver instance;
        return std::shared_ptr<IFightObserver>(&instance,
                                               [](IFightObserver *) {});
    }

    void on_fight(const std::shared_ptr<NPC> attacker,
                  const std::shared_ptr<NPC> defender,
                  bool win) noexcept override {
        if (win) {
            os << "Murder --------" << std::endl;
            os << *attacker << " KILLED BY " << *defender << "\n";
        }
    }
};