//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: complex
#include <stdio.h>
#include <string.h>

int main()
{
    // Define Cat Dictionary
    const char* c_cat[] = {
        "meow",     // Hello
        "purr",     // Goodbye
        "hiss",     // Yes
        "growl",    // No
        "mewmew",   // Thank you
        "scratches",// Please
        "paws",     // Food
        "whiskers", // Water
        "tail",     // Play
        "feathers", // Bird
        "mouse",    // Toy
        "litter",   // Bathroom
        "nap",      // Sleep
        "stare",    // Look
        "lick",     // Like
        "rub",      // Love
    };

    char input[1000];
    int i;

    printf("Enter a sentence in Cat Language (separated by spaces): ");
    fgets(input, 1000, stdin);

    // Split Sentence into Words
    char* word = strtok(input, " ");

    while (word != NULL)
    {
        // Check if word exists in Cat Dictionary
        for (i = 0; i < 16; i++)
        {
            if (strcmp(word, c_cat[i]) == 0)
            {
                // Print Translation
                switch (i)
                {
                    case 0:
                        printf("Hello ");
                        break;
                    case 1:
                        printf("Goodbye ");
                        break;
                    case 2:
                        printf("Yes ");
                        break;
                    case 3:
                        printf("No ");
                        break;
                    case 4:
                        printf("Thank you ");
                        break;
                    case 5:
                        printf("Please ");
                        break;
                    case 6:
                        printf("Food ");
                        break;
                    case 7:
                        printf("Water ");
                        break;
                    case 8:
                        printf("Play ");
                        break;
                    case 9:
                        printf("Bird ");
                        break;
                    case 10:
                        printf("Toy ");
                        break;
                    case 11:
                        printf("Bathroom ");
                        break;
                    case 12:
                        printf("Sleep ");
                        break;
                    case 13:
                        printf("Look ");
                        break;
                    case 14:
                        printf("Like ");
                        break;
                    case 15:
                        printf("Love ");
                        break;
                }
            }
        }

        word = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}