#include <bits/stdc++.h>

/* Run this program with leaks/valgrind to learn something new :) */
/* Usage - leaks -atExit -- ./a.out | grep LEAK: */

/* Single use allocator (for test purpose) */
class allocator {
    public:
    void* loc = nullptr;
    allocator() {
        loc = malloc(1000);
    }
    void* allocate(size_t x){
        return loc;
    }
    void deallocate(void* loc) {
        free(loc);
        loc = nullptr;
    }
};

allocator* al;

class cl {
public:
    int x;
    char y;
    float z;
    allocator* memloc;
    cl(allocator* loc) : memloc(loc){
        std::cout << "Default constructor called\n";
    }
    ~cl() {
        memloc = nullptr;
        std::cout << "Destructor called\n";
    }
    void* operator new(size_t x, allocator* al) {
        int jj = x;
        void* pl = al->allocate(x);
        return pl;
    }
    void operator delete( void* loc) {
        al->deallocate(loc);
    }
};
int main() {
    al = new allocator;
    // Use allocator
    cl* x = new (al) cl(al);
    delete x;
    delete al;

    // delete(x) -> frees memory, calls destructor
    // delete(y) -> frees memory, doesn't call destructor

    std::cout << "Hello world\n";
    return 0;
}