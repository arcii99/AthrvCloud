//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: standalone
#include <stdio.h>

/* calculate checksum of an array */
int calculate_checksum(unsigned char* data, int len)
{
    int i, sum = 0;
    for(i = 0; i < len; i++) {
        sum += data[i];
    }
    return sum & 0xFF;
}

/* calculate checksum of a file */
int calculate_checksum_file(const char* filename)
{
    FILE* fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }
    fseek(fp, 0L, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);
    unsigned char* file_data = malloc(file_size);
    fread(file_data, 1, file_size, fp);
    fclose(fp);
    int checksum = calculate_checksum(file_data, file_size);
    free(file_data);
    return checksum;
}

int main()
{
    int i, len = 6;
    unsigned char data[6] = {0x41, 0x42, 0x43, 0x44, 0x45, 0x46};

    printf("Data:\n");
    for(i = 0; i < len; i++) {
        printf("0x%02X ", data[i]);
    }
    printf("\nChecksum: 0x%02X\n", calculate_checksum(data, len));

    int checksum = calculate_checksum_file("test.txt");
    if(checksum >= 0) {
        printf("Checksum of test.txt: 0x%02X\n", checksum);
    }

    return 0;
}