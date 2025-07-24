//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    char filename[50];
    FILE *fp;

    while(1) { // Shape-shifting loop
        printf("\nWelcome to the C Checksum Calculator!\n");
        printf("Select an option:\n");
        printf("1. Calculate checksum\n");
        printf("2. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Calculate checksum
                printf("Enter the filename: ");
                scanf("%s", filename);

                fp = fopen(filename, "rb");
                if(fp == NULL) {
                    printf("Error: File could not be opened.\n");
                    break;
                }

                unsigned long long checksum = 0;
                int byte;
                while((byte = fgetc(fp)) != EOF) {
                    checksum += byte;
                }

                printf("Checksum: %llu\n", checksum);
                
                fclose(fp);
                break;
            case 2: // Exit
                printf("Goodbye!\n\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}