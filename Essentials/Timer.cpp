//
// Created by a9214 on 2019/11/3.
//

#include "Timer.h"
#include <thread>
#include <mutex>
#include "Schedule.h"
#include <windows.h>
#include <iostream>
#include "ClientDataBase.h"
void onTimer() {
    while(1) {
        time_t now = time(0);
        for (auto p : schedules) {
            if (p->type == ALARM_CLOCK) {
                //闹钟计划
                if (!p->alerted && p->endTime <= now) {
                    std::cout << p->name << "alerted!\n";//闹钟提醒
                    p->alerted = true;
                    DataBase::editSchedule(p->sid, *p);
                    if (loggedin) DataBase::sync_edit(p->sid, *p);
                }
            } else {
                //长期计划
                //根据getUrgency的返回值来判断
            }
        }
        Sleep(1000);
    }


}

void startTimer() {
    std::thread timer(onTimer);
    timer.detach();
}