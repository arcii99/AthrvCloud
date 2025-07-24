//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>

int calculate_checksum(char *data, int length){
    int sum = 0;
    for (int i = 0; i < length; i++){
        sum += data[i];
    }
    return sum % 256;
}

int main(){
    char data[100];
    int length, checksum;

    // get user input
    printf("Enter data to calculate checksum for: ");
    fgets(data, 100, stdin);
    printf("Enter length of data: ");
    scanf("%d", &length);

    // calculate checksum
    checksum = calculate_checksum(data, length);
    printf("Checksum of data is: %d\n", checksum);

    return 0;
}