#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Request.cpp"
#include "WebServer.cpp"
using namespace std;
class LoadBalancer {
    queue<Request> requestQueue;
    vector<WebServer> webServers;
    int timeTracker;
    int numServers;

    LoadBalancer() {
        cout << "Initializing Load Balancer..." << endl;

        this->requestQueue = queue<Request>();
        this->webServers = vector<WebServer>();
        this->timeTracker = 0;
        this->numServers = 0;
        
    }
};