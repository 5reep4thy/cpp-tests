#include <bits/stdc++.h>
using namespace std;
// Primary template
template<typename T, typename U>
struct is_samee : std::false_type {};

// Partial specialization for when types are the same
template<typename T>
struct is_samee<T, T> : std::true_type {};

// Helper variable template (C++14 style)
template<typename T, typename U>
inline constexpr bool is_samee_v = is_samee<T, U>::value;


template<class T>
struct trait_tester {
    using type = T;
    static constexpr T val = 12;
};

int main() {
    cout << is_samee_v<int, double> << "\n";
    cout << is_samee_v<double, double> << "\n";
    float *y = new float(13);
    int *x = new int(12);
    float* j =reinterpret_cast<float*> (x);
    cout << *j << "\n";
    trait_tester<int>::type ti; 

    //Size of empty class in c++ is 1, in c it's 0
    cout << "size of trait_tester: " << sizeof(trait_tester<int>::type) << "\n";
    cout << "value of trait_tester: " << trait_tester<int>::val << "\n";
    return 0;
}