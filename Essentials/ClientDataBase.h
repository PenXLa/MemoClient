#ifndef MEMOCLIENT_CLIENTDATABASE_H
#define MEMOCLIENT_CLIENTDATABASE_H


#include "Schedule.h"

void addSchedule(const Schedule &schedule);
void removeSchedule(int sid);
void editSchedule(int sid, const Schedule &schedule);
Schedule findSchedule(int uid, int sid);
void traverseSchedule(bool func(const Schedule& schedule));
void clearSchedule();

#endif //MEMOCLIENT_CLIENTDATABASE_H