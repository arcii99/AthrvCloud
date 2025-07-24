//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: surprised
#include <stdio.h>
#include <string.h>

// function to scan file for viruses
int scan_file(char* filename) {
    FILE* fileptr;
    char buffer[100];
    char virus_signature[] = "malware";
    int counter = 0;
    fileptr = fopen(filename,"rb");
    while(fgets(buffer, sizeof(buffer), fileptr)!= NULL) {
        if(strstr(buffer, virus_signature) != NULL){
            printf("Virus found in file!\n");
            return 1;
        }
        counter++;
        if(counter > 100){
            break;
        }
    }
    fclose(fileptr);
    printf("File is safe!\n");
    return 0;
}

int main() {
    char filename[100];

    printf("Enter filename to scan: ");
    scanf("%s", filename);

    // check if file exists
    FILE* temp = fopen(filename, "r");
    if (temp == NULL) {
        printf("Error: File does not exist!\n");
        return 1;
    }
    fclose(temp);

    // scan file for viruses
    scan_file(filename);

    return 0;
}