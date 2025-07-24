//FormAI DATASET v1.0 Category: Spam Detection System ; Style: innovative
#include<stdio.h>
#include<string.h>

// This program is a simple spam detector, checking for the presence of certain words in an input message

int main() {

    char spamWords[10][20] = {"$100", "click here", "discount", "free money", "lose weight", 
                              "make money", "money back", "multilevel marketing", "opportunity", "work from home"};
    int numSpamWords = 10;

    char input[100];
    printf("Enter message: ");
    fgets(input, 100, stdin); // get input from user

    int i, j, flag;
    flag = 0;

    for (i = 0; i < numSpamWords; i++) {
        char* word = spamWords[i];
        if (strstr(input, word) != NULL) { // if word is found in input
            flag = 1; // flag true if spam detected
            break;
        }
    }

    if (flag) {
        printf("SPAM DETECTED!");
    }
    else {
        printf("Message is not spam.");
    }

    return 0;
}