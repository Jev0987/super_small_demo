/*
 * @Descripttion:
 * @Author: jev
 * @version:
 * @Date: 2025-11-03
 * @LastEditors: jev
 * @LastEditTime: 2025-11-03
 */
#include <iostream>

class Engine {
public:
    virtual ~Engine() = default;
    virtual void start() = 0;
};

class GasolineEngine : public Engine {
public:
    void start() override { std::cout << "gasoline engine start." << std::endl; }
};

class Car_1 {
public:
    // 构造函数注入
    Car_1(Engine* engine)
        : engine_(engine) {}
    ~Car_1() { delete engine_; }

private:
    Engine* engine_;
};

class Car_2 {
public:
    // setter 方法注入
    void setEngine(Engine* engine) { engine_ = engine; }

    ~Car_2() { delete engine_; }

private:
    Engine* engine_;
};

class EngineInjectable {
public:
    virtual ~EngineInjectable() = default;
    virtual void injectEngine(Engine* engine) = 0;
};

class Car_3 : public EngineInjectable {
public:
    // 接口注入
    void injectEngine(Engine* engine) override { engine = engine_; }

    ~Car_3() { delete engine_; }

private:
    Engine* engine_;
};