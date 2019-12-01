#include <string>
#include <fstream>
#include <map>
using namespace std;

fstream db_stream;
map<string, string> kvs;


int put(string key, string value, int nbytes);
string get(string key, int nbytes);
int open();
void close();

