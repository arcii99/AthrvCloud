//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create arrays of conspiracy theories and random words
    char* theories[10] = {"The moon landing was faked by the government",
                          "The Illuminati controls the world",
                          "Aliens have been living among us for years",
                          "The Earth is flat",
                          "The government is hiding the cure for cancer",
                          "The CIA assassinated JFK",
                          "Chemtrails are poisoning us",
                          "Bigfoot is real and the government is covering it up",
                          "The Denver airport is a secret underground bunker",
                          "The New World Order is taking over"};

    char* words[10] = {"chemtrails",
                       "aliens",
                       "government",
                       "illuminati",
                       "cancer",
                       "conspiracy",
                       "JFK",
                       "moon",
                       "Denver",
                       "new world order"};

    // Generate a random conspiracy theory
    int theoryIndex = rand() % 10;
    char* theory = theories[theoryIndex];

    // Inject random words into the conspiracy theory
    int wordIndex = rand() % 10;
    char* word = words[wordIndex];

    char newTheory[100];
    int i, j, k;
    for (i=0, j=0, k=0; theory[i]!='\0' && j<100; i++, j++) {
        if (theory[i] == ' ') {
            newTheory[j] = theory[i];
            j++;
            for (; word[k]!='\0'; k++, j++) {
                newTheory[j] = word[k];
                if (j == 99) {
                    break;
                }
            }
            k = 0;
        }
        newTheory[j] = theory[i];
        if (j == 99) {
            break;
        }
    }
    newTheory[j] = '\0';

    // Print the new conspiracy theory
    printf("%s\n", newTheory);

    return 0;
}