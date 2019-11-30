#include <fstream>
#include <map>
using namespace std;

void close() {
    extern fstream db_stream;
    extern map<string, string> kvs;

    db_stream.close();
    db_stream.open("my.db", ios::out | ios::trunc);
    for (auto const& item : kvs) {
        if (item.first == "") continue;
        db_stream << item.first << " " << item.second << "\n";
    }
    db_stream.close();
    kvs.clear();
}
