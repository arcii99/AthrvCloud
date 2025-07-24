//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: thoughtful
#include <stdio.h> 

int main() {

char text[500];
int row, column, ascii; //variables to store row, column and ascii value
int i, j;

printf("Enter your text (max 500 characters):\n");
fgets(text, 500, stdin); //read the input text from the user

for (i = 0; text[i] != '\0'; i++) {

    ascii = text[i]; //store the ascii value of character in a variable

    for (j = 7; j >= 0; j--) {

        if ((ascii >> j) & 1) { //if bit is 1, print '*'
            printf("*");
        } else { //if bit is 0, print ' '
            printf(" ");
        }

    }
    printf("\n"); //move to next row
}

return 0;
}