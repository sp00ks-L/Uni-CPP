#include <iostream>

#include "Circle.h"

using namespace std;

int main() {
    Circle A(3.0, 2.0, 1.0);
    Circle B(4.0, 5.0, 6.0);
    cout << A.getRadius() << endl;
    return 0;
}
