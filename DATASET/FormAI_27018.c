//FormAI DATASET v1.0 Category: Spam Detection System ; Style: careful
#include <stdio.h>
#include <string.h>

//function to detect spam words in a string
int detectSpam(char str[]) {
    char spamWords[5][20] = {"offer", "win", "money", "free", "limited time"};
    int count = 0;
    char *token;

    //splitting the string into words 
    token = strtok(str, " ");

    while (token != NULL) {
        for(int i=0; i<5; i++) {
            if(strcmp(token, spamWords[i]) == 0) {
                count++;
            }
        }
        token = strtok(NULL, " ");
    }

    //if total count of spam words is greater than 2, it is considered as spam
    if(count > 2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char input[100];

    printf("Enter a string:\n");
    fgets(input, 100, stdin);

    if(detectSpam(input) == 1) {
        printf("This string contains spam words.\n");
    } else {
        printf("This string is free from spam words.\n");
    }

    return 0;
}