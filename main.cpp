#include <iostream>
#include "stringData.h"
using namespace std;


int linear_search(vector<string> container, string element)
{
    for (int i = 0; i < container.size(); i++) {
        if (container[i] == element) {
            return i;
        }
    }
    return -1;
}

int binary_search(vector<string> container, string element)
{
    int min = 0;
    int max = container.size() - 1;
    int mid;
    while (min <= max) {
        mid = int((float)(min + max) / 2);
        if (container[mid] == element) {
            return mid;
        }
        else if (container[mid] > element) {
            max = mid - 1;
        }
        else {
            min = mid + 1;
        }
    }
    return -1;
}


int main()
{
    vector<string> data = getStringData();
    vector<string> tests = {"not_here","mzzzz","aaaaa"};
    for (string test : tests)
    {
        cout << "Index linear search found of \"" << test << "\": ";
        auto time_start = chrono::system_clock::now();
        cout << linear_search(data, test) << endl;
        auto time_end = chrono::system_clock::now();
        auto time_taken = chrono::duration_cast<chrono::nanoseconds>(time_end - time_start);
        cout << "time spent for linear search to find \"" << test << "\" : " << time_taken.count() * 1e-9 << endl;

        cout << "Index binary search found of \"" << test << "\": ";
        time_start = chrono::system_clock::now();
        cout << binary_search(data, test) << endl;
        time_end = chrono::system_clock::now();
        time_taken = chrono::duration_cast<chrono::nanoseconds>(time_end - time_start);
        cout << "time spent for binary search to find \"" << test << "\" : " << time_taken.count() * 1e-9 << endl;

        cout << "\n";
    }
    return 0;
}
