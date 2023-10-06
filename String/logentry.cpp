//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        Fall 2022
// Author:      
//
// Description: Class implementation for a log entry.
//
// 

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector> 

#include "string.hpp" 
#include "logentry.hpp"

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
LogEntry::LogEntry(String s) {
    std::cout << "line: " << s << std::endl;
    std::vector<String> vec = s.split(' ');
    if (vec.size() == 10){
        host = vec[0];
        std::vector<String> dtg = vec[3].split(':');
        date = Date(dtg[0]);
        time = Time(dtg[1], dtg[2], dtg[3]);
        request = vec[5] + " " + vec[6] + " " + vec[7];
        status = vec[8];
        if (vec[9] == '-'){
            number_of_bytes = 0;
        } else {
            number_of_bytes = StringToInt(vec[9]);
        }
    } else {
        host = "";
        request = "";
        status = "";
        number_of_bytes = 0;
    }
}

Date::Date(String d){
    std::vector<String> date = d.split('/');
    day = date[0];
    month = date[1];
    year = StringToInt(date[2]);
    //std::cout << year << std::endl;


}

Time::Time(String h, String m, String s){
hour = StringToInt(h);
//std::cout << hour << std::endl;
minute = StringToInt(m);
second = StringToInt(s);

}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;
    char line[512];
    while (!in.eof()){
        in.getline(line, 512);
        if (in.eof()) {
            break;
        }
        //std::cout << "parse" << std::endl;
        LogEntry log(line);
        //std::cout  << "parse2" << std::endl;
        result.push_back(log);
    }
    return result;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
std::ostream& operator<<(std::ostream& out, const LogEntry& log){
    out << log.host << " - - ["
    << log.date.getDay() << "/" << log.date.getMonth() << "/" << log.date.getYear() << ":"
    << log.time.getHour() << ":" << log.time.getMinute() << ":" << log.time.getSecond() << "]"
    << log.request << " "
    << log.status << " "
    << log.number_of_bytes;
    return out;



}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void output_all(std::ostream& out, const std::vector<LogEntry>& logs) {
    for (unsigned i = 0; i < logs.size(); ++i){
        out << logs[i] << std::endl;
    }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void by_host(std::ostream& out, const std::vector<LogEntry>& host) {
    for (unsigned i = 0; i < host.size(); ++i){
        out << host[i].getHost() << std::endl;
    }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
int byte_count(const std::vector<LogEntry>& log) {
    int count = 0;
    for (unsigned i = 0; i < log.size(); ++i){
        count += log[i].getBytes();
    }
    return count;
}

int StringToInt(String given) {
    int stringint = 0, i = 0;
    while (i < given.length()){
        stringint = stringint * 10 + (given[i] - '0');
        ++i;
    }
    return stringint;
}

// void Date::printDate(std::ostream& out) const{
//     out << day << " " << month << " " << year;
// }

// void Time::printTime(std::ostream& out) const{
//     out << hour<< " " << minute<< " " << second;
// }

// void LogEntry::printLogEntry(std::ostream& out) const{
//     out << host << " ";
//     date.printDate(out);
//     out << " ";
//     time.printTime(out);
//     out << " " << request << " " << status << " " << number_of_bytes;
// }

