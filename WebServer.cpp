#include "Request.cpp"

class WebServer {
public:
    bool isBusy;
    Request currentRequest;

    WebServer() {
        this->isBusy = false;
        this->currentRequest = Request();
    }
};