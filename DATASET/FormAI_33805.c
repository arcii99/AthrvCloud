//FormAI DATASET v1.0 Category: Text processing ; Style: grateful
#include <stdio.h>
#include <string.h>

void printGrateful(char str[]) {
    int len = strlen(str);
    int i;
    for (i=0; i<len; i++) {
	if (str[i] != ' ') {
	    printf("%c ", str[i]);
	}
	else {
	    printf("grateful ");
	}
    }
}

int main() {

    // Gather and process user input
    char input[100];
    printf("Welcome! Please enter a phrase you're grateful for: \n");
    fgets(input, sizeof(input), stdin);

    // Process the input and print output
    printf("Here is your input processed with gratitude: \n");
    printGrateful(input);
    printf("\n");

    return 0;
}