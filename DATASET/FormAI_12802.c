//FormAI DATASET v1.0 Category: QR code reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define CODE_SIZE 21 // QR codes are always 21 characters long

void deduce_code(char *code, int *num_digits, int *num_letters) {
    int i;
    *num_digits = 0;
    *num_letters = 0;

    for (i = 0; i < CODE_SIZE; i++) {
        if (code[i] >= '0' && code[i] <= '9') {
            (*num_digits)++;
        }
        else if ((code[i] >= 'A' && code[i] <= 'Z') || (code[i] >= 'a' && code[i] <= 'z')) {
            (*num_letters)++;
        }
        else {
            printf("Hmm, this doesn't look like a QR code. Please try again.\n");
            return;
        }
    }

    if (*num_digits == 4 && *num_letters == 17) {
        printf("Elementary, my dear Watson! This is a valid QR code.\n");
    }
    else {
        printf("It appears this is not a valid QR code. Try again, Watson!\n");
    }
}

int main() {
    char code[CODE_SIZE];
    int num_digits, num_letters;

    printf("Ah, Watson, what have we here? Pray, tell me about this strange cipher.\n");
    printf("It appears to be a sequence of characters, twenty-one in all.\n");
    printf("Do be so kind as to enter the cipher, Watson.\n");

    scanf("%s", code);

    deduce_code(code, &num_digits, &num_letters);

    printf("Hmm, let me think.\n");
    printf("There are %d digits and %d letters in this cipher.\n", num_digits, num_letters);

    return 0;
}