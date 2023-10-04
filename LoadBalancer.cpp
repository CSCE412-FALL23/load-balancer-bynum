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
    int queueCapacity;
    int numRejections;

    LoadBalancer(int numServers, int timeLeft) {
        cout << "Initializing Load Balancer..." << endl;

        this->requestQueue = queue<Request>();
        this->webServers = vector<WebServer>();
        this->timeLeft = timeLeft;
        this->numServers = numServers;
        this->queueCapacity = numServers * 5;
        this->numRejections = 0;
        
    }

    void RunLoadBalancer() {
        cout << "Running Load Balancer..." << endl;

        // initialize web servers
        for (int i = 0; i < this->numServers; i++) {
            WebServer ws = WebServer();
            this->webServers.push_back(ws);
        }

        // create full queue of requests
        for (int i = 0; i < this->queueCapacity; i++) {
            Request r = Request();
            this->requestQueue.push(r);
        }

        // main loop
        while (timeLeft > 0) {
            // check if any servers are available
            for (int i = 0; i < this->numServers; i++) {
                if (!this->webServers[i].isBusy) {
                    // if server is available, assign it a request
                    this->webServers[i].currentRequest = this->requestQueue.front();
                    this->webServers[i].isBusy = true;
                    this->requestQueue.pop();
                }
                else {
                    // if server is busy, decrement its timeLeft
                    this->webServers[i].currentRequest.requestTime--;
                    // if server is done, change the isBusy flag
                    if (this->webServers[i].currentRequest.requestTime == 0) {
                        this->webServers[i].isBusy = false;
                    }
                }
            }
            // decrement timeLeft
            timeLeft--;
            // generate 0-2 new requests randomly
            int numNewRequests = rand() % 3;
            for (int i = 0; i < numNewRequests; i++) {

                if (this->requestQueue.size() == this->queueCapacity) {
                    this->numRejections++;
                    continue;
                }
                Request r = Request();
                this->requestQueue.push(r);
            }


        }
    }
};