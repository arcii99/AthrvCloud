//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Digital Watermarking program.\n");
    
    char watermark[50];
    char message[1000];
    
    printf("Please enter your watermark: ");
    scanf("%s", watermark);
    
    printf("Please enter your message: ");
    scanf("%s", message);
    
    int watermarkLength = strlen(watermark);
    int messageLength = strlen(message);
    
    int i = 0;
    int j = 0;
    
    for (i = 0; i < messageLength; i++) {
        if (j == watermarkLength) {
            j = 0;
        }
        
        message[i] = message[i] ^ watermark[j];
        
        j++;
    }
    
    printf("Your watermarked message is: %s\n", message);
    
    printf("To extract the watermark, please enter your watermarked message: ");
    scanf("%s", message);
    
    int newWatermarkLength = 0;
    char newWatermark[50];
    
    for (i = 0; i < messageLength; i++) {
        if (j == watermarkLength) {
            j = 0;
        }
        
        newWatermark[j] = message[i] ^ watermark[j];
        
        j++;
    }
    
    newWatermarkLength = strlen(newWatermark);
    
    printf("Your extracted watermark is: %s\n", newWatermark);
    
    printf("Thank you for using the Digital Watermarking program.\n");
    
    return 0;
}