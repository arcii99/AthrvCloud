//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Linus Torvalds
#include <stdio.h>

#define MAX_ERRORS 5
// maximum number of attempts before triggering intrusion detection

int main() {
    
    char username[20];
    char password[20];
    int attempts = 0;
    
    while (attempts < MAX_ERRORS) {
        printf("Username: ");
        scanf("%s", username);
        
        printf("Password: ");
        scanf("%s", password);
        
        if (strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0) {
            printf("Welcome, admin!\n");
            break;
        } else {
            printf("Invalid username or password. Try again.\n");
            attempts++;
        }
    }
    
    if (attempts == MAX_ERRORS) {
        printf("Intrusion detected!!!\n");
        // some code to notify system administrator or security team
    }
    
    return 0;
}