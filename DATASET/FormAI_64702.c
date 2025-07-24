//FormAI DATASET v1.0 Category: QR code reader ; Style: irregular
#include<stdio.h>

int main(){
    printf("***********QR Code Reader Software***********\n\n");

    //initialize necessary variables
    FILE *qrCodeFile;
    char qrCodeData[100];
    int count = 0, i, j, k;

    //open the QR code file
    qrCodeFile = fopen("qrCode.txt", "r");

    //check if the file exists and can be read
    if(qrCodeFile == NULL){
        printf("Error: Cannot open file.\n\n");
        return 0;
    }

    //read the QR code data into qrCodeData array
    while(fscanf(qrCodeFile, "%s", qrCodeData)!=EOF){
        count++;
    }
    fclose(qrCodeFile);

    //display the QR code data
    printf("QR code data: \n\n");
    for(i = 0; i < count; i++){
        for(j = 0; qrCodeData[j]!=',' && qrCodeData[j]!='\0'; j++){
            printf("%c", qrCodeData[j]);            
        }
        printf("\n");
        if(qrCodeData[j] == '\0')
            break;
        j++;
        for(k = j; qrCodeData[k]!='\0'; k++){
            qrCodeData[k-j] = qrCodeData[k];
        }
        qrCodeData[k-j] = '\0';
    }

    return 0;
}