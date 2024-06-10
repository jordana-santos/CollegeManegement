#ifndef SYSINFO_HPP
#define SYSINFO_HPP
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SystemInfo final {
    protected:
    static const float version;
    static const vector<string> authors;

    public:    
    //getters
    static const float getVersion() ;
    static const vector<string> getAuthors() ;

    static const void showInfo();
};

#endif