//FormAI DATASET v1.0 Category: Text processing ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char input[100];
	printf("Welcome to the Haiku generator!\n");
	printf("Enter a line of text: ");
	fgets(input, 100, stdin); //gets user input
	input[strcspn(input, "\n")] = 0; //removes newline from input

	//checks if input is long enough for a Haiku
	if (strlen(input) < 5) {
		printf("That's too short for a Haiku, sorry.");
		exit(0);
	}

	char haiku1[6], haiku2[8], haiku3[6]; //arrays to store each line of haiku

	//loop to randomly select each word of the haiku
	for (int i = 0; i < 5; i++) {
		int rand_num = rand() % strlen(input);
		haiku1[i] = input[rand_num];
	}
	haiku1[5] = '\0'; //adds null terminator

	for (int i = 0; i < 8; i++) {
		int rand_num = rand() % strlen(input);
		haiku2[i] = input[rand_num];
	}
	haiku2[8] = '\0';

	for (int i = 0; i < 5; i++) {
		int rand_num = rand() % strlen(input);
		haiku3[i] = input[rand_num];
	}
	haiku3[5] = '\0';

	//prints out the final haiku
	printf("\n");
	printf("%s, oh how sweet\n", haiku1);
	printf("%s is the very best treat\n", haiku2);
	printf("%s is neat\n", haiku3);

	return 0;
}