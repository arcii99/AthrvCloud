//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, num_sentences;
    char* subjects[] = {"The government", "Corporations", "Aliens", "The Illuminati", "Reptilians"};
    char* verbs[] = {"are controlling", "are manipulating", "are brainwashing", "are surveilling", "are conspiring with"};
    char* objects[] = {"the weather", "our minds", "the economy", "the media", "world leaders"};
    char* adverbs[] = {"secretly", "surreptitiously", "covertly", "clandestinely", "stealthily"};

    srand(time(NULL));

    printf("C Random Conspiracy Theory Generator\n\n");
    printf("Enter the number of sentences you'd like to generate: ");
    scanf("%d", &num_sentences);

    for (i = 0; i < num_sentences; i++) {
        printf("%d. %s %s %s ", i+1, subjects[rand() % 5], verbs[rand() % 5], objects[rand() % 5]);
        
        // Add adverb with 20% probability
        if (rand() % 5 == 0) {
            printf("%s ", adverbs[rand() % 5]);
        }
        
        // Add prepositional phrase with 50% probability
        if (rand() % 2 == 0) {
            printf("with the help of ");
            for (j = 0; j < 2; j++) {
                printf("%s", subjects[rand() % 5]);
                if (j == 0) {
                    printf(" and ");
                }
            }
            printf(" ");
        }
        
        // Add quotation with 30% probability
        if (rand() % 3 == 0) {
            printf("\"%s is not what it seems.\"", objects[rand() % 5]);
        }
        
        printf("\n");
    }

    return 0;
}