//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: light-weight
#include<stdio.h>
#include<string.h>

int main() {
    char str[100];
    printf("Enter the text to convert to ASCII art:\n");
    fgets(str, sizeof(str), stdin);

    int len = strlen(str);

    printf(" ___ ___ ___ ___ ___ ___ ___ ___ ___ \n");
    printf("|_%c_|_%c_|_%c_|_%c_|_%c_|_%c_|_%c_|_%c_|_%c_|\n",
        str[0], str[1], str[2], str[3], str[4], str[5], str[6], str[7]);

    for (int i = 8; i < len; i += 8) {
        printf("|_%c_|_%c_|_%c_|_%c_|_%c_|_%c_|_%c_|_%c_|\n",
            str[i], str[i+1], str[i+2], str[i+3], str[i+4], str[i+5], str[i+6], str[i+7]);
    }

    return 0;
}