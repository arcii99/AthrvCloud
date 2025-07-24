//FormAI DATASET v1.0 Category: Image Editor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_SIZE 256
#define MAX_FORMAT_SIZE 8
#define MAX_MENU_OPTIONS 4

void print_menu(void);
int get_option(void);
void open_file(char *filename, char *format);
void process_file(char *filename, char *format);
void save_file(char *filename, char *format);

void print_menu(void) {
    printf("Welcome to the Image Editor.\n");
    printf("1. Open an image.\n");
    printf("2. Process the image.\n");
    printf("3. Save the edited image.\n");
    printf("4. Exit.\n\n");
}

int get_option(void) {
    char option[2];

    printf("Select an option: ");
    fgets(option, 2, stdin);
    fflush(stdin);

    return atoi(option);
}

void open_file(char *filename, char *format) {
    printf("Enter the name of the image file: ");
    fgets(filename, MAX_FILENAME_SIZE, stdin);
    fflush(stdin);

    printf("Enter the format of the image (jpeg, png, bmp, etc.): ");
    fgets(format, MAX_FORMAT_SIZE, stdin);
    fflush(stdin);

    printf("File '%s' opened successfully in '%s' format.\n\n", filename, format);
}

void process_file(char *filename, char *format) {
    printf("Processing the file '%s'...\n\n", filename);
    // Provide the image processing logic here.
}

void save_file(char *filename, char *format) {
    char new_filename[MAX_FILENAME_SIZE];

    printf("Enter a new name for the edited image file: ");
    fgets(new_filename, MAX_FILENAME_SIZE, stdin);
    fflush(stdin);

    printf("Saving the edited file '%s'...\n\n", new_filename);
    // Provide the image saving logic here.
}

int main(void) {
    char filename[MAX_FILENAME_SIZE];
    char format[MAX_FORMAT_SIZE];
    int option;

    do {
        print_menu();
        option = get_option();

        switch (option) {
        case 1:
            open_file(filename, format);
            break;

        case 2:
            process_file(filename, format);
            break;

        case 3:
            save_file(filename, format);
            break;

        case 4:
            printf("Exiting Image Editor...\n\n");
            break;

        default:
            printf("Invalid option selected. Please try again.\n\n");
            break;
        }

    } while (option != MAX_MENU_OPTIONS);

    return 0;
}