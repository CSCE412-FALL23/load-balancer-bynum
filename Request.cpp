#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
class Request {
public:
    string ipIn;
    string ipOut;
    int requestTime;

    Request(string ipIn, string ipOut, int time) {
        this->ipIn = ipIn;

        this->ipOut = ipOut;
        
        this->requestTime = time;
    }

    Request() {
        this->ipIn = this->GenerateRandomIp();

        this->ipOut = this->GenerateRandomIp();

        this->requestTime = 3 + rand() % 98;
    }

    string GenerateRandomIp() {
        srand(time(NULL));
        int octet1 = rand() % 255;
        int octet2 = rand() % 255;
        int octet3 = rand() % 255;
        int octet4 = rand() % 255;

        return to_string(octet1) + "." + to_string(octet2) + "." + to_string(octet3) + "." + to_string(octet4);
    }
};
