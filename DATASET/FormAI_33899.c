//FormAI DATASET v1.0 Category: Text processing ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

int count_vowels(char *str) {
    int count = 0;

    for(int i=0; i<strlen(str); i++) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            count++;
        }
    }

    return count;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int vowels = count_vowels(str);

    printf("Number of vowels in \"%s\" is %d\n", str, vowels);

    return 0;
}