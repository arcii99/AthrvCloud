//FormAI DATASET v1.0 Category: Color Code Converter ; Style: systematic
#include <stdio.h>
#include <string.h>

int main()
{
    char input[8];

    printf("Enter a color code: ");
    scanf("%s", input);

    if (strlen(input) != 6)
    {
        printf("Invalid color code.\n");
        return 0;
    }

    unsigned int r, g, b;
    sscanf(input, "%02x%02x%02x", &r, &g, &b);

    printf("Color code: #%s\n", input);
    printf("RGB values: (%d, %d, %d)\n", r, g, b);

    return 0;
}