//
// Created by a9214 on 2019/11/3.
//

#include "Timer.h"
#include <thread>
#include <mutex>
#include "Schedule.h"
#include <windows.h>
void onTimer() {
    while(1) {
        for (auto p : schedules) {
            //判断时间，提示..
        }
        Sleep(1000);
    }


}

void startTimer() {
    std::thread timer(onTimer);
    timer.detach();
}