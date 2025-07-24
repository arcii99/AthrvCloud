//FormAI DATASET v1.0 Category: File handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    FILE *file_pointer;
    char file_data[MAX_SIZE];

    file_pointer = fopen("poetry.txt", "r"); //open the file in read mode only

    if (file_pointer == NULL) { //if file is not found, exit from program
        printf("Cannot find poetry.txt file.");
        exit(0);
    }

    int line_count = 0;
    while (fgets(file_data, MAX_SIZE, file_pointer) != NULL) {
        line_count++; //increment line count after reading each line
        printf("Line %d: %s", line_count, file_data); //print the line read
    }

    fclose(file_pointer); //close the file

    printf("\n\nLet's get creative!\n\n");

    //write a poem to a new file
    file_pointer = fopen("new_poem.txt", "w"); //open file in write mode

    if (file_pointer == NULL) { //if file is not found, exit from program
        printf("Cannot create new_poem.txt file.");
        exit(0);
    }

    fprintf(file_pointer, "Oh, what a sight to behold!\n"); //write the poem line by line
    fprintf(file_pointer, "The sun sets down in the west\n");
    fprintf(file_pointer, "A blanket of stars unfolds\n");
    fprintf(file_pointer, "The world takes a peaceful rest.\n");

    fclose(file_pointer); //close the file

    printf("A new poem was written and saved to file.\n");

    return 0;
}