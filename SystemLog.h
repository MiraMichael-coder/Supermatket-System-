#ifndef SYSTEMLOG_H_INCLUDED
#define SYSTEMLOG_H_INCLUDED
#include <iostream>
#include <stack>
using namespace std;
class SystemLog
{
    stack<string>logs;
    string getTimestamp() ;
public:
  
    void addLog(const string& logEntry);

    // Displays all logs
    void displayLogs() const;
    
};
#endif // SYSTEMLOG_H_INCLUDED
