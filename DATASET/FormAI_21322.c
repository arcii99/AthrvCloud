//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int input_num;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &input_num);
    
    int arr[input_num];
    printf("Enter the elements of the array: ");
    
    for(int i=0; i<input_num; i++) {
        scanf("%d", &arr[i]);
    }
    
    int checksum = 0;
    
    for(int i=0; i<input_num; i++) {
        checksum += arr[i];
    }
    
    int remainder = checksum % 256;
    int checksum_value = 255 - remainder;
    
    printf("The checksum value is %d", checksum_value);
    
    return 0;
}