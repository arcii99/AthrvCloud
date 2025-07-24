//FormAI DATASET v1.0 Category: Spam Detection System ; Style: futuristic
#include <stdio.h>
#include <string.h>

// Function to check if the message contains spam
int check_spam(char message[]) {
    char spam_list[5][20] = {"make money fast", "enlarge your", "amazing offers", "buy now", "limited time offer"};
    int i, j;
    int match_count = 0;
    int spam_list_length = sizeof(spam_list) / sizeof(spam_list[0]);

    // Loop through all words in the message
    for(i = 0; message[i] != '\0'; i++) {
        char word[20] = "";
        int k = 0;

        // Loop through each character in the word and check if it's a letter
        for(j = i; message[j] != ' ' && message[j] != '\0'; j++) {
            if((message[j] >= 'a' && message[j] <= 'z') || (message[j] >= 'A' && message[j] <= 'Z')) {
                word[k++] = message[j];
            }
        }

        // Check if the word is in the spam list
        for(j = 0; j < spam_list_length; j++) {
            if(strcmp(word, spam_list[j]) == 0) {
                match_count++;
            }
        }

        // If there are 2 or more matches, the message is considered spam
        if(match_count >= 2) {
            return 1;
        }
    }

    // Return 0 if the message is not considered spam
    return 0;
}

int main() {
    char message[100];

    printf("Enter your message: ");
    fgets(message, 100, stdin);

    if(check_spam(message)) {
        printf("This message is spam. Please do not send it.\n");
    } else {
        printf("This message is not spam. You may send it.\n");
    }

    return 0;
}