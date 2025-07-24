//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Donald Knuth
#include <stdio.h>

int main() {
    char virus[] = "malware";  // define the virus to be detected
    char file[] = "example.exe";  // define the file to be scanned
    FILE *fp;
    char ch;

    fp = fopen(file, "r");  // open the file in read mode

    if (fp == NULL) {  // check if the file exists
        printf("File not found\n");
        return 1;
    }

    int i = 0;  // initialize loop counter for virus detection
    while ((ch = fgetc(fp)) != EOF) {  // read the file character by character
        if (ch == virus[i]) {  // check if the current character matches the virus
            i++;  // increase the counter
            if (i == sizeof(virus) - 1) {  // check if all characters of the virus have been detected
                printf("Virus detected in %s\n", file);
                fclose(fp);  // close the file
                return 1;  // exit the program
            }
        }
        else {
            i = 0;  // reset the counter if there is a mismatch
        }
    }

    printf("No viruses found in %s\n", file);
    fclose(fp);  // close the file

    return 0;  // exit the program
}