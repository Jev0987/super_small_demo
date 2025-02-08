/*
 * @Descripttion: 使用malloc开辟空间后，对应的指针是否还有效 if(void*)
 * @Author: jev
 * @version: 
 * @Date: 2025-02-08
 * @LastEditors: jev
 * @LastEditTime: 2025-02-08
 */
#include <iostream>

int main(int argc, char * argv[]) {
    
    void* buff = malloc(10);

    free(buff);

    if (buff) {
        std::cout << "free 后 指针仍然不为 nullptr" << std::endl;
        // 这里如果继续进行 free，会出现重复 free的错误
        // free(buff);
    }

    return 0;
}