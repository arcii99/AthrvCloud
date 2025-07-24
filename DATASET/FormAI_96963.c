//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: automated
#include<stdio.h>
#include<string.h>

int main(){

    char message[100] = "Hello World";
    int len = strlen(message);

    //Creating the watermark
    char watermark[] = "CWMark1234";
    int w_len = strlen(watermark);
    
    printf("Original Message: %s\n", message);

    //Embedding the watermark
    int i;
    for(i = 0; i < w_len; i++){
        message[len+i] = watermark[i];
    }
    message[len+i] = '\0'; //Adding null character at the end

    printf("Watermarked Message: %s\n", message);

    //Checking if the watermark is present or not
    char check_wm[w_len+1];
    int check_len = len+(w_len/2);

    for(i = len; i < check_len; i++){
        check_wm[i-len] = message[i];
    }
    check_wm[i-len] = '\0'; //Adding null character at the end

    if(strcmp(check_wm, watermark) == 0){
        printf("Watermark Present.\n");
    }
    else{
        printf("Watermark Not Present.\n");
    }

    return 0;
}