//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Declare function to generate random conspiracies
void generate_conspiracy();

int main() {
	srand(time(0));
	// Call the function five times to generate five different conspiracy theories
	for(int i=0;i<5;i++){
		generate_conspiracy();
		printf("\n\n");
	}	
	return 0;
}

// Define the generate_conspiracy function
void generate_conspiracy(){

	// Array of possible subjects for a conspiracy theory
	char subjects[][50] = {"The government","The Illuminati","The lizard people",
				"The Freemasons","The New World Order","The Reptoids"};

	// Array of possible actions for a conspiracy theory
	char actions[][50] = {"are controlling","are manipulating","are brainwashing",
				"are hiding information from","are experimenting on",
				"are planning to eliminate"};

	// Array of possible targets for a conspiracy theory
	char targets[][50] = {"the general public","world leaders","the media",
				"the education system","the banking system",
				"the healthcare industry"};

	// Select a random subject, action, and target
	int random_subject = rand() % 6;
	int random_action = rand() % 6;
	int random_target = rand() % 6;

	// Print the generated conspiracy
	printf("%s %s %s", subjects[random_subject], actions[random_action], targets[random_target]);
}