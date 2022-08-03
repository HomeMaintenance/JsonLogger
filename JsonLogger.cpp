#include "JsonLogger.h"
#include <fstream>
#include <algorithm>

JsonLogger::JsonLogger(std::string fileName):_fileName(fileName){
    std::replace( _fileName.begin(), _fileName.end(), '.', '_');
    _fileName += ".json";
}

JsonLogger::~JsonLogger(){
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "   ";

    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    std::ofstream outputFileStream(_fileName);
    writer -> write(data, &outputFileStream);
};

void JsonLogger::add_datapoint(milliseconds time, const Json::Value& input){
    Json::Value element{input};
    element["time"] = time.count();
    data[counter] = element;
    counter++;
}

int JsonLogger::get_counter() const { return counter; }
