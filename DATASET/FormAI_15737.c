//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_hex(int num);
char dec_to_hex(int dec);
int hex_to_dec(char hex);

int main()
{
    char input[50];
    int dec_num, i;

    printf("Hey there! I'm a humorous hexadecimal converter. Please enter a decimal number: ");
    fgets(input, 50, stdin);
    dec_num = atoi(input);

    printf("Oooh, %d, that's a good one. Let me convert it to hexadecimal for you...\n", dec_num);

    print_hex(dec_num);

    printf("\nWow, that was fun! Let's do it again with a new number. Enter another decimal number (or type exit to quit):\n");

    while (fgets(input, 50, stdin) != NULL) {
        if (strcasecmp(input, "exit\n") == 0) {
            printf("Aww, I guess I'll see you later then. Goodbye!");
            return 0;
        }

        dec_num = atoi(input);

        printf("Awesome, let me work my magic and convert %d to hexadecimal...here it is:\n", dec_num);

        print_hex(dec_num);

        printf("\nThat was amazing, let's do it again! Enter another decimal number (or type exit to quit):\n");

    }

    return 0;
}

void print_hex(int num) {
    char hex[50];
    int i = 0, remainder;

    while (num > 0) {
        remainder = num % 16;
        hex[i] = dec_to_hex(remainder);
        num /= 16;
        i++;
    }

    printf("0x");

    for (i = i-1; i >= 0; i--) {
        printf("%c", hex[i]);
    }
}

char dec_to_hex(int dec) {
    char hex;

    if (dec >= 0 && dec <= 9) {
        hex = dec + '0';
    } else {
        switch (dec) {
            case 10: hex = 'A'; break;
            case 11: hex = 'B'; break;
            case 12: hex = 'C'; break;
            case 13: hex = 'D'; break;
            case 14: hex = 'E'; break;
            case 15: hex = 'F'; break;
        }
    }

    return hex;
}

int hex_to_dec(char hex) {
    int dec;

    if (hex >= '0' && hex <= '9') {
        dec = hex - '0';
    } else {
        switch (hex) {
            case 'A':
            case 'a':
                dec = 10;
                break;
            case 'B':
            case 'b':
                dec = 11;
                break;
            case 'C':
            case 'c':
                dec = 12;
                break;
            case 'D':
            case 'd':
                dec = 13;
                break;
            case 'E':
            case 'e':
                dec = 14;
                break;
            case 'F':
            case 'f':
                dec = 15;
                break;
            default:
                printf("Oops, %c is not a valid hexadecimal digit. Please try again:\n", hex);
                return -1;
        }
    }

    return dec;
}