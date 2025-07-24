//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main() {
    char* subjects[] = {"The government", "Aliens", "The Illuminati", 
                        "The Freemasons", "Big Pharma", "The Reptilians"};
    char* actions[] = {"is secretly controlling", "is hiding the truth about", 
                       "is manipulating the data on", "is funding research on", 
                       "is using technology to alter", "is working with"};
    char* objects[] = {"the weather", "our minds", "the stock market", 
                       "vaccines", "crop yields", "our DNA"};
 
    srand(time(NULL));
 
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Press enter to generate a conspiracy theory...\n");
    getchar();
 
    while (1) {
        int subject_index = rand() % 6;
        int action_index = rand() % 6;
        int object_index = rand() % 6;
 
        printf("%s %s %s.\n", subjects[subject_index], actions[action_index], objects[object_index]);
        
        printf("Do you want to generate another conspiracy theory? (y/n)\n");
        char c = getchar();
 
        if (c == 'n') {
            printf("Thanks for using the Random Conspiracy Theory Generator!\n");
            break;
        } else {
            getchar(); // Read the newline character
            printf("\nGenerating new conspiracy theory...\n\n");
        }
    }
 
    return 0;
}