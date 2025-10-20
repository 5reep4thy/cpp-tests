#include <bits/stdc++.h>
#include <coroutine>

// coroutines - functions that can suspend themselves and can be resumed
struct ReturnObject {
    struct promise_type {
        std::suspend_never initial_suspend() {
            return {};
        }
        std::suspend_never final_suspend() noexcept {
            return {};
        }
        ReturnObject get_return_object() {
            return ReturnObject{std::coroutine_handle<promise_type>::from_promise(*this)};
        }
        void unhandled_exception() {
        }
    };
    std::coroutine_handle<> handle;
    ReturnObject(std::coroutine_handle<> _handle) : handle(_handle) {
    }
};
ReturnObject foo() {
    std::cout << "xxxxx 1 xxxxx\n";
    co_await std::suspend_always{};
    std::cout << "xxxxx 2 xxxxx\n";
    co_await std::suspend_always{};
    std::cout << "xxxxx 3 xxxxx\n";
}
int main() {
    ReturnObject ret = foo();
    ret.handle.resume();
    std::cout << std::boolalpha << ret.handle.done();
    std::cout << "\n";
    ret.handle();
    std::boolalpha(std::cout << ret.handle.done());
    return 0;
}