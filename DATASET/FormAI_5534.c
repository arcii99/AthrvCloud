//FormAI DATASET v1.0 Category: Binary Converter ; Style: enthusiastic
#include <stdio.h>

int main() {
    unsigned int num;
    int i, j, count = 0;
    char binary[50];
    
    printf("Welcome to the Binary Converter Program!\n");
    printf("Please enter the positive decimal number you wish to convert: ");
    scanf("%u", &num);
    
    if(num == 0) {
        printf("The binary value of 0 is 0.");
        return 0;
    } else {
        while(num > 0) {
            binary[count] = num % 2;
            num /= 2;
            count++;
        }
        
        printf("The binary value of the decimal number is: ");
        for(i = count - 1; i >= 0; i--) {
            printf("%d", binary[i]);
        }
    }
    
    printf("\nGoodbye and happy converting!");
    return 0;
}