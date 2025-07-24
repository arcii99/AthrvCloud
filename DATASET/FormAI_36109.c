//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

unsigned int crc_table[256];

void generate_crc_table(){
    unsigned int crc;
    int i, j;
    for(i = 0; i < 256; i++) {
        crc = i;
        for(j = 0; j < 8; j++){
            if(crc & 1) crc = (crc >> 1) ^ 0xEDB88320;
            else crc >>= 1;
        }
        crc_table[i] = crc;
    }
}

void calculate_crc(char* message, unsigned int message_len, unsigned int* crc_value){
    unsigned int crc = 0xFFFFFFFF;
    unsigned int i;
    for(i = 0; i < message_len; i++) {
        crc = crc_table[(crc ^ message[i]) & 0xFF] ^ (crc >> 8);
    }
    *crc_value = crc ^ 0xFFFFFFFF;
}

int main(){
    generate_crc_table();
    char message[256];
    unsigned int message_len = 0;
    printf("Enter message to calculate CRC: ");
    fgets(message, 256, stdin);
    message_len = strlen(message);
    unsigned int crc_value;
    calculate_crc(message, message_len, &crc_value);
    printf("CRC value is: %d\n", crc_value);
    return 0;
}