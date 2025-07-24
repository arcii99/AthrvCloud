//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void convertToMorse(char message[MAX_LENGTH]);

int main() {
	char message[MAX_LENGTH];

	printf("Welcome to the Cheerful Text to Morse code converter!\n");
	printf("Enter a message to convert to Morse code: ");
	fgets(message, MAX_LENGTH, stdin);

	convertToMorse(message);

	printf("\nThank you for using our cheerful converter! Have a great day!\n");
	return 0;
}

void convertToMorse(char message[MAX_LENGTH]) {
	int i, j, length, count = 0;
	char letter;
	char morseCode[36][7] = { {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."}, {"-----"}, {".----"}, {"..---"}, {"...--"}, {"....-"}, {"....."}, {"-...."}, {"--..."}, {"---.."}, {"----."} };

	length = strlen(message);

	printf("\nMorse code: ");

	for (i = 0; i < length; i++) {
		letter = toupper(message[i]); //converts letter to uppercase

		if (letter >= 'A' && letter <= 'Z') {
			j = letter - 'A'; //getting the index of the letter in morseCode array
			printf("%s ", morseCode[j]);

			count++;
			if (count % 5 == 0) {
				printf("  "); //spaces between words
			}
		}
		else if (letter == ' ') {
			count = 0; //reset the word counter
			printf("/ "); //punctuation mark for space
		}
	}

	printf("\n");
}