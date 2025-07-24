//FormAI DATASET v1.0 Category: Spam Detection System ; Style: detailed
#include <stdio.h>
#include <string.h>

int main() {
    char message[100];
    int flag = 0;
    
    printf("Enter your message: ");
    fgets(message, 100, stdin); // get user input
    
    // check if message contains common spam keywords
    if (strstr(message, "free")) {
        flag = 1; // mark as spam
    }
    else if (strstr(message, "win")) {
        flag = 1; // mark as spam
    }
    else if (strstr(message, "money")) {
        flag = 1; // mark as spam
    }
    
    // check if message contains excessive use of capital letters
    int caps_count = 0;
    for (int i=0; message[i]; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            caps_count++;
        }
    }
    if (caps_count > 10) {
        flag = 1; // mark as spam
    }
    
    // check if message is shorter than 10 characters
    if (strlen(message) < 10) {
        flag = 1; // mark as spam
    }
    
    // print message status
    if (flag == 1) {
        printf("\nThis message is spam.");
    }
    else {
        printf("\nThis message is not spam.");
    }
    
    return 0;
}