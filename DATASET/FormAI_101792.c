//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
    // Greetings, noble user.
    printf("Hail and well met! I am the Metadata Extractor, ready to serve thee.\n");

    // Prompt user for file name.
    printf("Pray tell, what be the name of the file thou dost wish to extract metadata from?\n");
    char file_name[256];
    fgets(file_name, 256, stdin);
    file_name[strcspn(file_name, "\n")] = 0;

    // Open the file.
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Verily, I could not open the file %s. Please check that the name be correct and thou hast the proper permissions.\n", file_name);
        return 1;
    }

    // Retrieve the file size.
    fseek(file, 0L, SEEK_END);
    int file_size = ftell(file);
    printf("Methinks the file size is %d bytes.\n", file_size);

    // Retrieve the file creation date.
    fseek(file, 0L, SEEK_SET);
    char date[256];
    fgets(date, 256, file);
    printf("The file was created on %s.\n", date);

    // Close the file.
    fclose(file);

    // Fare thee well, noble user!
    printf("I hope my humble service doth please thee. Until we meet again!\n");

    return 0;
}