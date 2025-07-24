//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASS_LENGTH 20

int main()
{
    char password[PASS_LENGTH + 1];
    int i, r;
    srand(time(NULL));
    
    printf("Welcome to the Secure Password Generator!\n\n");
    printf("Your new password is: ");
    
    for (i = 0; i < PASS_LENGTH; i++) {
        r = rand() % 3;
        switch (r) {
            case 0:
                password[i] = 'A' + rand() % 26;
                break;
            case 1:
                password[i] = 'a' + rand() % 26;
                break;
            case 2:
                password[i] = '0' + rand() % 10;
                break;
        }
    }
    
    password[PASS_LENGTH] = '\0';
    printf("%s", password);
    
    printf("\n\nWe recommend that you write it down someplace safe!");
    
    return 0;
}