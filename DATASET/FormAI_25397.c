//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Donald Knuth
#include <stdio.h>

#define MAX_LOGIN_ATTEMPTS 3

int main() {
    int login_attempts = 0;
    
    while (1) {
        printf("Enter username: ");
        char username[20];
        scanf("%19s", username);
        
        printf("Enter password: ");
        char password[20];
        scanf("%19s", password);
        
        if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
            printf("Login successful!\n");
            break;
        } else {
            printf("Incorrect username or password!\n");
            login_attempts++;
        }
        
        if (login_attempts >= MAX_LOGIN_ATTEMPTS) {
            printf("Too many login attempts!\n");
            // Call intrusion detection system
            break;
        }
    }
    
    return 0;
}