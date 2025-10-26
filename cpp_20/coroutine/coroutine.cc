#include <coroutine>
#include <cstdlib>
#include <iostream>
#include <ostream>

struct Generator {
    struct promise_type;
    using handleType = std::coroutine_handle<promise_type>;
    struct promise_type {
        int currentValue;
        std::suspend_always yield_value(int value) {
            currentValue = value;
            return {};
        }
        std::suspend_always initial_suspend() { return {};}
        std::suspend_always final_suspend() noexcept{ return {};}
        Generator get_return_object() {
            return Generator{handleType::from_promise(*this)};
        }
        void returnVoid() {}
        void unhandled_exception() {
            std::exit(1);
        }
    };
    handleType coroutineHandle;
    Generator(handleType hType) : coroutineHandle(hType) {}
    ~Generator() { if(coroutineHandle) coroutineHandle.destroy(); }

    bool moveNext() { 
        coroutineHandle.resume();
        return !coroutineHandle.done();
    }

    int currentValue() const {
        return coroutineHandle.promise().currentValue;
    }
};
Generator counter(int max) {
    for (int i=1; i<=max;i++) {
        co_yield i;
    }
}

int main() {
    auto gen = counter(10);
    while (gen.moveNext()) {
        std::cout << gen.currentValue() << " ";
    }
    std::cout << std::endl;
}