//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: high level of detail
#include <stdio.h>
#include <string.h>

int main() {
    char alien[100];
    int i, j, len;
    printf("Enter a sentence in Alien Language: ");
    fgets(alien, 100, stdin);

    len = strlen(alien);

    // Translation dictionary
    char alien_dict[12][10] = {"zoo", "noo", "lee", "gaa", "taa", "paa", "raa", "maa", "faa", "waa", "doo", "boo"};
    char eng_dict[12][10] = {"hello", "goodbye", "thank you", "please", "sorry", "yes", "no", "maybe", "help", "food", "drink", "sleep"};

    // Translation loop
    for (i = 0; i < len-2; i += 3) {
        char temp[4];
        temp[0] = alien[i];
        temp[1] = alien[i+1];
        temp[2] = alien[i+2];
        temp[3] = '\0';

        // Look up the translation in the dictionary
        for (j = 0; j < 12; j++) {
            if (strcmp(temp, alien_dict[j]) == 0) {
                printf("%s ", eng_dict[j]);
                break;
            }
        }
    }

    printf("\n");

    return 0;
}