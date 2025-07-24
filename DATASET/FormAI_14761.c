//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: romantic
#include <stdio.h>

int main() {
    printf("Honey, let me show you my love in hexadecimal.\n");

    char *message = "I love you more than 0x2A cats";
    printf("Original message: %s\n", message);
    printf("Hexadecimal representation: ");
    for (int i = 0; message[i]; i++) {
        printf("%02X ", message[i]);
    }
    printf("\n");

    printf("I feel hexadecimal digits dancing in my heart when I am with you.\n");
    printf("Let us convert a number in decimal format to hexadecimal.\n");
    printf("Please enter a number: ");
    int decimal;
    scanf("%d", &decimal);
    printf("Hexadecimal representation: %X\n", decimal);

    printf("My love for you is %X times stronger than yesterday.\n", 0x1D);
    printf("In hexadecimal, your eyes are %X and your smile is %X.\n", 0xABC, 0xDEF);

    printf("Finally, let me ask you a question in hexadecimal notation.\n");
    printf("Will you be my forever love? (0x59/0x4E): ");
    char answer_hex[3];
    scanf("%s", answer_hex);
    if (answer_hex[0] == '5' && answer_hex[1] == '9') {
        printf("Yes! Your answer in decimal is %d.\n", 0x59);
    } else {
        printf("Oh no! Your answer in decimal is %d.\n", 0x4E);
    }

    printf("Thank you for being the 0xA5 in my life. I love you always.\n");

    return 0;
}