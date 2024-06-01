#ifndef SYSINFO_HPP
#define SYSINFO_HPP
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SystemInfo {
protected:
    float version = 2.0;
    vector<string> authors = {"Celio Benhami", "Emily Tomadon", "Gabriel Gato", "Jordana Santos", "Rafael Pereira"};

public:
    SystemInfo(){};
    SystemInfo(const float& version, const vector<string>& authors):
    version(version), authors(authors){};
    
    //getters
    float getVersion() const {  return version; }
    vector<string> getAuthors() const { return authors; }

    //setters
    void setVersion(float version){ this->version = version; }
    void setAuthor(vector<string> authors){ this->authors = authors; }

    void showAuthors() const{
        for (const string& author : authors) {
            cout << author << endl;
        }
    };
};

#endif