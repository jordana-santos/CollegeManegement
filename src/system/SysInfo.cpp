#include "../../include/system/SysInfo.hpp"

const float SystemInfo::version = 2.0;
const vector<string> SystemInfo::authors = {"Celio Benhami", "Emily Tomadon", "Gabriel Gato", "Jordana Santos", "Rafael Pereira"};
//getters
const float SystemInfo::getVersion() {  return version; }
const vector<string> SystemInfo::getAuthors() { return authors; }

const void SystemInfo::showInfo() {
    cout<<endl<<" -- College Management System : Versão "<<getVersion()<<" -- "<<endl<<" Autores:"<<endl;
    for (const string& author : authors) {
        cout << " - "<< author << endl;
    }
    cout<<endl;
};