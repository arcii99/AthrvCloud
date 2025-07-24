//FormAI DATASET v1.0 Category: Educational ; Style: distributed
#include <stdio.h>

// Declaration of global variables
int a = 5, b = 10, diff = 0;

// Declaration of functions
void calcDiff(int x, int y);
void sendData();

int main()
{
    // Calling the function calcDiff to calculate the difference between two numbers
    calcDiff(a, b);

    // Calling the function sendData to send the calculated difference to another node
    sendData();

    return 0;
}

// Function to calculate the difference between two numbers
void calcDiff(int x, int y)
{
    diff = x - y;
}

// Function to send the calculated difference to another node
void sendData()
{
    printf("Sending data to another node: %d", diff);
}