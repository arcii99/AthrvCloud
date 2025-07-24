//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	int num;
	
	srand(time(0)); // Seed the random number generator with current time

	num = (rand() % 10) + 1; // Generate a random number between 1 and 10
	
	printf("Random number: %d", num); // Output the random number
	
	return 0;
}