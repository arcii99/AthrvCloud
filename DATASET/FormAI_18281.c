//FormAI DATASET v1.0 Category: Robot movement control ; Style: happy
// Happy Robot Movement Control Example Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	
	int motion[5];
	int i, j;
	
	srand(time(0)); // seed the random number generator with current time
	
	// initialize the motion array
	for(i=0; i<5; i++) {
		motion[i] = rand() % 5 + 1; // generate random number between 1-5
	}
	
	printf("The dance moves for your robot are:\n");
	
	// display the dance moves for the robot
	for(i=0; i<5; i++) {
		switch(motion[i]) {
			case 1:
				printf("Move the robot's arms up and down.\n");
				break;
			case 2:
				printf("Make the robot jump.\n");
				break;
			case 3:
				printf("Twist the robot's body.\n");
				break;
			case 4:
				printf("Make the robot spin around.\n");
				break;
			case 5:
				printf("Make the robot do a silly dance.\n");
				break;
			default:
				printf("Sorry, there was an error generating the dance moves.\n");
				break;
		}
	}
	
	printf("\nGet ready to dance with your robot! Are you ready? Let's do it!\n");
	
	// make the robot dance with the selected moves
	for(i=0; i<5; i++) {
		switch(motion[i]) {
			case 1:
				printf("Move robot's arms up and down.\n");
				break;
			case 2:
				printf("Make robot jump.\n");
				break;
			case 3:
				printf("Twist robot's body.\n");
				break;
			case 4:
				printf("Make robot spin around.\n");
				break;
			case 5:
				printf("Make robot do a silly dance.\n");
				break;
			default:
				printf("Sorry, there was an error generating the dance moves.\n");
				break;
		}
		
		// wait for a moment before performing the next move
		for(j=0; j<50000000; j++) {
			// wait
		}
	}
	
	printf("\nGreat job! Your robot is an amazing dancer! Let's do it again sometime!\n");
	
	return 0;	
}