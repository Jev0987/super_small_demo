/* 
 * @Descripttion: 成员变量的构造和析构
 * @Author: Jev
 * @Date: 25-6-15
 */

#include <iostream>

class Points {
public:
    Points() {
        std::cout << "Points constructor" << std::endl;
    }

    ~Points() {
        std::cout << "Points destructor" << std::endl;
    }
};

class Triangle {
public:
    Triangle() {
        std::cout << "Triangle constructor" << std::endl;
    }
    ~Triangle() {
        std::cout << "Triangle destructor" << std::endl;
    }

    void print() {
        std::cout << "======== Triangle print ========" << std::endl;
    }
private:
    Points points;
};

void demo_member_class() {
    Triangle triangle;
    triangle.print();
}
