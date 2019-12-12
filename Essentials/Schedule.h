#ifndef MEMOCLIENT_SCHEDULE_H
#define MEMOCLIENT_SCHEDULE_H

#include <ctime>
#include <list>
#include <string>
enum ScheduleType {
    ALARM_CLOCK, LONG_TERM_SCHEDULE //前者是闹钟一样的定时提醒，后者是长期计划
};
class Schedule {
public:
    time_t endTime=0;//预计的截止时间
    time_t costTime=0;//预计的耗费时间
    time_t lastEdit=0;//上次编辑的时间，用于判断哪个更新
    short importance=0;//重要程度(0~100)
    char name[256];//事项名称,返回-1表示已超过截止时间
    char getUrgency();//获取紧急程度(0~100)
    ScheduleType type=ALARM_CLOCK;
    unsigned int sid=0;//事项的id
    bool alerted=false;//是否已经提醒过，当作闹钟事项的过期标志

    Schedule();
    Schedule(std::string name);
};

extern std::list<Schedule*> schedules;



#endif //MEMOCLIENT_SCHEDULE_H
