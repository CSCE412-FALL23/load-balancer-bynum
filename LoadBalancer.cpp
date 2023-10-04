#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h> // integer floor function

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
    int numUniqueServers;
    int totalRequestsProcessed;

    LoadBalancer(int numServers, int timeLeft) {
        cout << "Initializing Load Balancer..." << endl;

        this->requestQueue = queue<Request>();
        this->webServers = vector<WebServer>();
        this->timeLeft = timeLeft;
        this->numServers = numServers;
        this->queueCapacity = numServers * 5;
        this->numRejections = 0;
        this->numUniqueServers = 0;
        this->totalRequestsProcessed = 0;
        
    }

    void RunLoadBalancer() {
        cout << "Running Load Balancer..." << endl;

        // initialize web servers
        for (int i = 0; i < this->numServers; i++) {
            cout << "Server " << this->numUniqueServers << " has been added." << endl;
            WebServer ws = WebServer(this->numUniqueServers++);
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
                        cout << "A request from IP " << this->webServers[i].currentRequest.ipIn << " has been processed by server " << this->webServers[i].serverId << endl;
                        this->totalRequestsProcessed++;
                    }
                }
            }
            // decrement timeLeft
            timeLeft--;

            // if queue is more than 70% full, add 20% more servers
            if (this->requestQueue.size() >= floor(this->queueCapacity * 0.7)) {
                int numNewServers = floor(this->numServers * 0.2);
                for (int i = 0; i < numNewServers; i++) {
                    cout << "Server " << this->numUniqueServers << " has been added." << endl;
                    WebServer ws = WebServer(this->numUniqueServers++);
                    this->webServers.push_back(ws);
                }
                this->numServers += numNewServers;
            }
            // generate 0-2 new requests randomly
            int numNewRequests = rand() % 3;
            for (int i = 0; i < numNewRequests; i++) {

                if (this->requestQueue.size() == this->queueCapacity) {
                    cout << "A new request has been discarded." << endl;
                    this->numRejections++;
                    continue;

                }
                Request r = Request();
                this->requestQueue.push(r);
            }


        }

        // Display log summary
        cout << "Load Balancer Summary:" << endl;
        cout << "Active servers: " << this->numServers << endl;
        cout << "Requests in queue: " << this->requestQueue.size() << endl;
        cout << "Discarded Requests: " << this->numRejections << endl;
        cout << "Total Processed Requests: " << this->totalRequestsProcessed << endl;
    }
};