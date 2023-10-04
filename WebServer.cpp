#include "Request.cpp"

class WebServer {
public:
    int serverId;
    int countDown;
    Request currentRequest;

    WebServer(int serverId) {
        this->serverId = serverId;
        this->countDown = 0;
        
    }
};