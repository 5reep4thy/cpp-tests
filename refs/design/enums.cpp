#include <bits/stdc++.h>

template <int v>
struct Int2Type
{
    int xx = 12;
    enum { value = v };
};
int main() {
    Int2Type<5> x;
    std::cout << x.value << "\n";
    return 0;
}