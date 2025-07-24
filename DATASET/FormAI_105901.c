//FormAI DATASET v1.0 Category: Ebook reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {
  while (1) {
    printf("Welcome to the eReader program. Please select an option: \n");
    printf("1. Upload ebook\n");
    printf("2. Download ebook\n");
    printf("3. Delete ebook\n");
    printf("4. Exit program\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        // Code to upload ebook
        break;
      case 2:
        // Code to download ebook
        break;
      case 3:
        // Code to delete ebook
        break;
      case 4:
        printf("Exiting program.\n");
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  }

  return 0;
}