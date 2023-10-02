#include "Request.cpp"
class WebServer {
public:
    bool isBusy;
    int timeLeft;
    Request currentRequest;
}