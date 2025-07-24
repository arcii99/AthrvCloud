//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: ephemeral
#include <stdio.h>
#include <string.h>

//	Function to convert given character to ASCII art
void charToAscii(char character) {
	
	switch(character) {
		case 'A':
		case 'a':
			printf("    /\\    \n");
			printf("   /  \\   \n");
			printf("  /----\\  \n");
			printf(" /      \\ \n");
			printf("/        \\\n");
			break;
		
		case 'B':
		case 'b':
			printf(" ______  \n");
			printf("|      \\ \n");
			printf("|       |\n");
			printf("|_______|\n");
			printf("|       |\n");
			printf("|_______|\n");
			break;
		
		case 'C':
		case 'c':
			printf("  ______ \n");
			printf(" /      \\\n");
			printf("/        \\\n");
			printf("\\        /\n");
			printf(" \\______/\n");
			break;
		
		case 'D':
		case 'd':
			printf(" _______ \n");
			printf("|       \\\n");
			printf("|        \\\n");
			printf("|         \\\n");
			printf("|         |\n");
			printf("|________/\n");
			break;
		
		// Add more cases for more characters here...
		
		default:
			printf("      /\\      \n");
			printf("     /  \\     \n");
			printf("    /    \\    \n");
			printf("   /------\\   \n");
			printf("  /        \\  \n");
			printf(" /          \\ \n");
			break;
	}
	
}

int main() {
	
	char input[100];
	
	printf("Enter a string to convert to ASCII art:\n");
	fgets(input, sizeof(input), stdin);
	
	// Remove the newline character at the end of the input
	input[strcspn(input, "\n")] = 0;
	
	// Display the ASCII art for each character in the input string
	for(int i = 0; i < strlen(input); i++) {
		charToAscii(input[i]);
	}
	
	return 0;
}