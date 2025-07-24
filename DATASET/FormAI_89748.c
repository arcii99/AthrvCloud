//FormAI DATASET v1.0 Category: Ebook reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_FILE_NAME 128
#define MAX_LINE_SIZE 256

void read_file(FILE *file_to_read) {
    char line[MAX_LINE_SIZE];
    while (fgets(line, sizeof(line), file_to_read)) {
        printf("%s", line);
    }
}

int main() {
    char file_name[MAX_FILE_NAME];
    printf("Enter the name of the ebook file you want to read: ");
    scanf("%s", file_name);
    FILE *ebook_file = fopen(file_name, "r");
    if (ebook_file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    char user_choice;
    do {
        printf("\n");
        printf("Choose an option:\n");
        printf("1. Read Ebook\n");
        printf("2. Quit\n");
        printf("Enter choice: ");
        scanf(" %c", &user_choice);
        user_choice = toupper(user_choice);
        switch (user_choice) {
            case '1':
                read_file(ebook_file);
                break;
            case '2':
                printf("Exiting ebook reader...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (user_choice != '2');
    fclose(ebook_file);
    return 0;
}