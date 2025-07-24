//FormAI DATASET v1.0 Category: Binary Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

void convert(int dec){
    int i, j, bit;
    int binary[32];
    
    // Convert decimal to binary
    for(i = 0; dec > 0; i++){
        binary[i] = dec % 2;
        dec /= 2;
    }

    // Print binary in reverse order
    printf("Binary equivalent: ");
    for(j = i - 1; j >= 0; j--){
        printf("%d", binary[j]);
    }
    printf("\n");
}

int main(){
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    convert(num);
    return 0;
}