//FormAI DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
#include<stdio.h>
#include<string.h>

int main(){
    printf("O Romeo, wherefore art thou binary?\n");
    printf("Shall I compare thee to a summer's day?\n");
    printf("Thou art more lovely and temperate.\n");
    printf("Rough winds do shake the darling buds of May,\n");
    printf("And summer's lease hath all too short a date.\n");
    printf("Sometime too hot the eye of heaven shines,\n");
    printf("And often is his gold complexion dimmed;\n");
    printf("But thy eternal summer shall not fade\n");
    printf("Nor lose possession of that fair thou owest;\n");
    printf("Nor shall Death brag thou wander'st in his shade\n\n");

    printf("My dear Juliet, let me show you\n");
    printf("How to convert decimal numbers to binary, anew:\n");
    printf("Please enter the decimal number you want to convert:\n");

    int decimal_number, remainder, quotient, i = 1, j;
    char binary_number[100];

    scanf("%d", &decimal_number);

    quotient = decimal_number;

    while (quotient != 0){
        remainder = quotient % 2;
        binary_number[i++] = remainder + '0';
        quotient = quotient / 2;
    }

    printf("\nYour decimal number %d in binary is: ", decimal_number);

    for(j = i -1 ; j> 0 ; j--){
        printf("%c", binary_number[j]);
    }

    printf("\n\nOh sweet Romeo, you have opened my mind\n");
    printf("To the wonders of binary, I now find.\n");
    printf("Thank you for showing me this, my love,\n");
    printf("I will treasure your gift, like the stars above.\n");
    
    return 0;
}