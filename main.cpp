
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

// RNG seed
srand(time(NULL));

// initialize LoadBalancer
LoadBalancer lb = LoadBalancer(numSevers, timeLeft);

// Run LoadBalancer
lb.RunLoadBalancer();

}