//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: immersive
#include <stdio.h>

// Function to convert decimal to hexadecimal
void dec2hex(int num) {
    int rem, i = 0, j, hex[100];

    // loop to convert decimal to hexadecimal
    while(num != 0) {
        rem = num % 16;
        
        // Check if remainder is greater than 9 then convert it to alphabets A-F
        if(rem >= 10)
            hex[i] = rem + 55;
        else
            hex[i] = rem + 48;
            
        num /= 16;
        i++;
    }

    printf("Hexadecimal Equivalent: ");

    // Loop to display hexadecimal equivalent
    for(j = i-1; j >= 0; j--)
        printf("%c", hex[j]);

    printf("\n");
}

int main() {
    int dec_num;

    printf("Enter decimal number: ");
    scanf("%d", &dec_num);

    dec2hex(dec_num);
    
    return 0;
}