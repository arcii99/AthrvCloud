//FormAI DATASET v1.0 Category: File Encyptor ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to encrypt the file data 
void encrypt(char* input_file, char* output_file, char* key){
    FILE *ifp, *ofp;
    char data;
  
    // Opening input file in read mode 
    ifp = fopen(input_file, "r");

    // Opening output file in write mode 
    ofp = fopen(output_file, "w");

    // Checking if file opening was successful 
    if (ifp == NULL || ofp == NULL) {
        printf("\nError in file handling!");
        exit(1);
    }

    // Setting the key in the beginning of the output file 
    fprintf(ofp, "%s", key);

    // Encrypting the data by XORing with key 
    while ((data = fgetc(ifp)) != EOF) {
        fputc(data ^ *key++, ofp);

        // Resetting the key to the beginning 
        if (*key == '\0')
            key = key - strlen(key);
    }

    // Closing the file handles 
    fclose(ifp);
    fclose(ofp);
}

// Main function
int main(int argc, char *argv[]){
    char *ifn = argv[1];
    char *ofn = argv[2];
    char *key = argv[3];

    // Check if all 3 arguments are provided 
    if(argc != 4){
        printf("Please enter input file, output file and key as arguments!");
        exit(1);
    }

    // Call the file encryption function 
    encrypt(ifn, ofn, key);

    printf("\nEncryption successfully completed!");
    return 0;
}