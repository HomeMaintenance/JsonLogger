#pragma once
#include <string>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <json/json.h>

using milliseconds = std::chrono::duration<double, std::milli>;

class JsonLogger{
public:
    JsonLogger(std::string fileName);
    ~JsonLogger();
    virtual void add_datapoint(milliseconds time, const Json::Value& input);
    int get_counter() const;

private:
    int counter = 0;
    std::string _fileName;
    Json::Value data{Json::arrayValue};
};
