//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

// Define the Morse code mappings
char *morse_codes[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", 
						".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", 
						".--", "-..-", "-.--", "--.." };
char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

// Define a function to convert text to Morse code
void text_to_morse(char *text)
{
	// Loop through each character in the input string
	for (int i = 0; i < strlen(text); i++)
	{
		// Ignore spaces
		if (text[i] == ' ') {
			printf("  ");
		}
		else {
			// Find the index of this character in the alpha string
			int index = -1;
			for (int j = 0; j < strlen(alpha); j++) {
				if (alpha[j] == toupper(text[i])) {
					index = j;
					break;
				}
			}

			// Print the Morse code equivalent
			if (index >= 0) {
				printf("%s ", morse_codes[index]);
			}
		}
	}	
}

int main()
{
	printf("Enter text to convert to Morse code:\n");
	char text[100];
	fgets(text, 100, stdin);

	printf("Morse code version:\n");
	text_to_morse(text);

	return 0;
}