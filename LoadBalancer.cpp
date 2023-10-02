#include <iostream>
using namespace std;
class LoadBalancer {
    int numRequests;
    LoadBalancer() {
        cout << "initialize" << endl;
        this->numRequests = 0;
    }
};