#include <bits/stdc++.h>
using namespace std;
class A {
    public:
        int x;
        int getz() {
            return z;
        }
    protected:
        A() {};
        ~A() {
            cout << "Destructing class A\n";
        };
        int y;
    private:
        int z;
};
class B: public A {
        void getbb() {}
    public:
        void getzz() {
            y = 12; // valid
            // z = 12; // invalid
        }
};
class C: protected A {
    public:
        void getzz() {
            y = 12; // valid
            x = 12; // x is protected here
        }
};
int main () {
    B b;
    b.x = 19;
    // b.y = 12; // invalid since y is protected
    b.getz();

    return 0;
}