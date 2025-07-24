//FormAI DATASET v1.0 Category: QR code reader ; Style: shape shifting
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Function to generate QR code in various shapes
void generateQRCode(char* qrCode[], int shape){
    int row, col, i, j;
    int size = strlen(qrCode[0]);

    switch(shape){
        case 1: //Shifting to Triangle Shape
            for(row = 0; row < size; row++){
                for(col = 0; col <= row; col++){
                    printf("%c ", qrCode[row][col]);
                }
                printf("\n");
            }
            for(row = size-2; row >= 0; row--){
                for(col = 0; col <= row; col++){
                    printf("%c ", qrCode[row][col]);
                }
                printf("\n");
            }
            break;

        case 2: //Shifting to Diamond Shape
            for(i=0; i<size; i++){
                for(j=0; j< size-i; j++){
                    printf(" ");
                }
                for(j=0; j<=i; j++){
                    printf("%c ",qrCode[i][j]);
                }
                printf("\n");
            }
            for(i=size-2; i>=0; i--){
                for(j=0; j<size-i; j++){
                    printf(" ");
                }
                for(j=0; j<=i; j++){
                    printf("%c ", qrCode[i][j]);
                }
                printf("\n");
            }
            break;

        case 3: //Shifting to Hourglass Shape
            for(row = 0; row < size; row++){
                for(col = 0; col < size; col++){
                    if(row <= col && row <= size-col-1) printf("%c ", qrCode[row][col]);
                    else if(row >= col && row >= size-col-1) printf("%c ", qrCode[row][col]);
                    else printf("  ");
                }
                printf("\n");
            }
            break;
        
        default: //Invalid option
            printf("Invalid Shape Option\n");
    }
}

int main(){
    char* qrcode[] = {
        "##  ##",
        "##  ##",
        "######",
        "##  ##",
        "##  ##",
        "##  ##"
    };

    int shapeOption;

    printf("Select Shape Option: \n");
    printf("\t1. Triangle\n");
    printf("\t2. Diamond\n");
    printf("\t3. Hourglass\n");
    
    scanf("%d", &shapeOption);

    generateQRCode(qrcode, shapeOption);

    return 0;
}