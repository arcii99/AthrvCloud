//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LEN 15
#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBERS "0123456789"
#define SYMBOLS "!@#$%^&*()_+~`|}{[]\\:;?><,./-="
#define CHARACTERS LOWERCASE UPPERCASE NUMBERS SYMBOLS

int main() {
    srand(time(NULL));
    char password[PASSWORD_LEN + 1] = "";
    int index;

    for (int i = 0; i < PASSWORD_LEN; i++) {
        index = rand() % (sizeof(CHARACTERS) - 1);
        password[i] = CHARACTERS[index];
    }

    printf("Your new, secure password is: %s\n", password);

    return 0;
}