//FormAI DATASET v1.0 Category: System administration ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc, char *argv[]) {
    char *username = "example_user";
    char *password = "example_password";
    
    struct passwd *p = getpwnam(username);
    
    // Check if user already exists
    if(p != NULL) {
        printf("The user %s already exists.\n", username);
        return 1;
    }
    
    // Create a new user account
    char *argv1[] = { "useradd", "-p", password, "-m", username, NULL };
    int result = execv("/usr/sbin/useradd", argv1);
    
    if(result != 0) {
        printf("Error creating user account.\n");
        return 1;
    }
    
    printf("User account %s created successfully.\n", username);
    return 0;
}