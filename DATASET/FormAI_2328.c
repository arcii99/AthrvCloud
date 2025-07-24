//FormAI DATASET v1.0 Category: Spam Detection System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int main() {
    FILE *fp;
    char filename[MAX_LEN];
    char line[MAX_LEN];
    int count_spam = 0, count_ham = 0, total_count = 0, num_spam_words = 0, num_ham_words = 0;

    printf("Enter the file name: ");
    fgets(filename, MAX_LEN, stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline character at the end of filename

    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    while(fgets(line, MAX_LEN, fp) != NULL) {
        char *token;
        const char *s = " \t\n"; // Delimiters

        token = strtok(line, s);
        while(token != NULL) {
            if(!strcmp(token, "spam")) { // If the word is "spam", increase the spam count and total count
                count_spam++;
                total_count++;
            } else if(!strcmp(token, "ham")) { // If the word is "ham", increase the ham count and total count
                count_ham++;
                total_count++;
            } else {
                if(count_spam > count_ham) { // If spam count is greater than ham count, the word is more likely spam
                    num_spam_words++;
                } else if(count_spam < count_ham) { // If ham count is greater than spam count, the word is more likely ham
                    num_ham_words++;
                }
                // Reset count_spam and count_ham for the next word
                count_spam = 0;
                count_ham = 0;
            }
            token = strtok(NULL, s);
        }
    }

    printf("Total number of words: %d\n", total_count);
    printf("Number of spam words: %d\n", num_spam_words);
    printf("Number of ham words: %d\n", num_ham_words);

    if(num_spam_words > num_ham_words) {
        printf("This message is likely spam.\n");
    } else {
        printf("This message is likely ham.\n");
    }

    fclose(fp);

    return 0;
}