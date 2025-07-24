//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
	printf("Looking for the missing portion of CPU usage...Please wait...\n\n");
	
	srand(time(NULL)); // Initialize random seed
	
	bool found = false;
	int i = 1; // Loop counter
	int cpuUsage = 0;
	
	while(!found) {
		int randNum = rand() % 100;
		cpuUsage += randNum;
		
		if(i % 10 == 0) { // Check CPU usage every 10 iterations
			if(cpuUsage == 100) {
				printf("CPU usage is a perfect 100%%! The missing portion has been found.\n\n");
				found = true;
			} else {
				printf("CPU usage is only %d%%. The search continues...\n", cpuUsage);
				cpuUsage = 0; // Reset counter
			}
		}
		
		// Surreal sleep function
		int randSleep = rand() % 5;
		if(randSleep == 3) {
			printf("The program took a nap for %d seconds...\n\n", rand() % 10);
			sleep(rand() % 10);
		}
		
		i++; // Increment loop counter
	}
	
	return 0;
}