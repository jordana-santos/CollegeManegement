#ifndef SYSINFO_HPP
#define SYSINFO_HPP
#include <string>
using namespace std;

class SystemInfo {
private:
    string version;
    string author;

public:
    SystemInfo(const string& version, const string& author):
     version(version), author(author) {}
    
    //get
    string getVersion() const { 
        return version; 
    }

    string getAuthor() const { 
        return author; 
    }
};

#endif