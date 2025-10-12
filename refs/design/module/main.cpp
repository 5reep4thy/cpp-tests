#include <iostream>
import math;
int main() {
    int a = 2, b = 3;
    int result = 0;
    result = add(a, b);
    std::cout << "Math module called\n";
    std::cout << "Added " << a << ", " << b << ";\n";
    std::cout << "Result: " << result << "\n";
    return 0;
}