//FormAI DATASET v1.0 Category: Spam Detection System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 1000
#define MAX_LINE_LEN 100

int main()
{
    char spam_phrases[10][30] = {"make money", "earn cash", "enlargement", "free trial", "money back guarantee", "call now", "limited time offer", "buy now", "lowest price", "exclusive offer"};
    char message[MAX_LINES][MAX_LINE_LEN];
    int i, j, spam_count;
    
    printf("Enter your message:\n");
    
    // Read input
    for (i = 0; i < MAX_LINES; i++) {
        fgets(message[i], MAX_LINE_LEN, stdin);
        if (strcmp(message[i], "\n") == 0) {
            break;
        }
    }
    
    spam_count = 0;
    
    // Check for spam phrases in message
    for (i = 0; i < MAX_LINES; i++) {
        for (j = 0; j < 10; j++) {
            if (strstr(message[i], spam_phrases[j])) {
                spam_count++;
                break;
            }
        }
    }
    
    // Print result
    printf("\nResult:\n");
    if (spam_count > 0) {
        printf("This message contains %d spam phrase(s).\n", spam_count);
    } else {
        printf("This message is not spam.\n");
    }
    
    return 0;
}