//FormAI DATASET v1.0 Category: Data recovery tool ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hello there, welcome to our cheerful C Data Recovery Tool!\n");
    printf("Have you lost important data? Fear not, we can recover it for you!\n");
    
    FILE *file;
    char *file_name = "important_data.txt";
    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Oops, we could not find the file %s. Please check the file path and try again.\n", file_name);
        return 1;
    } else {
        printf("Great news, we found the file %s!\n", file_name);
    }
    
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char *file_content = malloc(file_size);
    fread(file_content, 1, file_size, file);
    
    printf("%s", file_content);
    
    printf("Yay, we successfully recovered your lost data! We hope this puts a smile on your face!\n");
    
    fclose(file);
    free(file_content);
    
    return 0;
}