//FormAI DATASET v1.0 Category: QR code generator ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<qrencode.h> // Library for generating QR Codes

int main(){
    char data[100]; // the data we want to encode
    QRcode *code;
    
    printf("Enter the data to be encoded: ");
    scanf("%s",data);
    
    code = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1); // Generating QR Code
    
    FILE *fp; // File pointer
    fp = fopen("QRCode.svg", "w"); // opening file in write mode
    
    fprintf(fp,"<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\">\n", code->width+10, code->width+10);
    fprintf(fp,"<rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" fill=\"white\"/>\n", code->width+10, code->width+10);
    for(int i=0;i<code->width;i++){
        for(int j=0;j<code->width;j++){
            if(code->data[i*code->width+j]&1){
               fprintf(fp,"<rect x=\"%d\" y=\"%d\" width=\"1\" height=\"1\" fill=\"black\"/>\n",j+5,i+5);
            }
        }
    }
    fprintf(fp,"</svg>");
    fclose(fp);
    
    printf("QR Code generated successfully!!\n");
    return 0;
}