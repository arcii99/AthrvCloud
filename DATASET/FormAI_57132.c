//FormAI DATASET v1.0 Category: Ebook reader ; Style: Alan Touring
#include <stdio.h>

int main() {
    printf("Welcome to Ebook Reader!\n");
    
    // read the file path input from the user
    char file_path[100];
    printf("Please enter the file path: ");
    scanf("%s", file_path);
    
    // open the file for reading
    FILE *fp = fopen(file_path, "r");
    if(fp == NULL) {
        printf("File '%s' not found!\n", file_path);
        return 0;
    }
    
    // read the book content line by line and print to the screen
    char line[1000];
    while(fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    
    // close the file and exit the program
    fclose(fp);
    printf("\nBook finished. Thank you for reading!");
    return 0;
}