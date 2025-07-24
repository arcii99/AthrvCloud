//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
	char input_string[1000];
	int i, length;

	printf("Hey there! Welcome to the Palindrome Checker!\n");
	printf("Please enter a string: ");
	scanf("%s", input_string);

	length = strlen(input_string);

	for (i = 0; i < length/2; i++) {
		if (input_string[i] != input_string[length-i-1]) {
			break;
		}
	}

	if (i == length/2) {
		printf("\nYay! The entered string %s is a palindrome!\n", input_string);
	} else {
		printf("\nOops! The entered string %s is not a palindrome :(\n", input_string);
	}

	return 0;
}