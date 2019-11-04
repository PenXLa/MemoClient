//
// Created by a9214 on 2019/10/31.
//

#include "Schedule.h"
#include <cstring>
std::list<Schedule*> schedules;

Schedule::Schedule(std::string name) {
    sid = getTimeStamp();
    strcpy(this->name, name.c_str());
};