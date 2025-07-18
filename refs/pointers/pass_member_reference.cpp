#include <bits/stdc++.h>
using namespace std;

struct obj {
    int id;
    char c;
};

template <typename T>
bool comp(obj a, T obj::*cc) {
    cout << a.*cc << "\n";
    return 0;
}

int main() {
    obj a{18, 'c'}, b{2, 'a'};
    comp(a, &obj::id);
    return 0;
}