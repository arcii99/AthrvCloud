//FormAI DATASET v1.0 Category: Text processing ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
    char poem[1000];
    printf("Enter your heartfelt poem:\n");
    fgets(poem, 1000, stdin);

    int len = strlen(poem);

    //Romantic processing
    for (int i = 0; i < len; i++) {
        if (poem[i] >= 97 && poem[i] <= 122) {
            //Convert lowercase characters to uppercase
            poem[i] = poem[i] - 32;

            //Convert vowels to hearts
            if (poem[i] == 'A' || poem[i] == 'E' || poem[i] == 'I' || poem[i] == 'O' || poem[i] == 'U') {
                printf("<3");   
            }
            else {
                printf("%c", poem[i]);
            }
        }
        else if (poem[i] >= 65 && poem[i] <= 90) {
            //Convert uppercase characters to lowercase
            poem[i] = poem[i] + 32;

            //Convert vowels to hearts
            if (poem[i] == 'a' || poem[i] == 'e' || poem[i] == 'i' || poem[i] == 'o' || poem[i] == 'u') {
                printf("<3");
            }
            else {
                printf("%c", poem[i]);
            }
        }
        else {
            printf("%c", poem[i]);
        }
    }

    return 0;
}