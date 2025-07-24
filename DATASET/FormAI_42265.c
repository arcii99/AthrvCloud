//FormAI DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
// Romeo and Juliet: A Binary Conversion Tale

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Romeo: Oh Juliet, my love for you is as strong as binary code!\n");
    
    int decimal;
    
    while(1) // loop until user enters 0 to exit
    {
        printf("Juliet: Romeo, my dear, can you convert some binary code for me?\n");
        printf("Romeo: Of course, my love! Please enter a decimal number (enter 0 to exit): ");
        scanf("%d", &decimal);
        
        if(decimal == 0)
        {
            printf("Juliet: Farewell, Romeo.\n");
            break;
        }
        
        int binary[32], i = 0;
        while(decimal > 0) // convert decimal number to binary
        {
            binary[i] = decimal % 2;
            decimal /= 2;
            i++;
        }
        
        printf("Juliet: Oh Romeo, my heart is all aflutter! The binary equivalent of %d is: ", decimal);
        
        for(int j = i - 1; j >= 0; j--) // print binary number
        {
            printf("%d", binary[j]);
        }
        
        printf("\n");
    }
    
    printf("Romeo: Farewell, Juliet. Until next time!\n");
    
    return 0;
}