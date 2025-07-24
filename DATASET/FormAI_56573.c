//FormAI DATASET v1.0 Category: Data recovery tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 1000

int main() {
    char filename[50];
    printf("Welcome to the Happy Data Recovery Tool!\n\n");
    printf("Please enter the name of the file you want to recover: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Oopsie! The file could not be opened. Have you entered the correct filename? Try again!\n");
        return 1;
    }

    char data[MAX_DATA_SIZE];
    int size = fread(data, sizeof(char), MAX_DATA_SIZE, file);
    if (size == 0) {
        printf("The file is empty. There is nothing to recover. Sorry!\n");
        return 1;
    }

    char recovered_file[50];
    printf("\nCongratulations! The file has been successfully recovered.\n");
    printf("Now, you can save it on your computer.\n");
    printf("Please enter the name of the file you want to save the recovered data in: ");
    scanf("%s", recovered_file);

    FILE *recovered = fopen(recovered_file, "w");
    if (recovered == NULL) {
        printf("Oopsie! The file could not be created. Make sure you have permission to write files in this location.\n");
        return 1;
    }

    fwrite(data, sizeof(char), size, recovered);
    printf("\nHooray! The recovered data has been saved in the file \"%s\".\n", recovered_file);
    printf("Thank you for using the Happy Data Recovery Tool. Have a nice day!\n");

    fclose(file);
    fclose(recovered);

    return 0;
}