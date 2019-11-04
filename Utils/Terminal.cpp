#include "Terminal.h"
#include <iostream>
#include <string>
#include "../Essentials/Schedule.h"
#include "../Essentials/ClientDataBase.h"
#include "../JSONLib/json.hpp"
using namespace std;
void tui() {
    string cmd;
    while(1) {
        cin >> cmd;
        if (cmd == "addschedule") {
            string name; cin >> name;
            schedules.push_back(new Schedule(name));//内存中创建新事项
            //DataBase::addSchedule(*schedules.back());//放到文件中
            //*****服务器同步*****

            //*****服务器同步*****
        } else if (cmd == "removeschedule") {
            long long sid; cin >> sid;
            for (auto p=schedules.begin(); p!=schedules.end(); ++p) {
                if ((*p)->sid == sid) {
                    //DataBase::removeSchedule(sid);//数据库清除
                    delete(*p);//内存释放
                    schedules.erase(p);//链表中除名
                    //........do more:还应该和服务器同步
                    break;
                }
            }
        } else if (cmd == "list") {
            for (auto p : schedules) {
                cout << p->name << "\nImportance:" << p->importance << "\nEndTime:" << p->endTime << "\ncostTime:" << p->costTime << "\nsid:" << p->sid << "\n\n";
            }
        } else if (cmd == "setdate") {
            tm t; long long sid;
            cin >> sid >> t.tm_year >> t.tm_mon >> t.tm_mday >> t.tm_hour >> t.tm_min >> t.tm_sec;
            t.tm_year -= 1900;
            time_t tt = mktime(&t);
            for (auto p:schedules) {
                if(p->sid == sid){
                    p->endTime = tt;
                    //DataBase::editSchedule(sid, *p);//更新数据库
                    //........do more:还应该和服务器同步
                    break;
                }
            }
        }
    }
}