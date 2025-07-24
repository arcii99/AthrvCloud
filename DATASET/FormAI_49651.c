//FormAI DATASET v1.0 Category: Random ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    printf("Welcome to my happy random number generator!\n");

    int num1 = rand() % 25 + 1; // generate a random number between 1 and 25
    int num2 = rand() % 25 + 1; // generate a second random number between 1 and 25
    int sum = num1 + num2; // add the two numbers together

    printf("Your first random number is %d!\n", num1);
    printf("Your second random number is %d!\n", num2);
    printf("The sum of your two numbers is %d!\n", sum);

    // Now let's generate a random quote!
    char *quotes[5] = {
        "You are the sunshine of my code!\n",
        "Keep calm and code on!\n",
        "You can do it! I believe in you!\n",
        "Code like nobody is debugging!\n",
        "Happiness is a compiler that just works!\n"
    };

    int quote_index = rand() % 5; // pick a random quote from the array
    printf("%s", quotes[quote_index]);

    return 0;
}