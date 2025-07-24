//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sanitize(char url[]);
int validate(char c);

int main()
{
    char url[100];

    printf("Enter URL to sanitize: ");
    fgets(url, 100, stdin);

    sanitize(url);

    printf("\nSanitized URL: %s", url);

    return 0;
}

void sanitize(char url[])
{
    int i, j;

    for(i = 0, j = 0; url[i] != '\0'; i++)
    {
        if(validate(url[i]) == 1)
        {
            url[j++] = url[i];
        }
    }
    url[j] = '\0';
}

int validate(char c)
{
    if(c == 'A' || c == 'a' || c == 'B' || c == 'b' || c == 'C' || c == 'c' || c == 'D' || c == 'd' || c == 'E' || c == 'e' || c == 'F' || c == 'f' || c == 'G' || c == 'g' || c == 'H' || c == 'h' || c == 'I' || c == 'i' || c == 'J' || c == 'j' || c == 'K' || c == 'k' || c == 'L' || c == 'l' || c == 'M' || c == 'm' || c == 'N' || c == 'n' || c == 'O' || c == 'o' || c == 'P' || c == 'p' || c == 'Q' || c == 'q' || c == 'R' || c == 'r' || c == 'S' || c == 's' || c == 'T' || c == 't' || c == 'U' || c == 'u' || c == 'V' || c == 'v' || c == 'W' || c == 'w' || c == 'X' || c == 'x' || c == 'Y' || c == 'y' || c == 'Z' || c == 'z' || c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '/' || c == '.' || c == ':' || c == '-' || c == '_' || c == '~')
    {
        return 1;
    }

    return 0;
}