//FormAI DATASET v1.0 Category: Text processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

void processString(char* inputString, char* outputString, char* delimiter) {
	char* token;
	int tokenSize = 0;

	// Get the first token
	token = strtok(inputString, delimiter);

	// Keep getting tokens until there are no more
	while (token != NULL) {
		// Get the size of the token
		tokenSize = strlen(token);

		// If the token is a number, square it and add it to the output string
		if (isdigit(token[0])) {
			int num = atoi(token);
			int squared = num*num;
			char squaredString[MAX_STRING_LENGTH];
			sprintf(squaredString, "%d", squared);
			strcat(outputString, squaredString);
		}

		// If the token is a string, add it to the output string backwards
		else {
			char backwardsString[MAX_STRING_LENGTH];
			int i;
			for (i = 0; i < tokenSize; i++) {
				backwardsString[i] = token[tokenSize - 1 - i];
			}
			backwardsString[i] = '\0';
			strcat(outputString, backwardsString);
		}

		// Add the delimiter to the output string
		strcat(outputString, delimiter);

		// Get the next token
		token = strtok(NULL, delimiter);
	}
}

int main() {
	char inputString[MAX_STRING_LENGTH];
	char outputString[MAX_STRING_LENGTH];
	char delimiter[MAX_STRING_LENGTH];

	// Get the input string
	printf("Enter a string: ");
	fgets(inputString, MAX_STRING_LENGTH, stdin);
	inputString[strcspn(inputString, "\n")] = '\0';

	// Get the delimiter
	printf("Enter a delimiter (e.g. ','): ");
	fgets(delimiter, MAX_STRING_LENGTH, stdin);
	delimiter[strcspn(delimiter, "\n")] = '\0';

	// Process the string
	processString(inputString, outputString, delimiter);

	// Print the output string
	printf("Output: %s\n", outputString);

	return 0;
}