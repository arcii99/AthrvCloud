//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
    char data[100];
    int checksum = 0;
    
    printf("Welcome to the Checksum Calculator!\n");
    printf("Please enter the data you would like to calculate the checksum for:\n");
    fgets(data, 100, stdin);
    
    int i;
    for (i = 0; i < strlen(data); i++) {
        checksum += (int) data[i];
    }
    
    printf("The checksum for %s is: %d\n", data, checksum);
    
    return 0;
}