//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: grateful
#include <stdio.h>

int main() {

    char input[100]; 
    int sum = 0; //initialize the sum variable to zero

    printf("Enter a message to generate its checksum: ");
    scanf("%s", input);

    for(int i=0; input[i]!='\0'; i++) {
        sum += input[i]; //add up the ASCII values of each character in the message
    }

    int checksum = 255 - (sum % 256); //calculate the checksum value

    printf("The checksum value is %d\n", checksum);

    return 0;
}