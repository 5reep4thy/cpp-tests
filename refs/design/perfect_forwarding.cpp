#include <iostream>
#include <utility> // for std::forward
class MyClass {
  public:
    MyClass() {
        std::cout << "Default constructor\n";
    }
    MyClass(const MyClass&) {
        std::cout << "Copy constructor\n";
    }
    MyClass(MyClass&&) {
        std::cout << "Move constructor\n";
    }
    MyClass(int a, double b) {
        std::cout << "Constructor with int=" << a << ", double=" << b << "\n";
    }
};
// A factory function without perfect forwarding (only for one argument for simplicity)
template <typename T, typename Arg>
T create_no_forwarding(Arg a) {
    return T(a);
}
// A factory function with perfect forwarding
template <typename T, typename... Args>
T create(Args&&... args) {
    return T(std::forward<Args>(args)...);
}
int main() {
    std::cout << "Creating with no forwarding:\n";
    // We pass an rvalue (temporary) of MyClass to create_no_forwarding.
    // Inside the function, 'a' is an lvalue, so the copy constructor is called.
    MyClass obj1 = create_no_forwarding<MyClass>(MyClass{});
    exit(0);
    std::cout << "\nCreating with perfect forwarding:\n";
    // Here, the temporary MyClass{} is forwarded as an rvalue, so the move constructor is used.
    MyClass obj2 = create<MyClass>(MyClass{});
    std::cout << "\nCreating with lvalue and perfect forwarding:\n";
    MyClass existing;
    // We pass an lvalue. Inside create, it is passed as an lvalue to the constructor.
    MyClass obj3 = create<MyClass>(existing);
    std::cout << "\nCreating with multiple arguments:\n";
    auto obj4 = create<MyClass>(10, 20.5); // calls MyClass(int, double)
    return 0;
}