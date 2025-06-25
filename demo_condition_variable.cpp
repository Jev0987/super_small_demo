/*
 * @Descripttion: 条件变量使用
 * @Author: jev
 * @Date: 2025-06-25
 */
#include <thread>
#include <iostream>
#include <condition_variable>
#include <mutex>

using namespace std;

void waitting_thread(mutex &cur_mtx, condition_variable &cv, bool &ready) {
    unique_lock<mutex> lck(cur_mtx);

    cv.wait(lck, [&]() {return ready;});

    cout << "get condition variable, doing something..." << endl;
}

void notify_thread(mutex &cur_mtx, condition_variable &cv, bool &ready) {
    
    {
        unique_lock<mutex> lck(cur_mtx);
        cout << "get mutex, change state" << endl;
        ready = true;
        lck.unlock();
    }

    cv.notify_all();
}

void demo_condition_variable() {
    mutex mtx;
    condition_variable cv;
    bool ready = false;
    thread t1(waitting_thread, std::ref(mtx), std::ref(cv), std::ref(ready));
    thread t2(notify_thread, std::ref(mtx), std::ref(cv), std::ref(ready));

    t1.join();
    t2.join();
}