//FormAI DATASET v1.0 Category: Spam Detection System ; Style: cheerful
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_spam(char *input) {
    bool contains_keywords = false;
    char keywords[10][10] = {"buy", "cheap", "discount", "free", "money", "offer", "sale", "viagra", "win", "xxx"};

    // Check if input contains one of the keywords
    for(int i = 0; i < 10; i++) {
        if(strstr(input, keywords[i])) {
            contains_keywords = true;
            break;
        }
    }

    // If input contains a keyword, it's a spam
    if(contains_keywords) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char input[100];
    printf("Hello! This is a Spam Detection System.\n");
    printf("Please enter your message:\n");
    fgets(input, 100, stdin);

    if(is_spam(input)) {
        printf("WARNING: This message contains spam!\n");
    } else {
        printf("This message is not spam. Have a nice day!\n");
    }

    return 0;
}