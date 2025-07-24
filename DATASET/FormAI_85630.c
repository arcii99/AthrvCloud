//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: romantic
#include<stdio.h>
#include<string.h>
int main() {
    char password[50];
    int len, i, x=1, y=1, z=1, u=1;
    printf("My heart is like a C program, waiting to be compiled by you.\n");
    printf("Please enter your password my love: ");
    scanf("%s", password);
    len = strlen(password);

    for(i=0; i<len; i++) {
        if((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <= 'Z')) {
            x = 0;
        }
        else if(password[i] >= '0' && password[i] <= '9') {
            y = 0;
        }
        else if(password[i] == '@' || password[i] == '#' || password[i] == '$') {
            z = 0;
        }
        else {
            u = 0;
        }
    }

    if(len < 6) {
        printf("Error: Your Love is too short, my darling. Please enter at least 6 characters for safety.\n");
    }
    if(x == 1) {
        printf("Error: My Love, please include at least one alphabet in your password.\n");
    }
    if(y == 1) {
        printf("Error: Baby, please include at least one number in your password.\n");
    }
    if(z == 1) {
        printf("Error: My Sweetheart, please include at least one of the following symbols in your password - @, #, $.\n");
    }
    if(u == 1) {
        printf("Error: Beloved, please do not use spaces or special characters in your password.\n");
    }

    if(x == 0 && y == 0 && z == 0 && u == 0 && len >= 6) {
        printf("True Love: Congratulations my love! Your password is strong and secure. We can now connect without fear.\n");
    }

    return 0;
}