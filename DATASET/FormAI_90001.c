//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: scalable
#include <stdio.h>
#include <string.h>

int main() {
    char c_cat_language[] = "meow meow prrrrrr\npurr meow prrr\nmeow purr prrrr\nmeow meow meow prrrrrr";
    char *c_cat_words[4] = {"I", "love", "you", "too"};

    // split language into lines
    char *line = strtok(c_cat_language, "\n");

    printf("C Cat Language Translator:\n");

    while (line != NULL) {
        // split line into words
        char *word = strtok(line, " ");
        while (word != NULL) {
            // translate word
            int index;
            if (strcmp(word, "meow") == 0) {
                index = 0;
            } else if (strcmp(word, "purr") == 0) {
                index = 1;
            } else if (strcmp(word, "prrrrrr") == 0) {
                index = 2;
            } else {
                index = -1;
            }

            // print translated word
            if (index != -1) {
                printf("%s ", c_cat_words[index]);
            } else {
                printf("%s ", word);
            }

            // get next word
            word = strtok(NULL, " ");
        }
        printf("\n");

        // get next line
        line = strtok(NULL, "\n");
    }

    return 0;
}