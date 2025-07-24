//FormAI DATASET v1.0 Category: Spam Detection System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char email[100];
    int i, count = 0;

    printf("Enter email message: ");
    gets(email);

    char *spamWords[] = {"money", "discount", "offer", "limited time", "click here"};

    for(i = 0; i < 5; i++) {
        if(strstr(email, spamWords[i]) != NULL) {
            count++;
        }
    }

    if(count > 2) {
        printf("This is a spam message.\n");
    } else {
        printf("This is not a spam message.\n");
    }

    return 0;
}