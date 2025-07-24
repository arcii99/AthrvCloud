//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: energetic
#include<stdio.h>

int main()
{   // Print welcome message
    printf("Welcome to the Digital Watermarking program!\n");

    // Get user input
    printf("Please enter the message you want to watermark:\n");
    char message[100];
    scanf("%s", message);

    // Generate watermark
    char watermark[10] = "123456789";

    // Combine message and watermark
    char watermark_msg[110];
    int i, j;

    for(i=0;i<strlen(watermark);i++){
        watermark_msg[i]=watermark[i];
    }
    j=0;
    for(i=strlen(watermark);i<strlen(message)+strlen(watermark);i++){
        watermark_msg[i]=message[j];
        j++;
    }
    watermark_msg[i]='\0';

    // Print watermarked message
    printf("Your watermarked message is: %s\n", watermark_msg);

    return 0;
}