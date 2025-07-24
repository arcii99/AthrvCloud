//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

#define LENGTH 12

int main(void) {
    char password[LENGTH+1], c;
    int valid = 0, i, num_count = 0, lower_count = 0, upper_count = 0, pass_count = 0;

    srand(time(NULL)); //Seeding random number generator with current time

    while (!valid) { //Loop until a valid password is generated
        for (i = 0; i < LENGTH; i++) {
            int rand_num = rand() % 3;
            if (rand_num == 0 && num_count < 3) { //Adding a number
                password[i] = rand() % 10 + '0';
                num_count++;
            } else if (rand_num == 1 && upper_count < 3) { //Adding an uppercase letter
                password[i] = rand() % 26 + 'A';
                upper_count++;
            } else if (lower_count < 3) { //Adding a lowercase letter
                password[i] = rand() % 26 + 'a';
                lower_count++;
            } else { //Adding a special character
                password[i] = rand() % 15 + 33;
            }
        }

        pass_count++;

        //Checking if password meets requirements
        for (i = 0; i < LENGTH; i++) {
            c = password[i];
            if (isdigit(c)) {
                num_count++;
            } else if (isupper(c)) {
                upper_count++;
            } else if (islower(c)) {
                lower_count++;
            } else {
                if (!(c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&'
                        || c == '*' || c == '(' || c == ')' || c == '-' || c == '+' || c == '='
                        || c == '{' || c == '}' || c == '[' || c == ']' || c == '|' || c == '/'
                        || c == ':' || c == ';' || c == '<' || c == '>' || c == '?' || c == '.')) {
                    break;
                }
            }
        }

        if (num_count < 3 || upper_count < 3 || lower_count < 3) {
            num_count = upper_count = lower_count = 0;
            continue;
        } else {
            valid = 1;
            printf("Password %d: %s\n", pass_count, password);
        }
    }

    return 0;
}