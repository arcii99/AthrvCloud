//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: future-proof
#include<stdio.h>

int main(){
    char input[100];
    int checksum = 0;
    
    printf("Enter a string: ");
    scanf("%s", input);
    
    for(int i=0; input[i]!='\0'; i++){
        checksum += input[i];
    }
    
    printf("\nThe checksum value is: %d", checksum);

    return 0;
}