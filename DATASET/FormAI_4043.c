//FormAI DATASET v1.0 Category: Ebook reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int ch; 
    FILE *fp = NULL; // file pointer to store ebook data
    char file_name[30]; // string to store ebook file name

    printf("Welcome to C Ebook Reader Program!\n");
    printf("Please enter the file name of the ebook: ");
    scanf("%29s", file_name); // restrict input to avoid buffer overflow
    
    fp = fopen(file_name, "r"); // open ebook file in read-only mode
    
    if (fp != NULL) {
        printf("\nOpening ebook: %s\n\n", file_name);
        
        // read ebook file character by character and output to console
        while ((ch = fgetc(fp)) != EOF) {
            putchar(ch);
        }
        
        fclose(fp); // close ebook file
    } else {
        printf("\nError: Failed to open ebook.\n");
    }
    
    printf("\nThank you for using our Ebook Reader program!\n");
    return 0;
}