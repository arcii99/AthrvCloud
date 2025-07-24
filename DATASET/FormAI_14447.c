//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: real-life
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX_SIZE 10000

int main(){

    char text[MAX_SIZE], watermark[MAX_SIZE], watermarked_text[MAX_SIZE];
    int text_len, watermark_len, i, j;

    printf("Enter the text: ");
    fgets(text, MAX_SIZE, stdin);

    printf("Enter the watermark: ");
    fgets(watermark, MAX_SIZE, stdin);

    text_len = strlen(text);
    watermark_len = strlen(watermark);

    // Embedding watermark into text
    j = 0;
    for(i=0; i<text_len; i++){
        if(text[i] != ' ' && text[i] != '\n' && text[i] != '\r'){
            watermarked_text[j++] = text[i];
            watermarked_text[j++] = watermark[i%watermark_len];
        }else{
            watermarked_text[j++] = text[i];
        }
    }
    watermarked_text[j] = '\0';

    printf("Text after embedding watermark: %s\n", watermarked_text);

    // Extracting watermark from watermarked text
    j = 0;
    for(i=0; i<text_len; i++){
        if(watermarked_text[i] != ' ' && watermarked_text[i] != '\n' && watermarked_text[i] != '\r'){
            watermark[j++] = watermarked_text[i+1];
        }
    }
    watermark[j] = '\0';

    printf("Extracted watermark: %s\n", watermark);

    return 0;
}