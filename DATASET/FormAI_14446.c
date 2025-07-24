//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char password[100];
    printf("Hey there! Let's check how strong your password is!\n");
    printf("Please enter your password:\n");
    scanf("%s", password);

    int length = strlen(password);
    int score = 0;

    if(length < 6) {
        printf("Your password is too short, it needs to be at least 6 characters long!\n");
        return 0;
    }

    for(int i = 0; i < length; i++) {
        char c = password[i];
        if(isdigit(c)) {
            score += 2;
        }
        else if(isalpha(c)) {
            score++;
        }
        else {
            score += 3;
        }
    }

    if(score >= 10) {
        printf("Bravo! Your password is very strong! Score: %d\n", score);
    }
    else if(score >= 7) {
        printf("Good job! Your password is strong enough. Score: %d\n", score);
    }
    else {
        printf("Uh oh! Your password is weak. Score: %d\n", score);
    }

    return 0;
}