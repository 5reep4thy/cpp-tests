#include <bits/stdc++.h>
using namespace std;

class A {
    public:
    int x;
    A (int x): x(x) { cout << "Int constructor used\n";}
    A () :x(1) {
        cout << "Default constructor used\n";
    }
    A ( A& a) {
        cout << "Lvalue constructor used\n";
    }

    A (const A& a) {
        cout << "Copy constructor used\n";
    }

    A (A&& a) {
        cout << "Move constructor used\n";
    }

    // A (A&& a) = default;

    A operator= (A a) {
        cout << "Copy assignment used\n";
        return a;
    }
};
void f1(const A& a) {
}

A func() {
    A a;
    A b;
    volatile int x = 0;
    cout << "Address of a inside function is: " << &a << "\n";
    if (x % 2 == 0)
        return a;
    return b;
}

template <typename T>
void print(T&& t) {
    std::cout << "Print function\n";
}

// Perfect forwarding
template <typename T>
void test(T&& t) {
    print(std::forward<T>(t));
}

int main() {

    // Move constructor called in both cases since we can't perform copy elision
    // If move constructor isn't declared, copy constructor is used
    // If move constructor is deleted, return a, return b becomes invalid in func()
    A d(func());
    A e = func();

    // Perfect forwarding example
    test(e);

    // auto&& can bind to temporary and create a local variable, or it can bind as a lvalue reference
    auto&& va = d;
    cout << "--------------------------\n";
    auto&& x(func());
    cout << "--------------------------\n";
    A&& xx = func();
    return 0;
}