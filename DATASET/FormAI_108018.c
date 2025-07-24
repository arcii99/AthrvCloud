//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: excited
#include<stdio.h>
#include<string.h>

void embedWatermark(char message[], char watermark[], char result[]){
    int length = strlen(watermark);
    int counter = 0;
    for(int i=0; i<strlen(message); i++){
        if(counter < length && i%2==0){
            result[i] = watermark[counter];
            counter++;
        }
        else{
            result[i] = message[i];
        }
    }
}

void extractWatermark(char message[], char extracted[]){
    int counter = 0;
    for(int i=0; i<strlen(message); i++){
        if(i%2==0){
            extracted[counter] = message[i];
            counter++;
        }
    }
}

int main(){
    char originalMsg[100];
    char watermark[20];
    printf("Please enter the original message: ");
    gets(originalMsg);
    printf("Please enter the watermark: ");
    gets(watermark);
    char embeddedMsg[strlen(originalMsg)];
    embedWatermark(originalMsg,watermark,embeddedMsg);
    printf("The embedded message is: %s\n", embeddedMsg);
    char extractedWatermark[strlen(watermark)];
    extractWatermark(embeddedMsg,extractedWatermark);
    printf("The extracted watermark is: %s\n", extractedWatermark);
    return 0;
}