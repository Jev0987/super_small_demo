/*
 * @Descripttion: 由demo2启发，promise 的传值方式，还可以用ref
 * @Author: jev
 * @version: 
 * @Date: 2025-02-22
 * @LastEditors: jev
 * @LastEditTime: 2025-02-22
 */
#include <iostream>
#include <future>
#include <chrono>
#include <thread>

// 异步，将结果通过promise传递
// !!!promise_是一个引用，所以需要用std::ref包装
void onAdd(std::promise<int> &p, int a, int b) {
    p.set_value(a + b);
}

void demo_promise_ref() {
    std::cout << __func__ << std::endl;
    // “承诺”，在某个时刻会提供一个值或者异常
    std::promise<int> promise_;

    // 用来获取这个值的 “未来对象”
    std::future<int> future_ = promise_.get_future();

    // 新线程调用onAdd函数，将promise_作为参数传递
    std::thread t(onAdd, std::ref(promise_), 1, 2);

    // 主线程通过future_获取结果
    std::cout << "future get: " << future_.get() << std::endl;

    // 等待子线程结束
    t.join();
}