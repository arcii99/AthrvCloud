//FormAI DATASET v1.0 Category: Spam Detection System ; Style: shape shifting
#include<stdio.h>
#include<string.h>

int checkSpam(char text[]) {
    int spamCount=0;
    char* spamWords[5] = {"offer", "prize", "free", "limited", "discount"};
    int length = strlen(text);

    // Converting text to lowercase
    for(int i=0; i<length; i++) {
        text[i] = tolower(text[i]);
    }

    // Checking for spam words
    for(int i=0; i<5; i++) {
        char* ptr = strstr(text, spamWords[i]);
        if(ptr != NULL) {
            spamCount++;
        }
    }

    return spamCount;
}

int main() {
    char text[100];
    printf("Enter the text to check for spam: ");
    fgets(text, 100, stdin);

    int spamCount = checkSpam(text);

    if(spamCount > 0) {
        printf("This is a spam message.\n");
    } else {
        printf("This is not a spam message.\n");
    }

    return 0;
}