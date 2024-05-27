#ifndef SYSINFO_HPP
#define SYSINFO_HPP
#include <string>
using namespace std;

class SystemInfo {
protected:
    string version;
    string author;

public:
    SystemInfo(const string& version, const string& author):
     version(version), author(author) {}
    
    //getters
    string getVersion() const {  return version; }
    string getAuthor() const { return author; }

    //setters
    void setVersion(string version){ this->version = version; }
    void setAuthor(string author){ this->author = author; }
};

#endif