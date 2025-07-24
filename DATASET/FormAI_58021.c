//FormAI DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
// Romeo and Juliet: A Binary Love Story
//
// In fair Verona, where we lay our scene,
// Two lovers, each with a number so keen.
//
// With blushing cheeks and ardent hearts,
// They converse in code, with binary parts.
//
// Romeo, whose number is 1110,
// Declares his love to Juliet, with words aplenty.
// "My sweetest Juliet, fairest of all,
// Your beauty is like a binary thrall."
//
// Juliet, with her number 0101,
// Returns his affection with equal devotion.
// "Dearest Romeo, my truest knight,
// Your love is like a binary delight."
//
// Together, they combine their numbers,
// As their love grows stronger, without any slumbers.
//
// The C program below, converts decimal to binary,
// A testament to their love, so pure and fiery.

#include <stdio.h>

// Decimal to Binary function
void decToBin(int num) {
    int binary[32], i = 0;
    while (num > 0) {
        binary[i] = num % 2;
        num /= 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

int main() {
    int romeoNum = 14;
    int julietNum = 5;

    printf("In fair Verona, where we lay our scene,\n");
    printf("Two lovers, each with a number so keen.\n\n");

    printf("Romeo, whose number is %d,\n", romeoNum);
    printf("Declares his love to Juliet, with words aplenty.\n");
    printf("\"My sweetest Juliet, fairest of all,\n");
    printf("Your beauty is like a binary thrall.\"\n\n");

    printf("Juliet, with her number %d,\n", julietNum);
    printf("Returns his affection with equal devotion.\n");
    printf("\"Dearest Romeo, my truest knight,\n");
    printf("Your love is like a binary delight.\"\n\n");

    printf("Together, they combine their numbers,\n");
    printf("As their love grows stronger, without any slumbers.\n\n");

    printf("Romeo's number %d in binary is: ", romeoNum);
    decToBin(romeoNum);
    printf("\n");

    printf("Juliet's number %d in binary is: ", julietNum);
    decToBin(julietNum);
    printf("\n");

    printf("Their combined number in binary is: ");
    decToBin(romeoNum + julietNum);
    printf("\n");

    printf("A testament to their love, so pure and fiery.\n");
    return 0;
}