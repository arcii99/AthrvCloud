//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: funny
#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];
    printf("Welcome to the Input Sanitizer 5000!\n");
    printf("Please enter some text: ");
    fgets(input, 100, stdin);

    for (int i = 0; input[i] != '\0'; i++) {
        if (!isspace(input[i])) { // remove whitespace
            if (isalpha(input[i])) { // handle letters
                if (isupper(input[i])) {
                    input[i] = tolower(input[i]); // convert to lowercase
                } else {
                    input[i] = toupper(input[i]); // convert to uppercase
                }
            } else if (isdigit(input[i])) { // handle numbers
                switch(input[i]) {
                    case '0': 
                        input[i] = 'O'; // replace 0 with O
                        break;
                    case '1':
                        input[i] = 'I'; // replace 1 with I
                        break;
                    case '3':
                        input[i] = 'E'; // replace 3 with E
                        break;
                    case '4':
                        input[i] = 'A'; // replace 4 with A
                        break;
                    case '5':
                        input[i] = 'S'; // replace 5 with S
                        break;
                    case '6':
                        input[i] = 'G'; // replace 6 with G
                        break;
                    case '7':
                        input[i] = 'T'; // replace 7 with T
                        break;
                    case '8':
                        input[i] = 'B'; // replace 8 with B
                        break;
                    case '9':
                        input[i] = 'P'; // replace 9 with P
                        break;
                    default:
                        break;
                }
            } else { // handle all other characters
                input[i] = '?'; // replace with ?
            }
        }
    }

    printf("Sanitized text: %s", input);
    printf("\nThank you for using the Input Sanitizer 5000! Come back soon!\n");

    return 0;
}