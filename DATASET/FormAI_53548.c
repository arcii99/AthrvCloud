//FormAI DATASET v1.0 Category: QR code generator ; Style: detailed
#include <stdio.h>  
#include <stdlib.h>    
#include <qrencode.h>   

int main()  
{  
    char dataToEncode[1000];
    QRcode *qr;  
      
    printf("Enter the data to be encoded:");  
    fgets(dataToEncode, 1000, stdin);  
    
    qr = QRcode_encodeString(dataToEncode, 0, QR_ECLEVEL_M, QR_MODE_8, 1);  
      
    printf("QR Code Generated Successfully!\n");  
    printf("Saving QR Code as QR.png ...\n");  
    
    FILE *fp = fopen("QR.png", "wb");  
    fwrite(qr->data, sizeof(unsigned char), qr->width * qr->width, fp);  
    fclose(fp);  
    
    QRcode_free(qr);  
    return 0;  
}