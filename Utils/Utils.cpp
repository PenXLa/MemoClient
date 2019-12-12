//
// Created by a9214 on 2019/11/3.
//

#include "Utils.h"


nlohmann::json schedule2json(const Schedule &sch) {
    nlohmann::json json;
    json["endtime"] = sch.endTime;
    json["costtime"] = sch.costTime;
    json["alerted"] = sch.alerted;
    json["importance"] = sch.importance;
    json["sid"] = sch.sid;
    json["name"] = sch.name;
    json["lastedit"] = sch.lastEdit;
    return json;
}

Schedule* json2Schedule(const nlohmann::json json) {
    Schedule* sch = new Schedule(json["name"].get<std::string>());
    sch->sid = json["sid"].get<int>();
    sch->importance = json["importance"].get<int>();
    sch->alerted = json["alerted"].get<bool>();
    sch->costTime = json["costtime"].get<time_t>();
    sch->endTime = json["endtime"].get<time_t>();
    sch->lastEdit = json["lastedit"].get<time_t>();
    return sch;
}