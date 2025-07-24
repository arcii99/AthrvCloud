//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    srand(time(NULL)); // seed the random number generator with current time
    int length, num_digits, num_symbols, i, j;
    char password[100] = ""; // initialize password as empty string

    // prompt user to enter desired password length and number of digits/symbols
    printf("Enter desired password length (must be at least 6): ");
    scanf("%d", &length);

    printf("Enter number of digits (must be at least 1): ");
    scanf("%d", &num_digits);

    printf("Enter number of symbols (must be at least 1): ");
    scanf("%d", &num_symbols);

    // validate user input
    if (length < 6 || num_digits < 1 || num_symbols < 1) {
        printf("Invalid input. Password length must be at least 6, and number of digits/symbols must be at least 1.\n");
        return 0;
    }

    // generate random letters, digits, and symbols for password
    for (i = 0; i < length; i++) {
        int category = rand() % 3; // choose random category (0=letter, 1=digit, 2=symbol)
        switch (category) {
            case 0:
                password[i] = 'a' + rand() % 26; // random lowercase letter
                break;
            case 1:
                password[i] = '0' + rand() % 10; // random digit
                break;
            case 2:
                char symbols[] = "!@#$%^&*()_+-={}|[]\\:\";'<>,.?/"; // list of possible symbols
                password[i] = symbols[rand() % strlen(symbols)]; // random symbol
                break;
        }
    }

    // ensure at least one digit and symbol are included
    for (j = 0; j < num_digits; j++) {
        int index = rand() % length; // choose random index to insert digit
        while (password[index] >= '0' && password[index] <= '9') { // ensure index doesn't already contain a digit
            index = rand() % length;
        }
        password[index] = '0' + rand() % 10; // insert random digit
    }

    for (j = 0; j < num_symbols; j++) {
        int index = rand() % length; // choose random index to insert symbol
        while ((password[index] >= '0' && password[index] <= '9') || (password[index] >= 'a' && password[index] <= 'z') || (password[index] >= 'A' && password[index] <= 'Z')) { // ensure index doesn't already contain a letter or digit
            index = rand() % length;
        }
        char symbols[] = "!@#$%^&*()_+-={}|[]\\:\";'<>,.?/"; // list of possible symbols
        password[index] = symbols[rand() % strlen(symbols)]; // insert random symbol
    }

    // print generated password
    printf("Your secure password is:\n%s\n", password);

    return 0;
}