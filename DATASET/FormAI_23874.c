//FormAI DATASET v1.0 Category: File handling ; Style: excited
//Wow! It's time to dive into some file handling! Let's get started with a bang!

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the world of File Handling!\n\n");

    //First, let's create a file pointer and try to open a file using it
    FILE *fp;
    fp = fopen("example.txt", "w+");
    if(fp == NULL) {
        printf("Oh no! Something went wrong while creating the file...\n");
        exit(0);
    }

    //If everything goes well, we will get a message like this
    printf("Yay, the file has been created successfully! :)\n");

    //Now, let's write some text to the file
    int write_status = fprintf(fp, "This is an example text written to the file!");
    if(write_status < 0) {
        printf("Oops, an error occured while writing to the file :(\n");
        exit(0);
    }

    //Let's close the file for now
    fclose(fp);

    //Now, let's try to read from the file
    fp = fopen("example.txt", "r");
    if(fp == NULL) {
        printf("Uh-oh, the file could not be opened for reading :(\n");
        exit(0);
    }

    //Let's read the content of the file and print it to the console
    char file_content[101];
    fgets(file_content, 101, fp);
    printf("The content of the file is: %s\n", file_content);

    //Let's close the file again
    fclose(fp);

    //Finally, let's delete the file
    int delete_status = remove("example.txt");
    if(delete_status == 0) {
        printf("The file has been deleted successfully! :)\n");
    } else {
        printf("Uh-oh, an error occured while deleting the file :(\n");
        exit(0);
    }

    return 0;
}