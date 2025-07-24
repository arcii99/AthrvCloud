//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char morse[26][6] = {
		{".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."},
		{".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, {".--."},
		{"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"},
		{"-.--"}, {"--.."}
	};

	char phrase[100];
	printf("Enter a phrase to convert to Morse code: ");
	scanf("%[^\n]", phrase);

	for (int i = 0; i < strlen(phrase); i++) {
		if (isalpha(phrase[i])) {
			int index = tolower(phrase[i]) - 'a';
			printf("%s", morse[index]);
		} else if (isspace(phrase[i])) {
			printf("   ");
		} else {
			printf("%c", phrase[i]);
		}

		if (i < strlen(phrase) - 1) {
			// Add a puzzle element
			if (i % 2 == 0) {
				printf("*");
			} else if (i % 3 == 0) {
				printf("-");
			} else if (i % 4 == 0) {
				printf("+");
			}
		}
	}

	return 0;
}