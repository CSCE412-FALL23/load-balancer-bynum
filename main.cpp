
#include "LoadBalancer.cpp"

#include <iostream>
#include <string>
#include <vector>
#include <queue>

int main () {

// Process User input
int numSevers;
cout << "Enter the number of servers: ";
cin >> numSevers;

int timeLeft;
cout << "Enter the total run time: ";
cin >> timeLeft;


// initialize LoadBalancer
LoadBalancer lb = LoadBalancer(numSevers, timeLeft);


}