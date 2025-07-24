//FormAI DATASET v1.0 Category: QR code generator ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <qrencode.h>

int main() {
    char input_string[100];
    QRcode *qr;
    int i, j;
    
    printf("Enter your input string:");
    scanf("%s", input_string);
    
    qr = QRcode_encodeString(input_string, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);
    
    printf("\nQR code generated for the input string %s:\n", input_string);
    
    for(i=0; i<qr->width+4; i++)
        printf("X");
    
    printf("\n");
    
    for(i=0; i<qr->width; i++) {
        printf("X  ");
        for(j=0; j<qr->width; j++) {
            if(qr->data[i*qr->width+j] & 1)
                printf(" ");
            else
                printf("X");
        }
        printf("  X\n");
    }
    
    for(i=0; i<qr->width+4; i++)
        printf("X");
        
    QRcode_free(qr);
    return 0;
}