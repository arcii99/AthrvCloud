//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    int length, letters = 0, digits = 0, symbols = 0, score = 0;

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);

    length = strlen(password);

    for(int i=0; i<length; i++) {
        if(password[i] >= 'a' && password[i] <= 'z') // Check lowercase letters
            letters++;
        else if(password[i] >= 'A' && password[i] <= 'Z') // Check uppercase letters
            letters++;
        else if(password[i] >= '0' && password[i] <= '9') // Check digits
            digits++;
        else // Check symbols
            symbols++;
    }

    // Calculate score based on password strength
    if(length >= 8 && letters > 0 && digits > 0 && symbols > 0)
        score = 4;
    else if(length >= 8 && letters > 0 && digits > 0)
        score = 3;
    else if(length >= 8 && letters > 0)
        score = 2;
    else if(length >= 8)
        score = 1;

    // Print password strength and score
    if(score == 4)
        printf("Password strength: Strong (Score: %d)\n", score);
    else if(score == 3)
        printf("Password strength: Medium (Score: %d)\n", score);
    else if(score == 2)
        printf("Password strength: Weak (Score: %d)\n", score);
    else if(score == 1)
        printf("Password strength: Very weak (Score: %d)\n", score);
    else
        printf("Error calculating password strength.\n");

    return 0;
}