//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculate_checksum(const char* data, int length);
void print_checksum(unsigned char* checksum);

int main() {
    char input[1000];
    int length;
    printf("Enter the data: ");
    scanf("%s", input);
    length = strlen(input);

    int checksum = calculate_checksum(input, length);
    unsigned char checksum_arr[2];
    memcpy(checksum_arr, &checksum, 2);

    printf("The checksum is: ");
    print_checksum(checksum_arr);
    return 0;
}

int calculate_checksum(const char* data, int length) {
    int checksum = 0;
    for(int i = 0; i < length; i++) {
        checksum += (int)data[i];
    }
    return ~(checksum & 0xff);
}

void print_checksum(unsigned char* checksum) {
    printf("%02X %02X\n", checksum[0], checksum[1]);
}