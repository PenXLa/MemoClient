#include <iostream>
#include "JSONLib/json.hpp"
#include "Net/ClientNetUtils.h"
#include "Utils/Terminal.h"
#include "Essentials/Timer.h"
#include "Essentials/ClientDataBase.h"
using nlohmann::json, std::cout;
int main() {
    if (!initSocket()) cout << "Socket初始化失败，网络功能将无法使用。";
    DataBase::loadSchedules();
    startTimer();
    tui();
    return 0;
}