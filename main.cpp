
#include "LoadBalancer.cpp"

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/**
 * @brief The main function. It takes in user input for the number of servers and the total run time, then creates a LoadBalancer object and runs it.
 * 
 * @return int 
 */
int main () {

// Process User input
int numSevers;
cout << "Enter the number of servers: ";
cin >> numSevers;

int timeLeft;
cout << "Enter the total run time: ";
cin >> timeLeft;

// RNG seed
srand(time(NULL));

// initialize LoadBalancer
LoadBalancer lb = LoadBalancer(numSevers, timeLeft);

// Run LoadBalancer
lb.RunLoadBalancer();

}