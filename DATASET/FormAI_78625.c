//FormAI DATASET v1.0 Category: Compression algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to compress a string */
char *compress(char *str)
{
    int i, j, count;
    char *ans = (char *)malloc(sizeof(char) * strlen(str));
    int idx = 0;
    
    for (i = 0; i < strlen(str); i++) {
        count = 0;
        /* Count the number of times a character appears consecutively */
        for (j = i; j < strlen(str) && str[j] == str[i]; j++) {
            count++;
        }
        /* Store the character and its count in the new string */
        ans[idx++] = str[i];
        if (count > 1) {
            char num[10];
            snprintf(num, 10, "%d", count); /* Convert integer to string */
            for (int k = 0; k < strlen(num); k++) {
                ans[idx++] = num[k];
            }
            i = j-1;
        }
    }
    ans[idx] = '\0'; /* Append null character to terminate string */
    return ans;
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    /* Remove newline character */
    if (str[strlen(str)-1] == '\n') {
        str[strlen(str)-1] = '\0';
    }
    
    char *ans = compress(str);
    printf("Compressed string: %s\n", ans);
    free(ans);
    return 0;
}