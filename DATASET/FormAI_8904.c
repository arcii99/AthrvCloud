//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

unsigned short calculate_checksum(char *data, int length) {
    unsigned int i;
    unsigned short sum = 0;
    
    for (i = 0; i < length; i += 2) {
        sum += (data[i] << 8) + data[i + 1];
        if (sum & 0xFFFF0000) {
            sum &= 0xFFFF;
            sum++;
        }
    }

    if (length % 2 == 1) {
        sum += data[length - 1] << 8;
        if (sum & 0xFFFF0000) {
            sum &= 0xFFFF;
            sum++;
        }
    }

    return ~sum & 0xFFFF;
}

int main() {
    char data[100];
    int length, i;

    printf("Enter data to calculate checksum: ");
    fgets(data, 100, stdin);
    length = strlen(data);
    if (data[length - 1] == '\n') {
        data[length - 1] = '\0';
        length--;
    }

    printf("\nThe data entered is: %s\n", data);
    printf("\nCalculating checksum...\n");
    unsigned short checksum = calculate_checksum(data, length);

    printf("The checksum is: %#04x\n", checksum);
    return 0;
}