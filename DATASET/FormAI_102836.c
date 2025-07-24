//FormAI DATASET v1.0 Category: System administration ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//function to check if a file exist or not
int fileExists(char *filename){
    return access(filename, F_OK);
}

int main(int argc, char *argv[]){
    if (argc < 2){
        printf("Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        exit(1);
    }

    printf("Starting system administration...\n");

    int i;
    for (i=1; i<argc; i++){
        printf("Checking the existence of file %s...", argv[i]);
        if (fileExists(argv[i]) == 0)
            printf("File exists\n");
        else
            printf("File does not exist\n");
    }

    printf("System administration completed successfully!\n");

    return 0;
}