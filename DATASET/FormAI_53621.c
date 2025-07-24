//FormAI DATASET v1.0 Category: Spell checking ; Style: ephemeral
#include <stdio.h>
#include <string.h>

int main() {

    char input[100];
    printf("Enter a sentence: ");
    fgets(input, 100, stdin);

    char dic[10][20] = {"apple", "banana", "orange", "grape", "lemon",
                        "cherry", "kiwi", "pear", "peach", "melon"};
    int dic_size = 10;

    char* word;
    word = strtok(input, " ,.-\n\0");

    while (word != NULL) {

        int found = 0;

        for (int i = 0; i < dic_size; i++) {
            if (strcmp(word, dic[i]) == 0) {
                found = 1;
                break;
            }
        }

        if (found == 0) {
            printf("Did you mean ");

            int len = strlen(word);
            char temp[len + 1];

            for (int j = 0; j <= len; j++) {
                strcpy(temp, word);
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[j] = c;
                    for (int k = 0; k < dic_size; k++) {
                        if (strcmp(temp, dic[k]) == 0) {
                            printf("%s?", temp);
                            break;
                        }
                    }
                    if (found == 1) break;
                }
                if (found == 1) break;
            }

            if (found == 0) {
                printf("%s?", word);
            }
        }

        printf(" ");
        word = strtok(NULL, " ,.-\n\0");
    }

    printf("\n");

    return 0;
}