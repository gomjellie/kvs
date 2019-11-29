#include <fstream>
#include <map>

using namespace std;

fstream dbStream;

int open() {
    dbStream.open("my.db", ios::in | ios::out | ios::trunc);
    return 0;
}
