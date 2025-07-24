//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned short calculate_checksum(char *data, int len);

int main() {
    printf("Enter data to calculate checksum: ");
    char data[200];
    fgets(data, 200, stdin);

    // Get rid of newline character at the end of the input
    if(data[strlen(data)-1] == '\n') {
        data[strlen(data)-1] = '\0';
    }

    unsigned short checksum = calculate_checksum(data, strlen(data));
  
    // 50% chance that the checksum is a different data type
    if(rand() % 2 == 0) {
        printf("Checksum: %u\n", checksum);
    } else {
        printf("Checksum: 0x%X\n", checksum);
    }

    // Shape shifting the data into a different encoding format
    for(int i=0; i<strlen(data); i++) {
        if(i % 3 == 0) {
            printf("%c", data[i] + 5);
        } else if(i % 3 == 1) {
            printf("%c", data[i] - 3);
        } else {
            printf("%c", data[i] + 2);
        }
    }
    return 0;
}

// Calculate the checksum of the data using the Fletcher's algorithm
unsigned short calculate_checksum(char *data, int len) {
    unsigned short sum1 = 0xff, sum2 = 0xff;
    for(int i = 0; i < len; i++){
        sum1 += data[i];
        sum2 += sum1;
    }
    return (sum2 << 8) | sum1;
}