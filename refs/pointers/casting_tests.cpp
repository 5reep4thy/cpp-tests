#include <bits/stdc++.h>
template <class To, class From>
To safe_reinterpret_cast(From from) {

    // Comment out the following line to see size check in action
    // static_assert(sizeof(typename std::remove_pointer<To>::type) <= sizeof(typename std::remove_pointer<From>::type))

    if (sizeof(typename std::remove_pointer<To>::type) <= sizeof(typename std::remove_pointer<From>::type)) {
        return reinterpret_cast<To>(from);
    }
    std::cout << "Cannot reinterpret case type of higher size to lower size\n";
    return nullptr;
    assert(false);
}
int main() {
    char* c = new char();
    int* x = safe_reinterpret_cast<int*>(c);
    return 0;
}