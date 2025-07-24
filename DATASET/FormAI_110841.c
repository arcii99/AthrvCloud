//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

char* toBinary(char message[]){
    int i, j, k;
    char* binary = calloc(MAX_LEN, sizeof(char));
    for(i = 0, k = 0; i < strlen(message); i++){
        int ascii = (int) message[i];
        for(j = 7; j >= 0; j--){
            if(ascii >= (1 << j)){
                ascii -= (1 << j);
                binary[k++] = '1';
            } else {
                binary[k++] = '0';
            }
        }
    }
    return binary;
}

void addWatermark(char watermark[], char* binary, int start){
    int i, j;
    for(i = start, j = 0; j < strlen(watermark); i += 9, j++){
        if(watermark[j] == '1'){
            if(binary[i] == '0'){
                binary[i] = '1';
            } else {
                binary[i] = '0';
            }
        }
    }
}

char* extractWatermark(char* binary, int start, int length){
    int i, j, k;
    char* watermark = calloc(length + 1, sizeof(char));
    for(i = start, j = 0, k = 0; j < length; i += 9, j++){
        if(binary[i] == '1'){
            watermark[k++] = '1';
        } else {
            watermark[k++] = '0';
        }
    }
    return watermark;
}

int main(){

    char message[MAX_LEN];
    char watermark[] = "101101011";
    int watermarkLength = strlen(watermark);
    int start = 45;     // arbitrary value to start adding watermark

    puts("Enter message to encode:");
    fgets(message, MAX_LEN, stdin);
    message[strcspn(message, "\n")] = '\0';

    char* binary = toBinary(message);
    addWatermark(watermark, binary, start);

    // print original message and encoded message with watermark
    printf("Original message:\n%s\n", message);
    printf("Encoded message with watermark:\n");
    int i;
    for(i = 0; i < strlen(binary); i++){
        if(i % 8 == 0 && i != 0){
            printf(" ");
        }
        printf("%c", binary[i]);
    }
    printf("\n");

    char* extractedWatermark = extractWatermark(binary, start, watermarkLength);
    printf("Extracted watermark:\n%s\n", extractedWatermark);

    free(binary);
    free(extractedWatermark);

    return 0;
}