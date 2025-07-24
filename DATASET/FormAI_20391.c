//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Ada Lovelace
/* Ada Lovelace Style C Password Strength Checker */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[50];
    int upright = 0, lowercase = 0, digit = 0, special = 0, length = 0, score = 0;
    int upper_weight = 4, lower_weight = 2, digit_weight = 3, special_weight = 5;

    printf("Enter your password (Maximum of 50 characters): ");
    fgets(password, 50, stdin);

    length = strlen(password) - 1;

    /* Check password categories */
    for(int i = 0; i < length; i++) {
        if(isupper(password[i]))
            upright++;
        else if(islower(password[i]))
            lowercase++;
        else if(isdigit(password[i]))
            digit++;
        else
            special++;
    }

    /* Calculate password score */
    score = (upright * upper_weight) + (lowercase * lower_weight) + (digit * digit_weight) + (special * special_weight);

    /* Checking Passwrod strength
     * 0 - Weak; 1 - Moderate; 2 - Strong; 3 - Very Strong
     */
    if(length < 8 || score < 30)
        printf("Password strength is weak.\n");
    else if((length < 12 && score < 40) || (length < 8 && score >= 30))
        printf("Password strength is moderate.\n");
    else if((length >= 12 && score < 50) || (length < 12 && score >= 40))
        printf("Password strength is strong.\n");
    else
        printf("Password strength is very strong.\n");

    return 0;
}