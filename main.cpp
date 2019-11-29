#include "./kvs.hpp"
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
    extern fstream db_stream;
    open();
    map<string, string> m;
    m["key1"] = "val1";
    m["key3"] = "val3";

    for (auto const& item : m) {
        db_stream << item.first << " " << item.second << "\n";
    }
    close();
}
