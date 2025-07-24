//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: relaxed
#include <stdio.h>

int main() {

    char input[100];

    printf("Enter a text to convert to ASCII art: ");
    fgets(input, 100, stdin);

    printf("\n");

    for (int i = 0; input[i] != '\0'; i++) {

        int asciiValue = (int)input[i];

        switch(asciiValue) {

            case 32:
                printf("      ");
            break;

            case 33:
                printf("  /\\  \n (  ) \n/    \\\n");
            break;

            case 34:
                printf(" _   _ \n( )_( )\n(____)\n");
            break;

            case 35:
                printf("  #   #  \n#########\n  #   #  \n");
            break;

            // Add more cases for other characters

            default:
                printf("     ?    \n");
        }
    }

    return 0;
}