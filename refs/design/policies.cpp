#include <bits/stdc++.h>
using namespace std;

// Templating + multiple inheritance (Reduced/less runtime poly)

template <class T>
struct OpNewCreator {
    T* val;
    public:
    T* Create() {
        val = new T;
        return val;
    }

    // Only the derived class can call the ctor and dtor. This class can't be used outside in a straightforward manner.
    protected:
    OpNewCreator() {}
    ~OpNewCreator() {
        if ( val != nullptr )
            delete val;
    }
};

template <class creationPolicy>
class Intobject: creationPolicy {
    public:
        int* y;
    Intobject() {
        y = creationPolicy::Create();
        *y = 12;
    }
};

template < template <class> class creationPolicy>
class Intobject2: creationPolicy<int> {
    public:
        int* y;
    Intobject2() {
        // allocated int will be cleaned up by the creationPolicy
        y = creationPolicy<int>::Create();
        *y = 14;
    }
};

int main() {

    // Specify it here redundantly
    Intobject<OpNewCreator<int>> o1;

    // Remove redundancy as it's evident that int will get created and is used explicitly in Intobject2's base class
    Intobject2<OpNewCreator> o2;

    cout << *(o1.y) << "\n";
    cout << *(o2.y) << "\n";


    return 0;
}