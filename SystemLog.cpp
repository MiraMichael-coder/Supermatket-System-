#include "SystemLog.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;


 string SystemLog::getTimestamp() {
          // Get the current time
    time_t now = time(nullptr);

    // Convert to local time
    tm localTime = *localtime(&now);

    // Create a formatted timestamp
    ostringstream timestamp;
    timestamp << put_time(&localTime, "%d/%m/%Y %H:%M:%S");

    return timestamp.str();
    } 
void SystemLog::addLog(const string& logEntry) {
    string timestamp = getTimestamp();
    logs.push("[" + timestamp + "] " + logEntry);
}
void SystemLog::displayLogs()  const{
    stack<string> tempLogs(logs); 
    if (logs.empty()) {
        cout << "No system logs available.\n";
        return;
    }

    cout << "System Logs:\n";

    // Create a copy of logs
  /*  while(!logs.empty())
    {
        tempLogs.push(logs.top());
        logs.pop();
    }
*/
    // Pop from the temporary stack to display logs in reverse order (latest first)
    while (!tempLogs.empty()) 
        { 
        cout << tempLogs.top() << "\n";
        tempLogs.pop();
    }
}
