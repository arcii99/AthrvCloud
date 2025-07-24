//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

// Define the maximum length of the virus signature
#define MAX_SIGNATURE_LEN 50

// Define the maximum number of virus signatures to be scanned
#define MAX_SIGNATURES_NUM 10

// Define the maximum file size to be scanned in bytes
#define MAX_FILE_SIZE 1000000

// Define the signature struct for virus signature matching
typedef struct
{
    char signature[MAX_SIGNATURE_LEN+1];
    int signature_len;
} Signature;

// Define the virus signature database
Signature signatureDB[MAX_SIGNATURES_NUM];

// Define the virus scanner function
void scanFile(char* fileName)
{
    // Open the file for reading
    FILE* file = fopen(fileName, "r");
    
    // Check if the file opened successfully
    if (file == NULL)
    {
        printf("ERROR: Could not open file %s\n", fileName);
        return;
    }

    // Read the file content into a buffer
    char fileContent[MAX_FILE_SIZE+1];
    size_t bytesRead = fread(fileContent, 1, MAX_FILE_SIZE, file);
    fileContent[bytesRead] = '\0';

    // Close the file
    fclose(file);

    // Check if the file content is empty
    if (bytesRead == 0)
    {
        printf("WARNING: File %s is empty\n", fileName);
        return;
    }

    // Scan the file content for virus signatures
    for (int i=0; i<MAX_SIGNATURES_NUM; i++)
    {
        if (signatureDB[i].signature_len == 0)
            break; // End of the database
        
        if (strstr(fileContent, signatureDB[i].signature) != NULL)
        {
            printf("Virus signature found in file %s: %s\n", fileName, signatureDB[i].signature);
            return; // Stop scanning for other signatures
        }
    }
}

int main()
{
    // Initialize the virus signature database
    strncpy(signatureDB[0].signature, "virus_signature_1", MAX_SIGNATURE_LEN);
    signatureDB[0].signature_len = strlen(signatureDB[0].signature);
    
    strncpy(signatureDB[1].signature, "virus_signature_2", MAX_SIGNATURE_LEN);
    signatureDB[1].signature_len = strlen(signatureDB[1].signature);
    
    // Start scanning the files for virus signatures
    scanFile("file_1.txt");
    scanFile("file_2.txt");
    scanFile("file_3.txt");
    scanFile("file_4.txt");

    return 0;
}