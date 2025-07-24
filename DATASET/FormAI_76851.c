//FormAI DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>

int main(){
    FILE *file_pointer; // declaring a file pointer 
    int count = 0; // to count number of words in a file
    file_pointer = fopen("example.txt","r"); // opening a file in read mode
    
    if(file_pointer == NULL){ // if file is unable to open
        printf("Unable to open file.");
        return 0;
    }
    else{
        printf("File opened successfully\n\n");
    }
    
    // Reading file
    printf("Printing content of the file:\n\n");
    char c;
    while((c = fgetc(file_pointer)) != EOF){ // reading character by character till End of file
        printf("%c", c);
        if(c == ' ' || c == '\n'){ // checking for end of word
            count++;
        }
    }
    printf("\n\nNumber of words in the file: %d", count);
    
    fclose(file_pointer); // closing the file
    
    return 0;
}