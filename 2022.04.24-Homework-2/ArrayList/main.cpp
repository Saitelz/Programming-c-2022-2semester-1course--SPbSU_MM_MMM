#include <iostream>
#include <ctime>
#include "ArrayListLib.h"

using namespace std;

int main(int argc, char* argv[])
{
    cout << "Source array" << endl;

    srand(time(0));
    ArrayList arr;
    for (int i = 0; i < 10; ++i)
    {
        arr.pushend(rand() % 100);
    }

    cout << arr << endl;

    cout << "Demonstration program" << endl;

    arr.sort();
    cout << arr << endl;

    cout << arr.extract(7) << endl << arr << endl;
    arr.insert(66, 4);
    cout << arr << endl;

    arr.pushbegin(77);
    cout << arr << endl;
    arr.pushend(88);
    cout << arr << endl;

    cout << arr.extractbegin() << endl << arr << endl;
    cout << arr.extractend() << endl << arr << endl;

    arr.sort();
    cout << arr << endl;

    return EXIT_SUCCESS;
}