//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Romeo and Juliet
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char directory_name[100];
    char file_name[100];
    char file_content[100];

    printf("Welcome to the Unix-like Shell program coded in Romeo and Juliet Style! \n");
    printf("Please enter a new directory name: \n");
    scanf("%s", directory_name);
    mkdir(directory_name, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    printf("Directory '%s' created successfully! \n", directory_name);

    printf("Now, let's create a new text file in the directory '%s'.\n", directory_name);
    printf("Please enter file name (including the extension): \n");
    scanf("%s", file_name);
    printf("Please enter file content (maximum of 100 characters): \n");
    scanf("%s", file_content);
    char path[100];
    strcpy(path, "./");
    strcat(path, directory_name);
    strcat(path, "/");
    strcat(path, file_name);
    FILE *fp = fopen(path, "w+");
    fputs(file_content, fp);
    printf("File '%s' created successfully with content: '%s'.\n", file_name, file_content);
    fclose(fp);  
    return 0;
}