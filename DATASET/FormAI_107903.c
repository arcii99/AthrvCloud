//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char virusName[50];
    char md5[33];
} virus_definition;

int scan_file(char* fname, virus_definition *viruses, int num_viruses) {
    char buffer[100];
    FILE *fp;
    int bytes_read, i, j;
    fp = fopen(fname, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", fname);
        return 0;
    }

    bytes_read = fread(buffer, 1, sizeof(buffer), fp);
    while (bytes_read > 0) {
        for (i=0; i<num_viruses; i++) {
            if (bytes_read < strlen(viruses[i].md5) * 2)
                continue;
            for (j=0; j<bytes_read - strlen(viruses[i].md5) * 2; j++) {
                if (memcmp(&buffer[j], viruses[i].md5, strlen(viruses[i].md5)) == 0) {
                    printf("Virus detected: %s\n", viruses[i].virusName);
                    return 1;
                }
            }
        }
    }

    fclose(fp);
    return 0;
}

int main(int argc, char *argv[]) {
    virus_definition viruses[] = {
        {"T4-FlappyBird", "0ac011699d007b19bc818c70b171a1cc"},
        {"Trojan.Malware", "b0198c40fd4e42e6cb34961ea553fef1"},
        {"T2-Breakout", "c944f60cc89edf471e1c36fb47b2f52a"},
        {"CryptoLocker", "c0ece709a9f3432eec8ca590d975ef9e"}
    };
    int num_viruses = 4;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int result = scan_file(argv[1], viruses, num_viruses);
    if (result == 0) {
        printf("No viruses detected\n");
    }

    return 0;
}