#include <fstream>
#include <map>
#include <iostream>

using namespace std;

fstream db_stream;
map<string, string> kvs;
int open() {
    db_stream.open("my.db", ios::in | ios::out);
    while (!db_stream.eof()) {
        string k, v;
        db_stream >> k >> v;
        kvs[k] = v;
    }
    db_stream.clear();
    return 0;
}
