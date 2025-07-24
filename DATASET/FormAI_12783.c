//FormAI DATASET v1.0 Category: Spam Detection System ; Style: surprised
#include <stdio.h>
#include <string.h>

int check_spam(char *message) {
    int count = 0; // to count the number of spam keywords found
    char keywords[10][20] = { "cash", "best deal", "limited time offer", "money back guarantee", "urgent", "winner", "discount", "buy", "free", "click here" };
    // 10 most common spam keywords, feel free to add more
    
    char *word;
    word = strtok(message, " "); // get the first word
    
    while (word != NULL) { // loop until no more words found
        for (int i = 0; i < 10; i++) { // loop through each keyword
            if (strcmp(word, keywords[i]) == 0) { // if keyword found in message
                count++;
            }
        }
        word = strtok(NULL, " "); // get next word
    }
    
    if (count >= 3) { // if more than 3 spam keywords found
        return 1; // spam detected
    }
    else {
        return 0; // spam not detected
    }
}

int main() {
    char message[200];
    printf("Enter message to check for spam: ");
    fgets(message, 200, stdin); // read user input
    
    if (check_spam(message)) {
        printf("WARNING: This message contains spam keywords.");
    }
    else {
        printf("This message does not contain spam keywords.");
    }
    
    return 0;
}