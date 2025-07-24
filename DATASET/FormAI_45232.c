//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100], watermark[100];

    printf("Enter the input text: ");
    scanf("%[^\n]", input);

    printf("Enter the watermark text: ");
    scanf(" %[^\n]", watermark);

    int i, j = 0, k = 0;
    char output[100];

    for(i=0; i<strlen(input); i++) {
        if(input[i] == ' ' && j < strlen(watermark)) {
            output[k] = watermark[j];
            j++;
            k++;
        }
        output[k] = input[i];
        k++;
    }

    while(j < strlen(watermark)) {
        output[k] = watermark[j];
        j++;
        k++;
    }

    printf("\nWatermarked text: %s\n", output);

    return 0;
}