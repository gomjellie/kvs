#include "./kvs.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    extern fstream db_stream;
    extern map<string, string> kvs;
    open();
    cout << get("key4", 0);
    put("key4", "val4", 0);
    
    close();
}
