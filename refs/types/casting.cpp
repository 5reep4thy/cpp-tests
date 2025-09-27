#include <bits/stdc++.h>
using namespace std;
// https://en.cppreference.com/w/cpp/language/implicit_conversion.html
class Animal {
  public:
    int m_index = -1;
    Animal& operator=(const Animal& animalSource) {
        m_index = animalSource.m_index;
        return *this;
    }
    operator int() {
        cout << "Converting Animal to int\n";
        return m_index;
    }
};

class Star {
  public:
    int m_index = -2;
    operator Animal() {
        cout << "Converting star to animal\n";
        return Animal{};
    }
    Star(const Animal& animal) {
        m_index = animal.m_index;
    }
    Star() = default;
};

class Dog : public Animal {
  public:
    bool m_loudBark;
};
int main() {
    Animal dog;
    float x = dog;
    cout << x << "\n";
    Star star;
    dog = star;
    cout << dog.m_index << "\n";
    return 0;
}