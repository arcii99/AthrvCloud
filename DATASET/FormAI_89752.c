//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Romeo and Juliet
#include<stdio.h>
#include<string.h>

int main() {

    // Opening the files to synchronize

    FILE *file1 = fopen("file1.txt","r");
    FILE *file2 = fopen("file2.txt","r");

    // Reading the data from the files

    char data1[100], data2[100];
    fscanf(file1, "%[^\n]", data1);
    fscanf(file2, "%[^\n]", data2);

    // Closing the files

    fclose(file1);  
    fclose(file2);  

    // Concatenating the data from both files

    strcat(data1, data2);
    
    // Writing the concatenated data to both files

    file1 = fopen("file1.txt", "w");
    file2 = fopen("file2.txt", "w");

    fprintf(file1, "%s\n", data1);
    fprintf(file2, "%s\n", data1);

    // Closing the files

    fclose(file1);  
    fclose(file2);
    
    // Printing success message

    printf("My love for you is like a file synchronizer, we will always be in sync.\n");
    return 0;
}