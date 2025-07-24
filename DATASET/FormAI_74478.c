//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: thoughtful
#include <stdio.h>
#include <math.h>

int main(void) {
    char password[50];
    int password_length, lower_count=0, upper_count=0, digit_count=0, special_count=0, score=0;

    printf("Enter the password: ");
    fgets(password, 50, stdin);

    // Calculate the password length
    password_length = strlen(password)-1;

    // Check for lowercase, uppercase, digits and special characters
    for(int i=0; i<password_length; i++) {
        if(islower(password[i]))
            lower_count++;
        else if(isupper(password[i]))
            upper_count++;
        else if(isdigit(password[i]))
            digit_count++;
        else
            special_count++;
    }

    // Calculate the password strength score
    score += password_length * 4;
    score += (upper_count + lower_count == password_length) ? 0 : ((password_length-upper_count-lower_count) * 2);
    score += (digit_count >= 1) ? ((digit_count >= password_length/2) ? 20 : 10) : 0;
    score += (special_count >= 1) ? 20 : 0;

    // Determine the password strength rating
    if(score >= 80)
        printf("Password strength: Excellent\n");
    else if(score >= 60)
        printf("Password strength: Strong\n");
    else if(score >= 40)
        printf("Password strength: Moderate\n");
    else if(score >= 20)
        printf("Password strength: Weak\n");
    else
        printf("Password strength: Very weak\n");

    return 0;
}