#include <iostream>
#include "JSONLib/json.hpp"
#include "Net/ClientNetUtils.h"
using nlohmann::json, std::cout;
int main() {
    if (!initSocket()) std::cout << "Socket 初始化失败\n";
    json j;
    j["name"] = "test";
    j["txt"] = "hw!";
    cout << request(j);
    return 0;
}