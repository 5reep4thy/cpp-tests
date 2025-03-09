#include <iostream>
int func(int a) {
    return 15;
}
struct a {
    long a;
    int x;
};
struct b {
    int a, b, c;
};
int main() {
    std::cout << sizeof(a) << "\n";
    std::cout << sizeof(b) << "\n";
    int (*fptr)(int);
    typedef int (*fptr_t)(int);
    fptr_t ff = func;
    fptr = func;
    int y = fptr(12);
    int z = ff(12);
    std::cout << y << "\n";
    std::cout << z << "\n";
    return 0;
}
