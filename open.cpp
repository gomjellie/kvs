#include <fstream>
#include <map>

using namespace std;

fstream db_stream;

int open() {
    db_stream.open("my.db", ios::in | ios::out | ios::trunc);
    return 0;
}
