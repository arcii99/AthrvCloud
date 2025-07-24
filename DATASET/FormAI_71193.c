//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_LEN 10000
#define MAX_WORD_LEN 100

struct words {
    char word[MAX_WORD_LEN];
    int frequency;
};

struct resume {
    char content[MAX_RESUME_LEN];
};

void parse_resume(struct resume *r, struct words *w, int *num_words) {
    char *token;
    token = strtok(r->content, " ,.!?");

    while (token != NULL) {
        // Make word lowercase
        for (int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);
        }

        // Check if word already exists in list of words
        int match = 0;
        for (int i = 0; i < *num_words; i++) {
            if (strcmp(w[i].word, token) == 0) {
                w[i].frequency++;
                match = 1;
                break;
            }
        }

        // If word does not exist, add it to list of words
        if (!match) {
            strcpy(w[*num_words].word, token);
            w[*num_words].frequency = 1;
            *num_words += 1;
        }

        token = strtok(NULL, " ,.!?");
    }
}

int main() {
    struct resume r;
    struct words w[MAX_RESUME_LEN];
    int num_words = 0;

    printf("Enter resume content: ");
    fgets(r.content, MAX_RESUME_LEN, stdin);

    parse_resume(&r, w, &num_words);

    // Print out list of words and their frequency
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", w[i].word, w[i].frequency);
    }

    return 0;
}