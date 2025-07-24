//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char morseCode[26][5] = {
		".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
	};
	char text[100];
	printf("Enter text to convert to Morse Code: ");
	fgets(text, sizeof(text), stdin);
	text[strcspn(text, "\n")] = 0;
	printf("\n");

	for (int i = 0; i < strlen(text); i++) {
		if (isspace(text[i])) {
			printf("   ");
		} else if (isalpha(text[i])) {
			printf("%s ", morseCode[toupper(text[i]) - 'A']);
		} else {
			printf("%c ", text[i]);
		}
	}
	printf("\n");
	return 0;
}