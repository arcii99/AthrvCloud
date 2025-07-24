//FormAI DATASET v1.0 Category: Educational ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void validate_password(char* input_password) {
    char password[10] = "secretpass";
    if (strlen(input_password) != strlen(password)) {
        printf("Invalid password!\n");
        return;
    }
    for (int i=0; i<strlen(password); i++) {
        if (password[i] != input_password[i]) {
            printf("Invalid password!\n");
            return;
        }
    }
    printf("Access granted!\n");
}

void find_security_holes() {
    char* buffer = (char*) calloc(100, sizeof(char));
    printf("Please enter your username:\n");
    scanf("%s", buffer);
    printf("Please enter your password:\n");
    scanf("%s", buffer);
    validate_password(buffer);
}

int main() {
    printf("Welcome to our secure application!\n\n");
    printf("We take security very seriously here. That's why we've implemented a state-of-the-art password validation system to make sure that only authorized users can access our program.\n\n");
    printf("But we're always looking for ways to improve our security, which is why we want you to try to find any security holes that might exist in our program. If you can find any vulnerabilities, we'll reward you with a cash prize!\n\n");
    printf("To get started, simply enter your username and password in the fields below:\n");
    
    find_security_holes();
    
    printf("Thank you for participating in our security challenge. We'll be reviewing your findings and will let you know if you've won the prize.\n");
    return 0;
}