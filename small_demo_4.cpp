/*
 * @Descripttion: 利用async创建异步任务
 * @Author: jev
 * @version: 
 * @Date: 2025-02-22
 * @LastEditors: jev
 * @LastEditTime: 2025-02-22
 */

#include <iostream>
#include <future>

int calculate_num(int x) {
    // std::cout << std::this_thread::get_id() << std::endl;
    return x * x;
}

int main() {
    // 1. 默认模式
    std::future<int> fut_default = std::async(calculate_num, 10);
    std::cout << "当前是默认模式" << std::endl;
    std::cout << "默认模式: " <<fut_default.get() << std::endl;

    // 2. 异步模式
    std::future<int> fut_async = std::async(std::launch::async, calculate_num, 10);
    std::cout << "当前是异步模式" << std::endl;
    std::cout << "异步模式（强制创建线程）结果:  " << fut_async.get() << std::endl;

    // 3. 延迟模式
    std::future<int> fut_deferred = std::async(std::launch::deferred, calculate_num, 10);
    std::cout << "当前是延迟模式, 未调用get()不执行" << std::endl;
    std::cout << "延迟结果: " << fut_deferred.get() << std::endl;

    return 0;
}