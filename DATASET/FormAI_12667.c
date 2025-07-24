//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

// struct to represent a watermark
typedef struct watermark {
    char name[50];
    char message[100];
} watermark;

// function to create a watermark
watermark create_watermark(char *name, char *message) {
    watermark wm;
    strcpy(wm.name, name);
    strcpy(wm.message, message);
    return wm;
}

// function to print a watermark
void print_watermark(watermark wm) {
    printf("Watermark Name: %s\n", wm.name);
    printf("Watermark Message: %s\n", wm.message);
}

int main() {
    char name[50];
    char message[100];

    // get input from user for watermark name and message
    printf("Enter watermark name (max 50 characters): ");
    fgets(name, 50, stdin);
    printf("Enter watermark message (max 100 characters): ");
    fgets(message, 100, stdin);

    // create a watermark object
    watermark wm = create_watermark(name, message);

    // print the watermark
    print_watermark(wm);

    return 0;
}