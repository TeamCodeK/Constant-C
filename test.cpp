#include <iostream>
#include <sstream>
using namespace std;

int main() {
    float c;
    std::stringstream cv;
    cv << "0.1";
    cv >> c;
    cout << c << endl;
    return 0;
}
