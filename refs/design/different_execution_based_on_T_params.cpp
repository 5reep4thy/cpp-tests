#include <bits/stdc++.h>
//  We cannot have an if-else condition inside performaction because we don't
//  know the type of T. T::cat_meow, can't be written because if T was a dog, it
//  would've given a compile error
class Cat {
public:
  static void cat_meow() { std::cout << "Meow\n"; }
};
class Dog {
public:
  static void dog_bark() { std::cout << "Bark\n"; }
};
template <bool v> struct DogOrCat {
  enum { value = v };
};

template <class T, bool iscat> class PerformAction {
public:
  void performaction_actual(DogOrCat<true>) { T::cat_meow(); }
  void performaction_actual(DogOrCat<false>) { T::dog_bark(); }
  void performaction() { performaction_actual(DogOrCat<iscat>()); }
};
int main() {
  Cat cat;
  Dog dog;
  PerformAction<Cat, true> p;
  PerformAction<Dog, false> p;
  p.performaction();
  return 0;
}