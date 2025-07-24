//FormAI DATASET v1.0 Category: QR code generator ; Style: standalone
#include <qrencode.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    QRcode *code;
    const char *text = "Hello World!"; // Replace this with your text
    
    // Set size, version and level of error correction
    int size = 10;
    int version = 1;
    QRecLevel level = QR_ECLEVEL_L;
    
    // Create QR code
    code = QRcode_encodeString(text, version, level, QR_MODE_8, 1);
    
    // Print QR code as ASCII
    for(int i=0; i<code->width+2; i++)
        printf("##");
    printf("\n");
    for(int i=0; i<code->width; i++) {
        printf("##");
        for(int j=0; j<code->width; j++) {
            if(code->data[i*code->width+j]&1) // Black pixel
                printf("##");
            else // White pixel
                printf("  ");
        }
        printf("##\n");
    }
    for(int i=0; i<code->width+2; i++)
        printf("##");
    printf("\n");
    
    // Free QR code memory
    QRcode_free(code);
    
    return 0;
}