//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    int count = 0;
    
    printf("Enter your message: ");
    fgets(message, 1000, stdin);

    // Check for keywords
    if (strstr(message, "money") != NULL || strstr(message, "cash") != NULL) {
        count++;
    }
    if (strstr(message, "free") != NULL || strstr(message, "discount") != NULL) {
        count++;
    }
    if (strstr(message, "prince") != NULL || strstr(message, "inheritance") != NULL) {
        count++;
    }
    
    // Determine spam likelihood
    if (count == 0) {
        printf("This message is not spam.\n");
    } else if (count == 1) {
        printf("This message is likely spam.\n");
    } else if (count == 2) {
        printf("This message is highly likely spam.\n");
    } else {
        printf("This message is almost certainly spam.\n");
    }
    
    return 0;
}