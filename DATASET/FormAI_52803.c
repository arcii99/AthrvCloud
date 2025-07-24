//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: single-threaded
#include <stdio.h>
#include <string.h>

int main()
{
    // Define mapping arrays for C cat language
    char* ccat_to_c[9] = {"meow", "purr", "hiss", "scratch", "lick",
                          "nuzzle", "pounce", "claw", "sniff"};
    char* c_to_ccat[26] = {"meow", "purr", "hiss", "scratch", "lick",
                           "nuzzle", "pounce", "claw", "sniff", "meow", "purr",
                           "hiss", "scratch", "lick", "nuzzle", "pounce", "claw",
                           "sniff", "meow", "purr", "hiss", "scratch", "lick",
                           "nuzzle", "pounce", "claw"};

    char input[1000];
    char output[1000] = "";

    printf("Enter C Cat language code: ");
    fgets(input, 1000, stdin);   // Read input from user

    strtok(input, "\n");    // Remove the newline character

    // Loop through input string
    int i;
    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] != ' ')
        {
            // Convert C Cat to C code
            int index = input[i] - 'a';    // Get index of C language character
            strcat(output, c_to_ccat[index]);  // Append C Cat translation to output string
        }
        else
        {
            strcat(output, " ");   // Append space to output string
        }
    }

    // Print translated code
    printf("Translated C code: %s", output);

    return 0;
}