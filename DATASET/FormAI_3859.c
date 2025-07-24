//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *fortune[] = {"You will have a great day today.",
                       "A new opportunity is coming your way.",
                       "Your hard work will pay off.",
                       "Your creativity will lead to success.",
                       "A surprise is waiting for you today.",
                       "Good news is on the horizon.",
                       "You will make a new friend today.",
                       "Your determination will bring you victory.",
                       "Spend time with loved ones today.",
                       "Your confidence will inspire others.",
                       "A positive change is coming your way.",
                       "You will learn something valuable today.",
                       "Your efforts will be recognized and rewarded.",
                       "A pleasant experience is in store for you today.",
                       "Your generosity will bring you happiness."};
    int num_fortunes = sizeof(fortune) / sizeof(fortune[0]);
    
    srand(time(NULL)); // Initialize random seed
    
    printf("*** Welcome to the Automated Fortune Teller ***\n\n");
    printf("Would you like to receive your fortune? (y/n): ");
    
    char response;
    scanf("%c", &response);
    
    if (response == 'y') {
        int random_index = rand() % num_fortunes;
        printf("\n%s\n", fortune[random_index]);
    } else {
        printf("\nOkay, have a nice day!\n");
    }
    
    return 0;
}