//FormAI DATASET v1.0 Category: File handling ; Style: bold
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file_ptr;
    char name[20], address[50], phone[15];
    
    file_ptr = fopen("contact_list.txt", "a"); // opening file in append mode
    
    if (file_ptr == NULL) { // checking if file opened successfully
        printf("Error opening file!");
        exit(1);
    }
    
    printf("Enter Name: ");
    gets(name); // input name using gets() function
    fprintf(file_ptr, "Name: %s\n", name); // writing name to file
    
    printf("Enter Address: ");
    gets(address); // input address using gets() function
    fprintf(file_ptr, "Address: %s\n", address); // writing address to file
    
    printf("Enter Phone Number: ");
    gets(phone); // input phone number using gets() function
    fprintf(file_ptr, "Phone Number: %s\n", phone); // writing phone number to file
    
    // closing the file after writing data
    fclose(file_ptr);
    
    printf("\nData Written Successfully to File!");
    
    return 0;
}