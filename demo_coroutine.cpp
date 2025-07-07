#include <coroutine>
#include <iostream>
#include <optional>


template<typename T>
struct Generator {
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    struct promise_type {
        T current_value;
        std::suspend_always yield_value(T value) {
            current_value = value;
            return {};
        }

        std::suspend_always initial_suspend() {return {};}
        std::suspend_always final_suspend() noexcept {return {};}

        Generator get_return_object() {
            return Generator {handle_type::from_promise(*this)};
        }

        void return_void() {}
        void unhandled_exception() {std::terminate();}
    };

    handle_type coro;

    Generator(handle_type h) : coro(h) {}
    ~Generator() {if (coro) coro.destroy(); }

    bool next() {
        if (!coro.done()) {
            coro.resume();
        }
        return !coro.done();
    }

    T value() const {
        return coro.promise().current_value;
    }
};


void demo_coroutine() {

}