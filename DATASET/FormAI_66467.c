//FormAI DATASET v1.0 Category: String manipulation ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {
    char username[20];
    char password[20];
    char attempt[20];
    int access_granted = 0;
    
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    
    if (strcmp(username, "Neo") == 0 && strcmp(password, "Trinity") == 0) {
        printf("Access granted.\n");
        access_granted = 1;
    } else {
        printf("Access denied.\n");
        access_granted = 0;
    }
    
    while (access_granted == 1) {
        printf("Enter your command: ");
        scanf("%s", attempt);
        if (strcmp(attempt, "decrypt") == 0) {
            printf("Initiating decryption sequence...\n");
            //insert decryption code here
        } else if (strcmp(attempt, "hack") == 0) {
            printf("Initiating hacking sequence...\n");
            //insert hacking code here
        } else if (strcmp(attempt, "exit") == 0) {
            printf("Goodbye.\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    
    return 0;
}