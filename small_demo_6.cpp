/*
 * @Descripttion: 打印枚举值，16进制
 * @Author: zhanjiewen
 * @Date: 25-6-12
 */
#include <iostream>
enum MSG_ID {
    DATA = 0x01,
    MSG = 0x02,
    CONFIG_REQUEST = 0x03,
    CONFIG_RESPONSE = 0x04,
    SAVE_CONFIG_REQUEST = 0x05,
    SAVE_CONFIG_RESPONSE = 0x06
};

void demo_print_enum_hex() {
    std::cout << "Hexadecimal value: 0x" << std::hex << MSG_ID::DATA << std::endl;
}