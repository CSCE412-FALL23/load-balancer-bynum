#include "Request.cpp"

/**
 * @brief The class for representing a web server object. It has three members: serverId, countDown, and currentRequest.
 * 
 * 
 */
class WebServer {
public:
    int serverId; /**< The unique id number of the server*/
    int countDown; /**< The amount of clock cycles left to process the current request*/
    Request currentRequest; /**< The current request object being processed by the server*/

    /**
     * @brief Parameterized constructor for WebServer class
     * 
     * @param serverId The unique id number of the server
     */
    WebServer(int serverId) {
        this->serverId = serverId;
        this->countDown = 0;
        
    }
};