//FormAI DATASET v1.0 Category: Text processing ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {

    char input[100];
    printf("Please input a sentence:\n");
    fgets(input, sizeof(input), stdin);

    int len = strlen(input);
    char grateful_sentence[len+10];
    memset(grateful_sentence, '\0', sizeof(grateful_sentence));

    char *word = strtok(input, " ");

    while (word != NULL) {
        strcat(grateful_sentence, word);
        strcat(grateful_sentence, " is GREAT. ");
        word = strtok(NULL, " ");
    }

    printf("\nYour sentence in grateful form:\n%s\n", grateful_sentence);

    return 0;
}