#include <bits/stdc++.h>
#include <coroutine>

// coroutines - functions that can suspend thenselves and can be resumed
struct ReturnObject {
    struct promise_type {
        std::suspend_never initial_suspend() {
            return {};
        }
        std::suspend_never final_suspend() noexcept {
            return {};
        }
        ReturnObject get_return_object() {
            return {};
        }
        void unhandled_exception() {
        }
    };
};
ReturnObject foo() {
    std::cout << "xxxxx 1 xxxxx\n";
    co_await std::suspend_always{};
    std::cout << "xxxxx 2 xxxxx\n";
}
int main() {
    foo();
    return 0;
}