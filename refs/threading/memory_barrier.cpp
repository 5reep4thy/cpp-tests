#include <thread>
#include <iostream>
static std::atomic<int> cnt = 0;
static int glb = 0;
void func1() {
    int y = cnt.load(std::memory_order_acquire);
    std::cout << y << "\n";
    std::cout << glb << "\n";

}
void func2() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    glb = 13;
    cnt.store(12, std::memory_order_release);
}
int main() {
    std::thread T1(func1);
    std::thread T2(func2);
    T1.join();
    T2.join();
    return 0;
}