# super_small_demo

平时会遇到的问题，用一些代码demo验证

1. demo尽量一次只讲一个知识点

# 测试说明

1. 确保CMakeLists.txt 已经添加了对应的 cpp

```cmake
add_library(demo
        demo_async_mission.cpp
        ...
)
```

2. 在`include_all_demo.h` 前向声明函数名

```cpp
// 函数前向声明，防止未声明
// 定义在cpp中定义
// 此处添加新增的函数名
void demo_async_mission();
```

3. 在 `main.cpp` 中调用

```cpp
#include <iostream>

#include "include_all_demo.h"
int main() {
    // input test function
    std::cout << "input test function" << std::endl;
    demo_print_refrence();
    return 0;
}
```

4. 编译
```bash
mdkir build && cd build
cmake .. && cmake --build .
```

5. 运行(确保在 `build` 目录下)
```bash
./super_small_demo
```