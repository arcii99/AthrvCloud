//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: imaginative
#include <stdio.h>

// Function to check if a file is infected with virus or not
int isInfected(char* filename) {
    FILE *fileptr;
    char buffer[1000];
    int isVirus = 0;

    fileptr = fopen(filename, "r");
    if (fileptr == NULL){
        return 1;
    }

    // Read in small chunks until file is fully scanned or virus signature is detected
    while(!feof(fileptr)){
        size_t numBytesRead = fread(buffer, sizeof(char), sizeof(buffer), fileptr);

        // Check for virus signature in buffer
        for(int i=0; i<numBytesRead-5; i++){
            if(buffer[i]=='v' && buffer[i+1]=='i' && buffer[i+2]=='r' && buffer[i+3]=='u' && buffer[i+4]=='s'){
                isVirus = 1;
                break;
            }
        }

        // If virus is detected, stop scanning the file further
        if(isVirus){
            break;
        }
    }

    fclose(fileptr);

    return isVirus;
}

int main() {
    // List of files to be scanned for viruses
    char files[5][50] = {"file1.txt", "file2.doc", "file3.pdf", "file4.exe", "file5.xlsx"};

    for(int i=0; i<5; i++){
        if(isInfected(files[i])){
            printf("%s is infected with virus.\n", files[i]);
        } else {
            printf("%s is not infected with virus.\n", files[i]);
        }
    }

    return 0;
}