//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 10240
#define BITS_PER_BYTE 8
#define MESSAGE_LENGTH 50

// Function to calculate the CRC-16 value of a buffer
unsigned short crc16(unsigned char *data, int len) {
    unsigned int i;
    unsigned short crc = 0xffff;
    for (i = 0; i < len; i++) {
        crc ^= (unsigned short)data[i];
        for (unsigned short j = 0; j < BITS_PER_BYTE; j++) {
            if (crc & 0x0001) {
                crc = (crc >> 1) ^ 0x8408;
            } else {
                crc = crc >> 1;
            }
        }
    }
    return crc;
}

// Function to retrieve the timestamp in the format YYYYMMDD_HHMMSS
char *get_timestamp() {
    time_t current_time;
    char *timestamp;
    current_time = time(NULL);
    if (current_time == ((time_t)-1)) {
        return NULL;
    }
    timestamp = (char *)malloc(sizeof(char) * 20);
    strftime(timestamp, 20, "%Y%m%d_%H%M%S", localtime(&current_time));
    return timestamp;
}

int main() {
    char message[MESSAGE_LENGTH];
    unsigned char data[MAX_SIZE];
    unsigned short crc_value;
    char *timestamp;

    printf("Enter message: ");
    memset(message, 0, MESSAGE_LENGTH);
    fgets(message, MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0';

    printf("Enter the filename to embed the digital watermark: ");
    char filename[50];
    memset(filename, 0, 50);
    fgets(filename, 50, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    // Open the file
    FILE *fp = fopen(filename, "rb+");
    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return -1;
    }

    // Read the file into a buffer
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    rewind(fp);
    if (size > MAX_SIZE) {
        printf("Error: File size too large.\n");
        fclose(fp);
        return -1;
    }
    fread(data, sizeof(char), size, fp);
    fclose(fp);

    // Calculate the CRC-16 value of the buffer and prepend it to the message
    crc_value = crc16(data, size);
    sprintf(message, "%04X%s", crc_value, message);
    size += 2;

    // Append the message length to the message
    sprintf(message, "%04X%s", (unsigned short)strlen(message), message);
    size += 2;

    // Append the timestamp to the message
    timestamp = get_timestamp();
    if (timestamp == NULL) {
        printf("Error: Could not get timestamp.\n");
        return -1;
    }
    sprintf(message, "%s%s", timestamp, message);
    size += 15;
    free(timestamp);

    // Write the modified buffer back to the file
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return -1;
    }
    fwrite(data, sizeof(char), size, fp);
    fclose(fp);

    printf("Digital watermark embedded successfully.\n");

    return 0;
}