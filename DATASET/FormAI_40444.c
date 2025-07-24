//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: light-weight
#include <stdio.h>
#include <string.h>

int main()
{
    char inputString[100];
    int i, j;

    printf("Please enter the string in Cat Language: ");
    gets(inputString);

    char outputString[100] = "";
    int counter = 0;        // The Cat Language uses a counter to count 'a's before adding 'meow'
    
    for (i = 0; i < strlen(inputString); i++) {
        if (inputString[i] == 'a') {
            counter++;
        } else {
            if (counter > 0) {
                for (j = 0; j < counter; j++) {
                    strcat(outputString, "a");
                }
                strcat(outputString, "meow");
                counter = 0;
            }
            strncat(outputString, &inputString[i], 1);        // Add the non-'a' character to the output string
        }
    }

    if (counter > 0) {        // Add any remaining 'a's to the output string
        for (j = 0; j < counter; j++) {
            strcat(outputString, "a");
        }
        strcat(outputString, "meow");
    }

    printf("\nTranslated string in C language: %s", outputString);

    return 0;
}