#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;



/**
 * @brief The class for representing a request object. It has three members: ipIn, ipOut, and requestTime.
 * 
 * 
 */
class Request {
public:
    string ipIn; /**< Ip address sending request*/
    string ipOut; /**< Ip address receiving request*/
    int requestTime; /**< The amount of clock cycles needed to process the request*/

    /**
     * @brief Parameterized constructor for Request class
     * 
     * @param ipIn The ip address sending the request
     * @param ipOut The ip address receiving the request
     * @param time The amount of clock cycles needed to process the request
     */
    Request(string ipIn, string ipOut, int time) {
        this->ipIn = ipIn;

        this->ipOut = ipOut;

        this->requestTime = time;
    }

    /**
     * @brief Default constructor for Request class
     * 
     */
    Request() {
        this->ipIn = this->GenerateRandomIp();

        this->ipOut = this->GenerateRandomIp();

        this->requestTime = 3 + rand() % 98;
    
    }

    /**
     * @brief Generates a random ip address
     * 
     * @return string The random ip address
     */
    string GenerateRandomIp() {
        int octet1 = rand() % 255;
        int octet2 = rand() % 255;
        int octet3 = rand() % 255;
        int octet4 = rand() % 255;

        return to_string(octet1) + "." + to_string(octet2) + "." + to_string(octet3) + "." + to_string(octet4);
    }
};
