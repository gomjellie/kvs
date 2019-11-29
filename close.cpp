#include <fstream>

using namespace std;

extern fstream dbStream;
void close() {
    dbStream.close();
}
