//FormAI DATASET v1.0 Category: Spam Detection System ; Style: authentic
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int check_spam(char message[]) {
    char spam1[] = "make money fast";
    char spam2[] = "buy now";
    char spam3[] = "limited time offer";
    char spam4[] = "one time deal";
    
    if(strstr(message, spam1) != NULL || strstr(message, spam2) != NULL || strstr(message, spam3) != NULL || strstr(message, spam4) != NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    char message[MAX_LENGTH];
    int is_spam;
    
    printf("Enter a message: ");
    fgets(message, MAX_LENGTH, stdin);
    
    is_spam = check_spam(message);
    
    if(is_spam) {
        printf("This message is spam.\n");
    } else {
        printf("This message is not spam.\n");
    }
    
    return 0;
}