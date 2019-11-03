#ifndef MEMOCLIENT_SCHEDULE_H
#define MEMOCLIENT_SCHEDULE_H

#include <ctime>
enum ScheduleType {
    ALARM_CLOCK, LONG_TERM_SCHEDULE //前者是闹钟一样的定时提醒，后者是长期计划
};
class Schedule {
public:
    time_t endTime;//预计的截止时间
    time_t costTime;//预计的耗费时间
    char importance;//重要程度(0~100)
    char name[256];//事项名称,返回-1表示已超过截止时间
    char getUrgency();//获取紧急程度(0~100)
    ScheduleType type;//是闹钟
    int sid;//事项的id
};


#endif //MEMOCLIENT_SCHEDULE_H
