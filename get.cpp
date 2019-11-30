#include <fstream>
#include <string>
#include <map>

using namespace std;

string get(string key, int nbytes) {
    extern map<string, string> kvs;
    return kvs[key];    
}
