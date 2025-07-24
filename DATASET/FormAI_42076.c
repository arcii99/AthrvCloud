//FormAI DATASET v1.0 Category: QR code generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    //Initializing variables
    char message[50];
    int x, y;
    
    //Getting user input
    printf("Please enter a romantic message: ");
    fgets(message, sizeof(message), stdin);
    
    printf("Enter x and y coordinates for the QR code: ");
    scanf("%d %d", &x, &y);
    
    //Printing the QR code
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                [%s]\n", message);
    printf("          ***   ***   ***   ***   ***\n");
    printf("         ***** ***** ***** ***** *****\n");
    printf("        *********************************\n");
    printf("        *********         ***************\n");
    printf("        *********   %d,%d   ***************\n", x, y);
    printf("        *********         ***************\n");
    printf("        *********************************\n");
    printf("         ***** ***** ***** ***** *****\n");
    printf("          ***   ***   ***   ***   ***\n");
    
    return 0;
}