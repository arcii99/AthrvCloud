//FormAI DATASET v1.0 Category: Color Code Converter ; Style: funny
#include <stdio.h>

int main() {
    printf("Welcome to the Color Code Converter 5000!🌈\n");
    printf("Enter the hex code of your color: ");
    char hex[7];
    scanf("%s", hex);
    printf("Converting...\n");
    printf("Your color in RGB is: ");
    int r = 0, g = 0, b = 0;
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);
    printf("(%d, %d, %d)\n", r, g, b);
    printf("Do you want to convert to CMYK as well? (y/n) ");

    char choice;
    scanf(" %c", &choice);
    if(choice == 'y' || choice == 'Y') {
        printf("Converting...\n");
        float c, m, y, k;
        c = (255 - r) / 255.0;
        m = (255 - g) / 255.0;
        y = (255 - b) / 255.0;
        k = c < m ? (c < y ? c : y) : (m < y ? m : y);

        c = (c - k) / (1 - k);
        m = (m - k) / (1 - k);
        y = (y - k) / (1 - k);

        printf("Your color in CMYK is: (%.2f, %.2f, %.2f, %.2f)\n", c, m, y, k);
    } else if(choice == 'n' || choice == 'N') {
        printf("Ok then, thank you for using the Color Code Converter 5000!🌈\n");
    } else {
        printf("Sorry, I don't understand. Sounds like you need to learn how to code, haha! Here, have some code:"); // no apology!
        for (int i = 0; i < 50; i++){
            printf("0");
        }
    }

    return 0;
}