//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Watermark {
    char text[100];
    int xpos;
    int ypos;   
};

void printWatermark(struct Watermark wm) {
    printf("\n\nWatermark Text: %s", wm.text);
    printf("\nX position: %d", wm.xpos);
    printf("\nY position: %d", wm.ypos);
}

int main() {
    printf("Welcome to Digital Watermarking Example Program!");
    printf("\n\nPlease enter a text to be watermarked: ");
    char input[100];
    fgets(input, 100, stdin);

    struct Watermark wm;
    strcpy(wm.text, input);

    printf("\nPlease enter the X position of the watermark (0-100): ");
    scanf("%d", &wm.xpos);
    printf("\nPlease enter the Y position of the watermark (0-100): ");
    scanf("%d", &wm.ypos);

    printWatermark(wm);

    printf("\n\nDo you want to make changes to the watermark?\n1. Yes\n2. No\n");
    int option;
    scanf("%d", &option);

    if(option == 1) {
        printf("\nPlease enter the new X position of the watermark (0-100): ");
        scanf("%d", &wm.xpos);
        printf("\nPlease enter the new Y position of the watermark (0-100): ");
        scanf("%d", &wm.ypos);

        printWatermark(wm);
    }

    return 0;
}