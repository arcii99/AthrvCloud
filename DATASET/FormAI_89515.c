//FormAI DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *filePointer;
    char data[50];

    // Opening the file in write mode and writing data to it
    filePointer = fopen("Cheerful_File.txt", "w");
    fprintf(filePointer, "Hello there!\n");
    fprintf(filePointer, "I am a cheerful C file handling program!\n");
    fprintf(filePointer, "Let me tell you a joke:\n");
    fprintf(filePointer, "Why did the tomato turn red? Because it saw the salad dressing!\n");
    fprintf(filePointer, "Okay, okay, one more joke:\n");
    fprintf(filePointer, "Why did the chicken cross the road? To get to the other side!\n");
    fclose(filePointer);

    // Opening the same file in read mode and reading data from it 
    filePointer = fopen("Cheerful_File.txt", "r");
    fgets(data, 50, filePointer);
    printf("%s", data);

    fgets(data, 50, filePointer);
    printf("%s", data);

    fgets(data, 50, filePointer);
    printf("%s", data);

    fgets(data, 50, filePointer);
    printf("%s", data);

    fgets(data, 50, filePointer);
    printf("%s", data);

    fclose(filePointer);

    // Deleting the file after we are done with it
    remove("Cheerful_File.txt");

    return 0;
}