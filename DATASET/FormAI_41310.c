//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_LEN 8
#define MAX_LEN 16
#define NUM_SPECIAL 3
#define NUM_NUMBERS 2

int main() {
    char password[MAX_LEN+1];
    srand(time(NULL));
    int len = rand() % (MAX_LEN-MIN_LEN+1) + MIN_LEN;
    int num_special = 0;
    int num_numbers = 0;

    // generate password
    for (int i=0; i<len; i++) {
        int random = rand()%4;
        if (random==0 && num_special<NUM_SPECIAL) {
            password[i] = "!@#$%^&*"[rand()%8];
            num_special++;
        } else if (random==1 && num_numbers<NUM_NUMBERS) {
            password[i] = '0'+rand()%10;
            num_numbers++;
        } else {
            password[i] = 'a'+rand()%26;
        }
    }

    // add any missing special characters or numbers
    while (num_special<NUM_SPECIAL || num_numbers<NUM_NUMBERS) {
        for (int i=0; i<len; i++) {
            if (num_special<NUM_SPECIAL && !strchr("!@#$%^&*", password[i])) {
                password[i] = "!@#$%^&*"[rand()%8];
                num_special++;
            } else if (num_numbers<NUM_NUMBERS && !isdigit(password[i])) {
                password[i] = '0'+rand()%10;
                num_numbers++;
            }
            if (num_special>=NUM_SPECIAL && num_numbers>=NUM_NUMBERS) {
                break;
            }
        }
    }

	// add null character to end of string
    password[len] = '\0';

    // print password
    printf("Your new password is: %s\n", password);
    return 0;
}