//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Sherlock Holmes
/*
 * "I have always been on the side of the law"
 * said Sherlock Holmes
 *
 * Here is a secure password generator 
 * program written by me, Holmes!
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PASSWORD_LENGTH 12
#define NUM_SPECIAL_CHARS 3

const char upper_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char lower_chars[] = "abcdefghijklmnopqrstuvwxyz";
const char digits[] = "0123456789";
const char special_chars[] = "!@#$%^&*()_+~`|}{[]:;?><,./-=";

int main(void)
{
    int i;
    char password[PASSWORD_LENGTH + 1];
    int num_upper_chars = 0, num_lower_chars = 0, num_digits = 0, num_special_chars = 0;
    srand((unsigned int)time(NULL));

    // Generate the password
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        switch (rand() % 4) {
            case 0:
                // Generate upper case character
                password[i] = upper_chars[rand() % (sizeof(upper_chars) - 1)];
                num_upper_chars++;
                break;

            case 1:
                // Generate lower case character
                password[i] = lower_chars[rand() % (sizeof(lower_chars) - 1)];
                num_lower_chars++;
                break;

            case 2:
                // Generate digit
                password[i] = digits[rand() % (sizeof(digits) - 1)];
                num_digits++;
                break;

            default:
                // Generate special character
                if (num_special_chars < NUM_SPECIAL_CHARS) {
                    password[i] = special_chars[rand() % (sizeof(special_chars) - 1)];
                    num_special_chars++;
                    break;
                }
                // Fall through if there have been enough special characters generated
            case 3:
                // Generate another digit
                password[i] = digits[rand() % (sizeof(digits) - 1)];
                num_digits++;
                break;
        }
    }

    // Add null terminator to the end of the password string
    password[PASSWORD_LENGTH] = '\0';

    // Ensure that all character classes are included in the password
    if (num_upper_chars == 0 || num_lower_chars == 0 || num_digits == 0 || num_special_chars < NUM_SPECIAL_CHARS) {
        // If not, generate a new password
        return main();
    }

    printf("Your password is: %s\n", password);
    return 0;
}