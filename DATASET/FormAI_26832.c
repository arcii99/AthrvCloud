//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize random seed with the current time

    char password[11]; // password has a maximum length of 10 characters + '\0'
    int num_chars = rand() % 6 + 5; // generate a random number between 5 and 10 for the length of password

    for (int i = 0; i < num_chars; i++) {
        int char_type = rand() % 4; // generate a random number between 0 and 3 to determine the character type
        if (char_type == 0) { // lowercase letter
            password[i] = rand() % 26 + 'a'; // generate a random lowercase letter
        } else if (char_type == 1) { // uppercase letter
            password[i] = rand() % 26 + 'A'; // generate a random uppercase letter
        } else if (char_type == 2) { // digit
            password[i] = rand() % 10 + '0'; // generate a random digit
        } else { // special character
            int special_char_type = rand() % 6;
            if (special_char_type == 0) { // !
                password[i] = '!';
            } else if (special_char_type == 1) { // @
                password[i] = '@';
            } else if (special_char_type == 2) { // #
                password[i] = '#';
            } else if (special_char_type == 3) { // $
                password[i] = '$';
            } else if (special_char_type == 4) { // %
                password[i] = '%';
            } else { // &
                password[i] = '&';
            }
        }
    }
    password[num_chars] = '\0'; // add null terminator to the end of password

    printf("Your cyberpunk secure password is: %s\n", password);

    return 0;
}