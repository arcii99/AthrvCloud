//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: future-proof
#include <stdio.h>
#include <string.h>

int main() {

    char c_input[] = "Meow Meow Purrr";
    char c_output[1000];
    int i, j, k, len_input;

    char* c_name[] = {"Meow", "Purrr", "Hiss", "Scratch", "Fish", "Mouse", "Furry", "Whiskers", "Tail"};
    char* c_sound[] = {"Meeow", "Purrr", "Hissss", "Scraaatch", "Fiiish", "Squeak", "Furr", "Whiskers", "Tail"};

    len_input = strlen(c_input);
    j = 0;
    k = 0;

    for (i = 0; i < len_input; i++) {
        if (c_input[i] == ' ') {
            c_output[j] = ' ';
            j++;
            k = 0;
            continue;
        }

        if (c_input[i] >= 65 && c_input[i] <= 90) {
            c_input[i] = c_input[i] + 32;
        }

        for (int m = 0; m < 9; m++) {
            if (strncmp(c_name[m], &c_input[i], strlen(c_name[m])) == 0) {
                strcpy(&c_output[j], &c_sound[m]);
                j += strlen(c_sound[m]);
                k = strlen(c_name[m]);
                break;
            }
        }

        if (k == 0) {
            c_output[j] = c_input[i];
            j++;
        }

        i += k - 1;
    }

    c_output[j] = '\0';

    printf("Cat language translation: %s\n", c_output);

    return 0;
}