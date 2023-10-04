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

        freopen("log.txt", "w", stdout);
        
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

            // if queue is getting full, add a server
            if (this->requestQueue.size() >= this->queueCapacity - 5) {
                cout << "Server " << this->numUniqueServers << " has been added." << endl;
                WebServer ws = WebServer(this->numUniqueServers++);
                this->webServers.push_back(ws);
            }
            else if (this->requestQueue.size() <= this->queueCapacity / 2 + 5 && !this->requestQueue.empty() ){ // if queue is getting empty remove a server
                cout << "Server " << this->webServers.back().serverId << " has been removed." << endl;
                this->webServers.pop_back();
            }

            // check if any servers are available
            for (int i = 0; i < this->webServers.size(); i++) {
                    if (this->webServers.at(i).countDown == 0 && !this->requestQueue.empty()) {
                    // if server is available, assign it a request
                    this->webServers.at(i).currentRequest = this->requestQueue.front();
                    this->webServers.at(i).countDown = this->webServers.at(i).currentRequest.requestTime;
                    this->requestQueue.pop();
                }
                else {
                    // if server is busy, decrement its timeLeft
                    this->webServers.at(i).countDown--;
                    // if server is done, log completion
                    if (this->webServers.at(i).countDown == 0) {
                        cout << "A request from IP " << this->webServers.at(i).currentRequest.ipIn << " has been processed by server " << this->webServers.at(i).serverId << endl;
                        this->totalRequestsProcessed++;
                    }
                }
            }
            // decrement timeLeft
            timeLeft--;
            
            // generate 0-2 new requests randomly
            int numNewRequests = rand() % 3;
            for (int i = 0; i < numNewRequests; i++) {

                if (this->requestQueue.size() == this->queueCapacity) {
                    cout << "A new request has been discarded." << endl;
                    this->numRejections++;
                    continue;

                }
                else {
                    Request r = Request();
                    this->requestQueue.push(r);
                }
            }


        }

        // Display log summary
        cout << "Load Balancer Summary:" << endl;
        cout << "Active servers: " << this->webServers.size() << endl;
        cout << "Requests in queue: " << this->requestQueue.size() << endl;
        cout << "Discarded Requests: " << this->numRejections << endl;
        cout << "Total Processed Requests: " << this->totalRequestsProcessed << endl;
    }
};