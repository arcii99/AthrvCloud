//FormAI DATASET v1.0 Category: Spam Detection System ; Style: cheerful
#include<stdio.h>
#include<string.h>

int isSpam(char message[], int n) {
    char keywords[10][20] = {"lottery", "money", "free", "offer", "discount", "sale", "deal", "cash", "prize", "win"};
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (strstr(message[i], keywords[j]) != NULL) {
                count++;
            }
        }
    }
    if (count >= 3) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    printf("Welcome to the Spam Detection System!\n");
    while (1) {
        printf("Enter your message (type 'exit' to quit):\n");
        char message[100][100];
        int n = 0;
        while (1) {
            fgets(message[n], 100, stdin);
            if (strcmp(message[n], "exit\n") == 0 || strcmp(message[n], "exit\r\n") == 0) {
                return 0;
            }
            if (strcmp(message[n], "\n") == 0) {
                break;
            }
            n++;
        }
        if (isSpam(message, n)) {
            printf("This is a Spam message.\n");
        } else {
            printf("This is a genuine message.\n");
        }
    }
    return 0;
}