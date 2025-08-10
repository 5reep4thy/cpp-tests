#include <bits/stdc++.h>
template <class Tp>
class A {
  public:
    Tp a;
    A() {};
    A(std::remove_reference_t<Tp> toAdd, Tp initVal) : a(initVal) {
        a += toAdd;
    };
};
int main() {
    int y = 12;
    A<int&> x(13, y);
    std::cout << x.a << "\n";
    return 0;
}