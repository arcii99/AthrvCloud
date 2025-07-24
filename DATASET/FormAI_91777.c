//FormAI DATASET v1.0 Category: File handling ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int main(){
    
    printf("Wow! I can't believe I am working with files in C!\n");

    FILE *my_file_pointer;
    my_file_pointer = fopen("my_file.txt", "w");

    if(my_file_pointer == NULL){
        printf("Oops! Something went wrong while trying to open the file\n");
        exit(1);
    }

    printf("Hurray! I successfully opened the file!\n");

    fprintf(my_file_pointer, "This is a sample text that I am writing to my file\n");

    printf("Yes! I have written to the file!\n");

    fclose(my_file_pointer);

    printf("Oh my god! I have closed the file!\n");

    my_file_pointer = fopen("my_file.txt", "r");

    if (my_file_pointer == NULL){
        printf("Oops! Something went wrong while trying to read the file\n");
        exit(1);
    }

    printf("Yay! I successfully opened the file for reading!\n");

    char text[100];

    fgets(text, 100, my_file_pointer);

    printf("Wohoo! I read the text from the file: %s\n", text);

    fclose(my_file_pointer);

    printf("Unbelievable! I closed the file again!\n");

    return 0;
}