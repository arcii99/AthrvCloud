//FormAI DATASET v1.0 Category: Spam Detection System ; Style: optimized
#include <stdio.h>
#include <string.h>

// struct for storing spam keywords
typedef struct {
    char keyword[20];
    int count;
} spam_keyword;

int main() {
    spam_keyword keywords[5]; // array of 5 spam keywords
    int i, j, count = 0; // loop and keyword count variables
    char message[200]; // message inputted by user
    
    // prompt user for input message
    printf("Enter a message: ");
    fgets(message, 200, stdin); // read message from user
    
    // remove newline character from message
    message[strcspn(message, "\n")] = 0;
    
    // initialize keywords array
    strcpy(keywords[0].keyword, "money");
    strcpy(keywords[1].keyword, "free");
    strcpy(keywords[2].keyword, "prize");
    strcpy(keywords[3].keyword, "offer");
    strcpy(keywords[4].keyword, "click");
    
    // check if message contains any spam keywords
    for (i = 0; i < 5; i++) {
        for (j = 0; j < strlen(message); j++) {
            if (message[j] == keywords[i].keyword[0]) { // if the first letter matches
                if (strstr(&message[j], keywords[i].keyword) != NULL) { // if the keyword is found
                    keywords[i].count++; // increment keyword count
                    count++; // increment total keyword count
                }
            }
        }
    }
    
    // display results to user
    if (count == 0) {
        printf("This message is not spam.");
    } else {
        printf("This message contains %d spam keywords:\n", count);
        for (i = 0; i < 5; i++) {
            if (keywords[i].count > 0) {
                printf("%s: %d\n", keywords[i].keyword, keywords[i].count);
            }
        }
    }
    
    return 0;
}