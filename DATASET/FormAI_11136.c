//FormAI DATASET v1.0 Category: String manipulation ; Style: interoperable
#include <stdio.h>
#include <string.h>

int main() {
    char str[100], substr[20], replacement[20], result[100], temporary[100];
    int i, j, k, index, len_str, len_substr, len_replacement, flag = 0;

    printf("Enter a string: ");
    scanf("%[^\n]%*c", str);

    printf("Enter a substring to replace: ");
    scanf("%[^\n]%*c", substr);

    printf("Enter a replacement string: ");
    scanf("%[^\n]%*c", replacement);

    len_str = strlen(str);
    len_substr = strlen(substr);
    len_replacement = strlen(replacement);

    for (i = 0; i < len_str; i++) {
        flag = 0;
        index = i;

        for (j = 0; j < len_substr; j++) {
            if (str[index] == substr[j]) {
                temporary[j] = str[index];
                index++;
            }
            else {
                break;
            }
        }

        if (j == len_substr) {
            flag = 1;
            for (k = 0; k < len_replacement; k++) {
                result[i+k] = replacement[k];
            }

            i = i + (len_substr - 1);
        }

        if (flag == 0) {
            result[i] = str[i];
        }   
    }

    printf("\nOriginal String: %s\n", str);
    printf("Substring to Replace: %s\n", substr);
    printf("Replacement String: %s\n", replacement);
    printf("Resultant String: %s\n", result);

    return 0;
}