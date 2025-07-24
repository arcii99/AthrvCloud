//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: configurable
#include <stdio.h>
#include <string.h>

// the config struct contains the checksum parameters
typedef struct {
    int algorithm; // 0 for simple sum, 1 for bitwise XOR
    int initialValue;
} ChecksumConfig;

// function to calculate checksum based on input and config
int calculateChecksum(char* input, ChecksumConfig config) {
    int checksum = config.initialValue;
    if (config.algorithm == 0) {
        // simple sum algorithm
        for (int i = 0; i < strlen(input); i++) {
            checksum += (int) input[i];
        }
    } else {
        // bitwise XOR algorithm
        for (int i = 0; i < strlen(input); i++) {
            checksum ^= (int) input[i];
        }
    }
    return checksum;
}

int main() {
    // example usage with config
    char input[256];
    printf("Enter input string: ");
    fgets(input, 255, stdin);
    
    ChecksumConfig config;
    config.algorithm = 1;
    config.initialValue = 0;
    
    int checksum = calculateChecksum(input, config);
    
    printf("Checksum: %d\n", checksum);
    
    return 0;
}