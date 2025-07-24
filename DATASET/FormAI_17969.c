//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: real-life
#include<stdio.h>
#include<string.h>

/* Function to generate digital watermark */
void generateWatermark(char *text, int len, char *watermark){

    /* Initializing the watermark */
    memset(watermark,0,sizeof(watermark));

    /* Loop through the text and generate the watermark */
    for(int i=0; i<len; i++){
        watermark[i] = text[i]+i;      // watermarking algorithm
    }
}

/* Function to verify the digital watermark */
int verifyWatermark(char *watermark, int len, char *text){

    /* Loop through the watermark and verify it */
    for(int i=0; i<len; i++){
        if(watermark[i] != text[i]+i){      // verifying the watermark
            return 0;       // if watermark is tampered return false
        }
    }
    return 1;       // return true if watermark is verified successfully
}

int main(){

    char text[100] = "This is a sample text.";
    char watermark[100];

    /* Generating the digital watermark for the text */
    generateWatermark(text, strlen(text), watermark);

    /* Displaying the generated watermark */
    printf("Generated Watermark : %s\n", watermark);

    /* Tampering the watermark */
    watermark[2] = 'A';

    /* Verifying the tampered watermark */
    if(verifyWatermark(watermark, strlen(text), text)){
        printf("Watermark is verified. Text is not tampered.\n");
    }
    else{
        printf("Watermark is not verified. Text is tampered.\n");
    }

    return 0;
}