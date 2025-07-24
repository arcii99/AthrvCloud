//FormAI DATASET v1.0 Category: QR code reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <stdbool.h>

#define MAX_QR_CODE_SIZE 1000

bool is_fixed_pattern(const char *seq) {
    return strstr(seq, "|0000|0100|") == seq || strstr(seq, "|0100|0000|") == seq;
}

bool is_qr_like(const char *seq, size_t size) {
    const char *rtl_seq_end = seq + size - 4;
    return is_fixed_pattern(seq) || is_fixed_pattern(rtl_seq_end);
}

int main(int argc, char **argv) {
    char buffer[MAX_QR_CODE_SIZE];
    size_t length = fread(buffer, sizeof(char), MAX_QR_CODE_SIZE, stdin);

    if (!is_qr_like(buffer, length)) {
        printf("The input is not a valid QR code.\n");
        return -1;
    }

    printf("The input is a valid QR code!\n");

    return 0;
}