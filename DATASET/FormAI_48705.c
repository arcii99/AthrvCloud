//FormAI DATASET v1.0 Category: QR code generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char data[100];
    int version;
} QRCode;

int main()
{
    QRCode my_code;
    char input[100];
    int i, j, len, sum;
    int poly[] = {0, 251, 67, 46, 61, 118, 70, 64, 94, 32, 45, 108, 21, 23, 1};
    printf("Enter data for QR code (up to 100 characters): ");
    fgets(input, 100, stdin);
    len = strlen(input);
    if (input[len - 1] == '\n')
        input[len - 1] = '\0';
    strcpy(my_code.data, input);
    my_code.version = 1;
    for (i = 0; i < len; i++)
    {
        sum = (int)my_code.data[i];
        for (j = 0; j < 15; j++)
            sum = ((sum << 1) ^ ((sum >> 7) * poly[j]));
        sum = (sum % 256) ^ 0xAA;
        my_code.data[i] = (char)sum;
    }
    printf("Generated QR code: ");
    printf("[data]: %s\n", my_code.data);
    printf("[version]: %d\n", my_code.version);
    return 0;
}