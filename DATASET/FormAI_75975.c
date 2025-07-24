//FormAI DATASET v1.0 Category: Spam Detection System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_for_spam(char *str);

int main() {
    char message[1024], *ptr;
    int is_spam;
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);
    ptr = strtok(message, " ");
    while(ptr != NULL) {
        is_spam = check_for_spam(ptr);
        if(is_spam) {
            printf("SPAM DETECTED\n");
            exit(0);
        }
        ptr = strtok(NULL, " ");
    }
    printf("Message is free of spam\n");
    return 0;
}

int check_for_spam(char *str) {
    int i, len, spam_count = 0;
    char *spam_words[] = {"win", "money", "prize", "viagra", "porn"};
    len = sizeof(spam_words) / sizeof(spam_words[0]);
    for(i = 0; i < len; i++) {
        if(strstr(str, spam_words[i]) != NULL) {
            spam_count++;
            if(spam_count >= 2) {
                return 1;
            }
        }
    }
    return 0;
}