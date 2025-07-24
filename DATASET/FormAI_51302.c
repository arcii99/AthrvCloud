//FormAI DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>

int main(){
    // Welcome message
    printf("Hello there! Let's write some data to a file.\n");

    // Declare file pointer and file name
    FILE *fp;
    char filename[20] = "myfile.txt";

    // Open file in write mode and check for errors
    fp = fopen(filename, "w");
    if(fp == NULL){
        printf("Error opening file.\n");
        return 1;
    }

    // Write some data to the file and close it
    fprintf(fp, "This is some data that we are writing to the file!\n");
    fprintf(fp, "We can write multiple lines of data as well.\n");
    fclose(fp);

    // Re-open the file in read mode and check for errors
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error opening file.\n");
        return 1;
    }

    // Read each line of the file and print it to the console
    char buffer[100];
    while(fgets(buffer, 100, fp) != NULL){
        printf("%s", buffer);
    }

    // Close the file and print a closing message
    fclose(fp);
    printf("\nAll done! Check %s for the data.\n", filename);

    return 0;
}