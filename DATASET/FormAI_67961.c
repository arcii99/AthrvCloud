//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* surreal function to generate checksum */
int surreal_checksum(int n)
{
    int num, temp, remainder, result = 0;

    num = n;

    while (num != 0)
    {
        temp = num % 10;
        remainder = temp % 2;
        result += remainder;
        num /= 10;
    }

    return result;
}

/* main function for surreal checksum calculator */
int main(){
    char input[100];
    int i, sum=0;

    printf("Welcome to the Surrealist Checksum Calculator!\n\n");
    printf("Please enter a string to calculate the surreal checksum: ");
    scanf("%s", input);

    for(i=0; i<strlen(input); i++){
        int ascii_value = (int)input[i]; /* convert the character to its ASCII value */
        
        sum += surreal_checksum(ascii_value); /* add the surreal checksum of ASCII value to sum */
    }

    printf("The surreal checksum of the input string is: %d\n", sum);
    printf("Thank you for using the Surrealist Checksum Calculator!\n");

    return 0;
}