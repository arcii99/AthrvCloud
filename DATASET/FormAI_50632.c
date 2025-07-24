//FormAI DATASET v1.0 Category: QR code reader ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

// Recursive function to find the position of delimiter character
int find_pos(char *str, char del)
{
    if (str[0] == del) {
        return 0;
    }
    else if (str[0] == '\0') {
        return -1;
    }
    else {
        return find_pos(str + 1, del) + 1;
    }
}

// Recursive function to read the QR code 
void read_qr_code(char *qr_str)
{
    char delimiter = '\n';
    int pos = find_pos(qr_str, delimiter);
    if (pos == -1) {
        printf("QR code: %s\n", qr_str);
    }
    else {
        qr_str[pos] = '\0';
        printf("QR code: %s\n", qr_str);
        read_qr_code(qr_str + pos + 1);
    }
}

// Driver program to test the functions
int main()
{
    char qr_code[MAX_SIZE];
    printf("Enter QR code: ");
    scanf("%[^\n]", qr_code);

    read_qr_code(qr_code);

    return 0;
}