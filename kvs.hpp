#include <string>
#include <fstream>
using namespace std;

int put(string& key, string& value, int nbytes);
string get(string& key, int& nbytes);
int open();
void close();

