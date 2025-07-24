//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: portable
#include <stdio.h>
#include <string.h>

int main() {
    char password[64];
    int len, uppercase = 0, lowercase = 0, digits = 0, symbols = 0;

    printf("Enter Password: ");
    scanf("%[^\n]%*c", password);

    len = strlen(password);

    for(int i = 0; i < len; i++) {
        if(password[i] >= 'A' && password[i] <= 'Z')
            uppercase++;
        else if(password[i] >= 'a' && password[i] <= 'z')
            lowercase++;
        else if(password[i] >= '0' && password[i] <= '9')
            digits++;
        else
            symbols++;
    }

    int score = (len*4) + (uppercase*2) + (digits*4) + (symbols*6);

    if(uppercase == 0 || lowercase == 0 || digits == 0)
        printf("Weak Password\n");
    else if(score >= 100)
        printf("Strong Password\n");
    else if(score >= 80)
        printf("Medium Password\n");
    else
        printf("Weak Password\n");

    return 0;
}