//FormAI DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Joyous C File Handling Program!\n\n");

    // Creating a file
    FILE *file = fopen("joyful_file_handling.txt", "w");
    if (file == NULL) 
    {
        printf("Uh oh, the file couldn't be created! Let's try dancing harder!\n");
        exit(1);
    }
    printf("Hooray, we created a new file called joyful_file_handling.txt!\n");

    // Writing to the file
    fprintf(file, "Coding should always be joyful and fun!\n");
    printf("We wrote a joyous message to the file!\n");

    // Reading from the file
    char buffer[100];
    fseek(file, 0, SEEK_SET);
    fgets(buffer, 100, file);
    printf("The file says: %s\n", buffer);

    // Closing the file
    fclose(file);
    printf("We closed the file and are ready to dance some more!\n");

    return 0;
}