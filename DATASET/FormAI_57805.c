//FormAI DATASET v1.0 Category: Data recovery tool ; Style: brave
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    FILE *file_pointer;
    char file_name[50], *recover_data;
    int file_size, i, j;
  
    printf("Enter the name of the file to be recovered (with extension): ");
    scanf("%s", file_name);
  
    file_pointer = fopen(file_name, "rb"); // Open the file in binary mode
  
    if(file_pointer == NULL) {  // File not found 
        printf("\nOops, the file '%s' cannot be opened or does not exist!\n", file_name);
        exit(0); // Terminate the program
    }
  
    fseek(file_pointer, 0, SEEK_END); //Move the file pointer to the end of the file
    file_size = ftell(file_pointer); //Calculate the size of the file
    fseek(file_pointer, 0, SEEK_SET); //Move the file pointer to the beginning of the file
  
    recover_data = (char*) malloc(file_size * sizeof(char)); //Allocate memory for the file data
    fread(recover_data, sizeof(char), file_size, file_pointer); //Read the data from the file
  
    fclose(file_pointer); //Close the file
  
    printf("\nData recovered from the '%s' file successfully!", file_name);
    printf("\nRecovered Data: \n\n");

    //Displaying the recovered data
    for(i=0; i<file_size; i++) {
        if(recover_data[i] == '\0') {
            printf("\n"); //Add newline character after null character
        } 
        else {
            printf("%c", recover_data[i]); //Print the character
        }
    }
  
    free(recover_data); //Free the allocated memory
  
    return 0;
}