//FormAI DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file_pointer;
    char file_name[20] = "happy_file.txt";
    char text[100] = "I am a happy file! :)";
    
    file_pointer = fopen(file_name, "w");
    if(file_pointer == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    
    fprintf(file_pointer, "%s", text);
    fclose(file_pointer);
    
    file_pointer = fopen(file_name, "r");
    if(file_pointer == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    
    char ch;
    printf("Contents of the file: ");
    while((ch = fgetc(file_pointer)) != EOF) {
        printf("%c", ch);
    }
    
    fclose(file_pointer);
    
    printf("\nYay! We wrote and read a happy file successfully :)");
    return 0;
}