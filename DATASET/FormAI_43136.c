//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Cryptic
#include <stdio.h>
#include <string.h>

#define VIRUS_SIGNATURE "who_am_i"

int scan_code(const char *code)
{
    char virus_signature[] = VIRUS_SIGNATURE;
    int i, j, k;
    int match = 0;

    for (i = 0; i < strlen(code); i++) {
        if (code[i] == virus_signature[0]) {
            for (j = i, k = 0; k < strlen(virus_signature); j++, k++) {
                if (code[j] != virus_signature[k]) {
                    break;
                } else {
                    match++;
                }
            }
            if (match == strlen(virus_signature)) {
                printf("Virus found!\n");
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    char code[] = "some code with a virus who_am_i";

    if (scan_code(code)) {
        printf("Code is infected with a virus!\n");
    } else {
        printf("Code is clean\n");
    }

    return 0;
}