#include <string>
#include <map>

using namespace std;

extern map<string, string> kvs;

int put(string key, string value, int nbytes) {
    kvs[key] = value;

    return 0;
}
