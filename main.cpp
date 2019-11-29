#include "./kvs.hpp"
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
    extern fstream dbStream;
    open();
    map<string, string> m;
    m["key1"] = "val1";
    m["key2"] = "val2";

    for (auto const& item : m) {
        dbStream << item.first << " " << item.second << "\n";
    }
    close();
}
