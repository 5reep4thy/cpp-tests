#include <bits/stdc++.h>
struct C {
    int x, y;
};

// Reference to a pointer
void pointerRef(int*& x) {
    static int* y = new int(12);
    x = y;
}

// array pointer
void ChangeArrayVal (int (*b)[12]) {
    (*b)[1] = 13;
    return;
}
void ChangeArrayValInMultiDim(int (*b)[3][2]) {
    (*b)[0][0] = 16;
    return;
}
int main() {
    int* x = new int(11);
    pointerRef(x);
    ////////////////////////////
    int* b = new int[12];
    int (*c)[12] = (int(*)[12])b;
    ChangeArrayVal(c);
    std::cout << b[1] << "\n";
    int* d = new int[12];
    c = (int(*)[12])d;
    delete [] c;
    int multiDimArray[3][2] = {{1, 2}, {2, 5}, {5, 7}};
    ChangeArrayValInMultiDim((int(*)[3][2])multiDimArray);
    std::cout << multiDimArray[0][0] << "\n";

}