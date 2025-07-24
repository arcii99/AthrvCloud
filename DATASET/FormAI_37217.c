//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: genious
#include <stdio.h>
#include <string.h>

void scanFile(char fileName[]) {
    FILE *file;
    char virus[] = "malware"; // substitute with desired virus name

    file = fopen(fileName, "rb");

    if (!file) {
        printf("ERROR: Failed to open file.\n");
        return;
    }

    unsigned char buffer[1024];
    int readSize;
    int virusFound = 0;

    while ((readSize = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < readSize - strlen(virus); i++) {
            int j;
            for (j = 0; j < strlen(virus); j++) {
                if (buffer[i + j] != virus[j]) {
                    break;
                }
            }

            if (j == strlen(virus)) {
                virusFound = 1;
                break;
            }
        }
        if (virusFound) {
            printf("Virus '%s' found in file '%s'.\n", virus, fileName);
            break;
        }
    }

    fclose(file);

    if (!virusFound) {
        printf("No viruses found in file '%s'.\n", fileName);
    }
}

int main() {
    char fileName[] = "example.txt"; // substitute with desired file name
    scanFile(fileName);
    return 0;
}