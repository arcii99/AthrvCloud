//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: artistic
#include <stdio.h>

int main() {
    printf("=======================\n");
    printf("C Checksum Calculator\n");
    printf("=======================\n\n");
  
    int num = 0, checksum = 0, i;
    printf("Enter the number of integers you want to calculate the checksum for: ");
    scanf("%d", &num);
  
    printf("\nEnter the %d integers below:\n", num);
  
    for (i = 0; i < num; i++) {
        int currInt = 0;
        scanf("%d", &currInt);
        checksum = checksum + currInt;
    }
  
    printf("\nThe checksum for the entered integers is: %d\n\n", checksum);
    printf("************************************\n");
    printf("*** Thank you for using our tool! ***\n");
    printf("************************************\n");
  
    return 0;
}