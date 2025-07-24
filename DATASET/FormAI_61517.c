//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *fp;
    int c, i = 0;
    char buffer[1024];

    if((fp = fopen(filename, "rb")) == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    while((c = fgetc(fp)) != EOF && i < 1024) {
        buffer[i++] = (char)c;
    }

    fclose(fp);

    char *virus_signature_1 = "scary_virus_123";
    char *virus_signature_2 = "evil_malware_789";
    char *virus_signature_3 = "deadly_trojan_456";
    char *virus_signature_4 = "nefarious_worm_999";

    if(strstr(buffer, virus_signature_1) != NULL ||
        strstr(buffer, virus_signature_2) != NULL ||
        strstr(buffer, virus_signature_3) != NULL ||
        strstr(buffer, virus_signature_4) != NULL) {
        printf("Warning: Virus detected in file %s\n", filename);
    } else {
        printf("File %s is clean.\n", filename);
    }

    return 0;
}