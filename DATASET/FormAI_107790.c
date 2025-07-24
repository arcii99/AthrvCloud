//FormAI DATASET v1.0 Category: Ebook reader ; Style: inquisitive
#include <stdio.h>

void display_menu() {
    printf("Ebook Reader\n");
    printf("1. Open Ebook\n");
    printf("2. Bookmark\n");
    printf("3. Change Font Size\n");
    printf("4. Change Background Color\n");
    printf("5. Exit\n");
}

int main() {
    int choice = 0;
    int font_size = 12;
    int background_color = 0xFFFFFF;

    while (choice != 5) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Opening Ebook...\n");
                break;
            case 2:
                printf("Bookmarking page...\n");
                break;
            case 3:
                printf("Enter font size: ");
                scanf("%d", &font_size);
                printf("Font size changed to %d\n", font_size);
                break;
            case 4:
                printf("Enter background color (in hex): ");
                scanf("%x", &background_color);
                printf("Background color changed to #%06X\n", background_color);
                break;
            case 5:
                printf("Exiting Ebook Reader...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}