//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    char data[100];
    int checksum = 0;
    int c = 0;
    
    printf("Enter the data to generate the checksum:\n");
    fgets(data, sizeof(data), stdin);
    
    while (data[c] != '\n') {
        checksum += data[c];
        c++;
    }
    
    checksum = ~(checksum & 0xFF);
    
    printf("The checksum of the data is: %X\n", checksum);
    
    return 0;
}