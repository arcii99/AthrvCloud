//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Initializing the random number generator

    // Storing the fortunes in an array
    char fortunes[10][100] = {
        "It is certain",
        "It is decidedly so",
        "Without a doubt",
        "Yes - definitely",
        "You may rely on it",
        "As I see it, yes",
        "Most likely",
        "Outlook good",
        "Yes",
        "Signs point to yes"
    };

    int randNum = rand() % 10; // Generating a random number between 0 and 9
    printf("The fortune teller says: %s\n", fortunes[randNum]); // Printing out the corresponding fortune

    return 0;
}