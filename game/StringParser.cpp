#include "StringParser.h"
#include <string>
using namespace std;

double StringParser::valFromStr(const string& s, const string& key) {
    int pos = 0;
    string res = "0.0";
    if ((pos = s.find(key)) != string::npos) {
        if (s.find(',', pos) != string::npos) {
            res = s.substr(pos + key.length(), s.find(',', pos) - pos - key.length()); //get substring between key and next ','
        } 
        else {
            res = s.substr(pos + key.length(), s.length() - pos - key.length()); //get substring between key and EOL
        }
    }
    return stod(res);
}
