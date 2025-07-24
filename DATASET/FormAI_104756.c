//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: careful
#include <stdio.h>
#include <string.h>

// Function to translate from English to Cat Language
void english_to_cat(char input[]) {
    char output[1000] = "";

    // Loop through each character of input
    for (int i = 0; i < strlen(input); i++) {
        switch(input[i]) {
            case 'a':
                strcat(output, "meow");
                break;
            case 'b':
                strcat(output, "purr");
                break;
            case 'c':
                strcat(output, "hiss");
                break;
            case 'd':
                strcat(output, "scratch");
                break;
            case 'e':
                strcat(output, "paw");
                break;
            case 'f':
                strcat(output, "hunt");
                break;
            case 'g':
                strcat(output, "climb");
                break;
            case 'h':
                strcat(output, "nap");
                break;
            case 'i':
                strcat(output, "lick");
                break;
            case 'j':
                strcat(output, "cuddle");
                break;
            case 'k':
                strcat(output, "treat");
                break;
            case 'l':
                strcat(output, "drink");
                break;
            case 'm':
                strcat(output, "fish");
                break;
            case 'n':
                strcat(output, "bird");
                break;
            case 'o':
                strcat(output, "mouse");
                break;
            case 'p':
                strcat(output, "rat");
                break;
            case 'q':
                strcat(output, "yawn");
                break;
            case 'r':
                strcat(output, "stretch");
                break;
            case 's':
                strcat(output, "pounce");
                break;
            case 't':
                strcat(output, "swat");
                break;
            case 'u':
                strcat(output, "knead");
                break;
            case 'v':
                strcat(output, "purr");
                break;
            case 'w':
                strcat(output, "slick");
                break;
            case 'x':
                strcat(output, "scratch");
                break;
            case 'y':
                strcat(output, "lick");
                break;
            case 'z':
                strcat(output, "nap");
                break;
            case ' ':
                strcat(output, " ");
                break;
            default:
                strcat(output, "meow");
        }
    }

    // Display the translated output
    printf("Cat Language: %s\n", output);
}

int main() {
    char input[1000];

    // Get user input
    printf("Enter English text to translate to Cat Language: ");
    fgets(input, sizeof(input), stdin);

    // Call translate function
    english_to_cat(input);

    return 0;  
}