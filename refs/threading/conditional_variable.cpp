#include <chrono>
#include <thread>
#include <iostream>
std::condition_variable cv;
std::mutex m_cnt;
int cnt = 0;
void producer() {
  while (1) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::unique_lock<std::mutex> ul(m_cnt);
    cv.wait(ul, [] {return cnt % 2 == 1;});
    cnt++;
    std::cout << cnt << "\n";
    cv.notify_one();
    // std::this_thread::sleep_for(std::chrono::seconds(2));
  }
}
void consumer() {
  while (1) {
    // std::this_thread::sleep_for(std::chrono::seconds(1));
    std::unique_lock<std::mutex> ul(m_cnt);
    cv.wait(ul, [] {return cnt % 2 == 0;});
    cnt++;
    std::cout << cnt << "\n";
    cv.notify_one();
  }
}

int main () {
  std::thread T1(producer);
  std::thread T2(consumer);
  T1.join();
  T2.join();
  return 0;
}