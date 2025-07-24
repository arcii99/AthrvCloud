//FormAI DATASET v1.0 Category: Spam Detection System ; Style: sophisticated
#include <stdio.h>
#include <string.h>

#define MAX_EMAIL_SIZE 1000
#define SPAM_THRESHOLD 0.8

int main(void) {
    char email[MAX_EMAIL_SIZE];
    printf("Enter your email: ");
    fgets(email, MAX_EMAIL_SIZE, stdin);

    int email_size = strlen(email);
    int spam_count = 0;
    int i;

    for(i = 0; i < email_size; i++) {
        if(email[i] == 'l') { // common spam letter
            spam_count++;
        }
    }

    double spam_ratio = (double) spam_count / (double) email_size;
    if(spam_ratio > SPAM_THRESHOLD) {
        printf("This email is likely spam.\n");
    } else {
        printf("This email is not likely spam.\n");
    }

    return 0;
}