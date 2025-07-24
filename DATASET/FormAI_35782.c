//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("### HEX CONVERTER 2077 ###\n");
    printf("Enter an integer to convert to hexadecimal: ");
    
    int num;
    scanf("%d", &num);
    
    char hex[10];
    int i = 0;
    
    while(num > 0){
        int rem = num % 16;
        if(rem < 10){
            hex[i] = rem + 48; // ASCII code for 0-9
        }
        else{
            hex[i] = rem + 55; // ASCII code for A-F
        }
        i++;
        num = num / 16;
    }
    
    printf("The hexadecimal value is: ");
    for(int j=i-1; j>=0; j--){
        printf("%c", hex[j]);
    }
    
    printf("\nCYBERPUNK SECURITY PROTOCOLS ENGAGED...\n");
    printf("Generating random hexadecimals...\n");
    
    int rand_nums[10];
    int upperbound = 65536; // 16^4
    srand(time(0));
    
    for(int k=0; k<10; k++){
        rand_nums[k] = rand() % upperbound;
        printf("%d: %X\n", k+1, rand_nums[k]);
    }
    
    printf("### PROGRAM TERMINATED ###\n");
    
    return 0;
}