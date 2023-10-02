#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Request.cpp"
using namespace std;
class LoadBalancer {
    queue<Request> requestQueue;
    int timeTracker;
    int numServers;

    LoadBalancer() {
        cout << "Initializing Load Balancer..." << endl;
        
        this->requestQueue = queue<Request>();
        this->timeTracker = 0;
        this->numServers = 0;
        
    }
};