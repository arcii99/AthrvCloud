//FormAI DATASET v1.0 Category: Word Count Tool ; Style: calm
#include <stdio.h>
#include <string.h>
#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 5000

int word_count(char *s);
void print_dictionary(char words[][MAX_WORD_LENGTH], int frequency[], int count);

int main() {
    char text[100000];
    printf("Enter text\n");
    fgets(text, 100000, stdin);

    int count = word_count(text);

    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    int frequency[MAX_NUM_WORDS] = { 0 };

    char *token = strtok(text, " \n");

    while(token != NULL) {
        int i;
        for(i = 0; i < count; i++) {
            if(strcmp(words[i], token) == 0) {
                frequency[i] += 1;
                break;
            } else if(frequency[i] == 0) {
                strcpy(words[i], token);
                frequency[i] += 1;
                break;
            }
        }
        token = strtok(NULL, " \n");
    }
    print_dictionary(words, frequency, count);
    return 0;
}

int word_count(char *s) {
    int i, count = 1;
    for(i = 0; s[i] != '\0'; i++) {
        if(s[i] == ' ' || s[i] == '\n') {
            count++;
        }
    }
    return count;
}

void print_dictionary(char words[][MAX_WORD_LENGTH], int frequency[], int count) {
    printf("\nWord Count:\n");

    int i;
    for(i = 0; i < count; i++) {
        if(frequency[i] > 0) {
            printf("%s: %d\n", words[i], frequency[i]);
        }
    }
}