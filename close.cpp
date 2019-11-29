#include <fstream>

using namespace std;

extern fstream db_stream;
void close() {
    db_stream.close();
}
