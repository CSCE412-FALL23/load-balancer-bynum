#include <iostream>
#include <string>
#include <vector>
#include <queue>

#include "WebServer.cpp"
using namespace std;
class LoadBalancer {
    public:
    queue<Request> requestQueue;
    vector<WebServer> webServers;
    int timeLeft;
    int numServers;

    LoadBalancer(int numServers, int timeLeft) {
        cout << "Initializing Load Balancer..." << endl;

        this->requestQueue = queue<Request>();
        this->webServers = vector<WebServer>();
        this->timeLeft = timeLeft;
        this->numServers = numServers;
        
    }

    void RunLoadBalancer() {
        cout << "Running Load Balancer..." << endl;

    }
};