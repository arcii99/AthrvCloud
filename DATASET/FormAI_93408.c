//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1000

int main(){
    char content[MAXSIZE], watermark[MAXSIZE];
    printf("Enter the content to be watermarked:\n");
    fgets(content, MAXSIZE, stdin);
    printf("Enter the watermark:\n");
    fgets(watermark, MAXSIZE, stdin);

    int contentLen = strlen(content);
    int wLen = strlen(watermark);

    if(wLen > MAXSIZE || wLen > contentLen || wLen < 2){
       printf("Watermark length error, cannot proceed!\n");
       return 0;
    }

    int i, offset = 0;
    for(i = 0; i < wLen; i++){
        offset += (int) watermark[i];
    }
    offset = offset % contentLen;
    printf("Offset: %d\n", offset);

    for(i = 0; i < wLen; i++){
        content[offset + i] = watermark[i];
    }

    printf("Watermarked content: %s", content);
    return 0;
}