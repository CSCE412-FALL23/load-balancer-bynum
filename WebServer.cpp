#include "Request.cpp"

class WebServer {
public:
    int serverId;
    bool isBusy;
    Request currentRequest;

    WebServer(int serverId) {
        this->serverId = serverId;
        this->isBusy = false;
        
    }
};