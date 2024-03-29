#include "kvs.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cassert>

using namespace std;

int main(int argc, char** argv) {
    /**
     * this program is supposed to get 3 file_name parameter
     * example) ./main put.txt get.txt result_dll.txt
     * 
     * and this will write result of query at result.txt
     */
    assert(argc == 4);
    open();
    
    fstream put_file_stream(argv[1]);
    fstream get_file_stream(argv[2]);
    fstream result_file_stream(argv[3], ios::out | ios::trunc);
    while (!put_file_stream.eof()) {
        string key, val;
        put_file_stream >> key >> val;
        put(key, val, 0);
    }

    while(!get_file_stream.eof()) {
        string query_key, res;
        get_file_stream >> query_key;
        res = get(query_key, 0);
        result_file_stream << res << "\n";
    }
    close();
}
