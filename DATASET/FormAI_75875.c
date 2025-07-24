//FormAI DATASET v1.0 Category: Error handling ; Style: creative
#include <stdio.h>

int main() {
    FILE *file_pointer = fopen("text_file.txt", "r");
    if(file_pointer == NULL)
    {
        printf("Error: Could not open file!\n");
        return -1;
    }
    char text[100];
    while(fgets(text, 100, file_pointer) != NULL)
    {
        printf("%s", text);
    }
    if(feof(file_pointer))
    {
        printf("End of file reached successfully!\n");
    }
    else if(ferror(file_pointer))
    {
        printf("Error: Failed to reach end of file!\n");
    }

    fclose(file_pointer);

    return 0;
}