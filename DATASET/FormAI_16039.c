//FormAI DATASET v1.0 Category: File Encyptor ; Style: high level of detail
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define KEY 7 //Encryption key

int main() 
{ 
    FILE *fp1, *fp2; 
    char ch, input_file[20], output_file[20];
    
    printf("Enter name of file to encrypt: "); 
    scanf("%s", input_file);
    
    printf("Enter name of output file: "); 
    scanf("%s", output_file);
    
    fp1 = fopen(input_file, "r"); //Open file to encrypt 
    if (fp1 == NULL) {
        printf("Error opening file\n"); 
        exit(1); 
    } 
    
    fp2 = fopen(output_file, "w"); //Open output file to write encrypted data 
    if (fp2 == NULL) {
        printf("Error opening file\n"); 
        exit(1); 
    } 
  
    while ((ch = fgetc(fp1)) != EOF) { //Encrypt file data character by character using the key 
        ch = ch + KEY;
        fputc(ch, fp2);
    } 
    
    fclose(fp1); //Close input file 
    fclose(fp2); //Close output file
  
    printf("\nFile encrypted successfully.\n"); 
    return 0; 
}