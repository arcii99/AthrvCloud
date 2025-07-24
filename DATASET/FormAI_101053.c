//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: cheerful
#include<stdio.h>

int main(){
    printf("Welcome to the cheerful C Checksum Calculator!\n");
    printf("Input a string of characters to generate its checksum: ");
    char input[100];
    scanf("%s", input);
    
    int sum = 0;
    int i = 0;
    while(input[i] != '\0'){
        sum += (int)input[i];
        i++;
    }
    
    printf("The checksum of \"%s\" is %d!\n", input, sum);
    printf("Thank you for using the C Checksum Calculator!\n");
    return 0;
}