#include <string>
#include <map>

using namespace std;

int put(string key, string value, int nbytes) {
    extern map<string, string> kvs;
    kvs[key] = value;

    return 0;
}
