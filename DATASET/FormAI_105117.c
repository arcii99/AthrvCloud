//FormAI DATASET v1.0 Category: Word Count Tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

int main()
{
    char text[1000];
    char *words[MAX_WORDS];
    int counts[MAX_WORDS] = { 0 };
    int total_words = 0, unique_words = 0;
    int i, j, k, found;

    printf("Enter some text:\n");
    fgets(text, 1000, stdin);

    /* Split text into words */
    words[0] = strtok(text, " ,.!?\"()\n");
    while (words[total_words] != NULL) {
        total_words++;
        words[total_words] = strtok(NULL, " ,.!?\"()\n");
    }

    /* Count the occurrences of each word */
    for (i = 0; i < total_words; i++) {
        found = 0;
        for (j = 0; j < unique_words; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                counts[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            words[unique_words] = words[i];
            counts[unique_words]++;
            unique_words++;
        }
    }

    printf("\nWord count:\n");
    for (i = 0; i < unique_words; i++) {
        printf("%s: %d\n", words[i], counts[i]);
    }

    return 0;
}