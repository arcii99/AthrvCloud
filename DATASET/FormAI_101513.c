//FormAI DATASET v1.0 Category: Ebook reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main() {

    char filename[100];
    FILE *fp;
    int c;
    
    printf("Enter the name of the eBook file: ");
    fgets(filename, 100, stdin);
    
    // check for potential dangerous inputs
    if (filename[0] == '.' && filename[1] == '.') {
        printf("Sorry, you cannot access files in parent directories!\n");
        exit(1);
    } else if (filename[0] == '/' || filename[0] == '\\') {
        printf("Sorry, absolute paths are not allowed!\n");
        exit(1);
    } else if (filename[0] == '~') {
        printf("Sorry, the '~' character is not allowed!\n");
        exit(1);
    }
    
    // check if file extension is .pdf or .epub
    int i;
    for (i = 0; i < 100; i++) {
        if (filename[i] == '\0') {
            printf("Sorry, invalid file type!\n");
            exit(1);
        } else if (filename[i] == '.') {
            if (filename[i+1] == 'p' && filename[i+2] == 'd' && filename[i+3] == 'f') {
                printf("Opening PDF file...\n");
                break;
            } else if (filename[i+1] == 'e' && filename[i+2] == 'p' && filename[i+3] == 'u' && filename[i+4] == 'b') {
                printf("Opening EPUB file...\n");
                break;
            } else {
                printf("Sorry, invalid file type!\n");
                exit(1);
            }
        }
    }
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    printf("Starting eBook reader...\n\n");
    
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }
    
    fclose(fp);

    return 0;
}