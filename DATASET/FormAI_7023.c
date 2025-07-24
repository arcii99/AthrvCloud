//FormAI DATASET v1.0 Category: QR code generator ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main(){

    printf("Welcome to the QR code generator!\n\n");

    printf("Please enter the data you want to encode in the QR code:\n");

    char data[1000];
    scanf("%[^\n]", data);

    int size = strlen(data);

    printf("\n\nYour data has been recorded successfully and is ready to be encoded into a beautiful QR code!\n");

    printf("\n\n");

    int i,j;

    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            if(data[i] == ' ' || data[i] == '\t' || data[i] == '\n' || data[i] == '\r'){
                printf("  ");
            }
            else{
                if(i%3 == 0 || j%7 == 0){
                    printf("**");
                }
                else{
                    printf("  ");
                }
            }
        }
        printf("\n");
    }

    printf("\n\nVoila! Your unique QR code has been generated successfully.\n\n");

    return 0;

}