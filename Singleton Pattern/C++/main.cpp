#include <iostream>

class Singleton {
    private:
        static Singleton *singleton_;
        std::string value_;
        Singleton(const std::string value): value_(value) {}
    public:
        Singleton(Singleton &other) = delete;
        void operator=(const Singleton &) = delete;
        
        static Singleton* getInstance(const std::string &value);

        std::string getValue() const {
            return value_;
        }
};

Singleton* Singleton::singleton_ = nullptr;

Singleton* Singleton::getInstance(const std::string &value) {
    if (singleton_ == nullptr)
        singleton_ = new Singleton(value);
    return singleton_;
}

int main() {

    Singleton* singleton1 = Singleton::getInstance("Foo");
    std::cout << "Singleton Foo->value : " << singleton1->getValue() << "\n";

    Singleton* singleton2 = Singleton::getInstance("Bar");
    std::cout << "Singleton Bar->value : " << singleton2->getValue() << "\n";
    
    return 0;
}