//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdint.h>

// function prototypes
uint8_t calculate_checksum(uint8_t *data, uint32_t length);
void print_binary(uint8_t value);

int main(){
    // initialize data array
    uint8_t data[] = {0x3A, 0x01, 0xFF, 0x22, 0x91, 0x05};
    uint32_t length = sizeof(data)/sizeof(data[0]);
    
    // calculate checksum
    uint8_t checksum = calculate_checksum(data, length);
    
    // print results
    printf("Data: ");
    for(int i = 0; i < length; i++){
        printf("0x%02X ", data[i]);
    }
    printf("\nChecksum: ");
    print_binary(checksum);
    printf("\n");
    
    return 0;
}

// function to calculate checksum of data array
uint8_t calculate_checksum(uint8_t *data, uint32_t length){
    uint16_t sum = 0;
    for(int i = 0; i < length; i++){
        sum += data[i];
        if(sum > 0xFF){
            sum -= 0xFF;
        }
    }
    return (uint8_t)sum;
}

// function to print a binary value
void print_binary(uint8_t value){
    for(int i = 7; i >= 0; i--){
        printf("%d", (value >> i) & 1);
    }
}