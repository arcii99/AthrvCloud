//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 16

int main(void) {
    char password[LENGTH + 1] = {0}, symbols[] = "!@#$%^&*()_+-=[]{}|;':\",./<>?\\", c;
    int i, len = 0, numbers = 0, upper = 0, lower = 0, symbol = 0;
    srand(time(NULL)); 

    printf("Your new password is: ");

    while (len < LENGTH || !numbers || !upper || !lower || !symbol) {
        c = rand() % 93 + 33; 
        if (isdigit(c)) numbers = 1; 
        else if (isupper(c)) upper = 1;
        else if (islower(c)) lower = 1;
        else if (strchr(symbols, c)) symbol = 1; 
        password[len++] = c;
    }

    printf("%s\n", password);
    return 0;
}