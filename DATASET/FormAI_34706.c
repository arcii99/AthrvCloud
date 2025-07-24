//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char* fortunes[] = {"You will find love soon.", 
                        "A great job opportunity is coming your way.",
                        "You will inherit a large sum of money.",
                        "The stars are aligned in your favor.",
                        "A vacation is in your future."};
    int num_fortunes = sizeof(fortunes)/sizeof(fortunes[0]);
    
    srand(time(NULL)); // Seed the random number generator
    
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Think of a question and I will give you a fortune.\n");
    
    while(1) {
        char answer;
        printf("\nAre you ready? (Y/N): ");
        scanf(" %c", &answer);
        
        if (answer == 'Y' || answer == 'y') {
            printf("\nThinking...\n");
            int index = rand() % num_fortunes;
            printf("\nYour fortune is: %s\n", fortunes[index]);
        }
        else if (answer == 'N' || answer == 'n') {
            printf("\nGoodbye!\n");
            break;
        }
        else {
            printf("\nInvalid input. Please enter Y or N.\n");
        }
    }
    
    return 0;
}