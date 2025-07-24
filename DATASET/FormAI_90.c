//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Happy Birthday Celebration!\n");
    printf("We're going to be generating a personalized birthday message for you!\n");
    
    srand(time(NULL));
    
    char names[3][10] = {"Bob", "Lisa", "Steve"};
    char gifts[3][20] = {"a new car", "a vacation", "a puppy"};
    char locations[3][20] = {"the beach", "the mountains", "Disneyland"};
    
    int random_index = rand() % 3;
    
    printf("Happy Birthday, %s!\n", names[random_index]);
    printf("We hope you have a wonderful day filled with joy and happiness!\n");
    printf("In celebration of your special day, we have a surprise gift just for you!\n");
    printf("You'll be receiving %s!\n", gifts[random_index]);
    printf("And, to make things even better, you'll get to enjoy it in %s!\n", locations[random_index]);
    
    printf("We hope you have a fantastic birthday!\n");
    printf("Thanks for letting us celebrate with you!\n");
    
    return 0;
}