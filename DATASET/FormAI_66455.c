//FormAI DATASET v1.0 Category: String manipulation ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *str = (char *)malloc(sizeof(char) * 100);
    char *temp;
    int len, choice;
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    len = strlen(str);
    printf("\nOriginal string: %s", str);
    while(1) {
        printf("\nChoose an operation:\n1. Reverse the string\n2. Convert to uppercase\n3. Convert to lowercase\n4. Replace a substring\n5. Exit\n");
        scanf("%d", &choice);
        getchar(); // to clear the input buffer
        switch(choice) {
            case 1:
                temp = (char *)malloc(sizeof(char) * (len+1));
                int i, j;
                for(i=0, j=len-1; i<len; i++, j--) {
                    temp[i] = str[j];
                }
                temp[i] = '\0';
                printf("\nReversed string: %s", temp);
                free(temp);
                break;
            case 2:
                for(i=0; i<len; i++) {
                    if(str[i] >= 'a' && str[i] <= 'z') {
                        str[i] = str[i] - 32;
                    }
                }
                printf("\nUppercase string: %s", str);
                break;
            case 3:
                for(i=0; i<len; i++) {
                    if(str[i] >= 'A' && str[i] <= 'Z') {
                        str[i] = str[i] + 32;
                    }
                }
                printf("\nLowercase string: %s", str);
                break;
            case 4:
                char *substr = (char *)malloc(sizeof(char) * 20);
                char *newstr = (char *)malloc(sizeof(char) * 100);
                printf("Enter the substring to replace: ");
                fgets(substr, 20, stdin);
                printf("Enter the new substring: ");
                fgets(newstr, 100, stdin);
                int sublen = strlen(substr);
                int newlen = strlen(newstr);
                for(i=0; i<len; i++) {
                    if(strncmp(&str[i], substr, sublen) == 0) {
                        if(sublen < newlen) {
                            int diff = newlen - sublen;
                            str = (char *)realloc(str, (len+diff+1) * sizeof(char));
                            memmove(&str[i+newlen], &str[i+sublen], len-i-sublen+1);
                            memcpy(&str[i], newstr, newlen);
                            len = len + diff;
                        } else {
                            memmove(&str[i+newlen], &str[i+sublen], len-i-sublen+1);
                            memcpy(&str[i], newstr, newlen);
                        }
                    }
                }
                printf("Modified string: %s", str);
                free(substr);
                free(newstr);
                break;
            case 5:
                exit(0);
            default:
                printf("Please choose a valid option.\n");
        }
    }
    free(str);
    return 0;
}