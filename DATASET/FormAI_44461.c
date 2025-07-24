//FormAI DATASET v1.0 Category: QR code generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generateQRCode(char* data, int length);

int main() {
    char* data = "Hello, World!";
    int length = strlen(data);
    
    generateQRCode(data, length);
    
    return 0;
}

void generateQRCode(char* data, int length) {
    printf("Generating QR Code for data: %s\n", data);
    
    // Step 1: Generate a random seed
    srand(time(NULL));
    int seed = rand();
    
    // Step 2: Generate checksum
    int checksum = 0;
    for(int i = 0; i < length; i++) {
        checksum += data[i];
    }
    
    // Step 3: Merge seed and checksum
    int mergedValue = seed | checksum;
    
    // Step 4: Convert merged value to binary
    int binary[32];
    int i = 0;
    while(mergedValue > 0) {
        binary[i] = mergedValue % 2;
        mergedValue /= 2;
        i++;
    }
    
    // Step 5: Generate QR code using binary
    printf("\nQR Code:\n");
    for(int j = 31; j >= 0; j--) {
        if(binary[j] == 1) {
            printf("# ");
        } else {
            printf(". ");
        }
        if((j+1) % 8 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}