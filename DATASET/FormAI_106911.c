//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: inquisitive
#include <stdio.h>
#include <string.h>

void count_frequency(char *str) {
    int frequency[26] = {0};
    int length = strlen(str);
    int i;
    for(i = 0; i < length; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            frequency[str[i] - 'a']++;
        }
    }
    printf("Letter Frequency in String:\n");
    for(i = 0; i < 26; i++) {
        if(frequency[i] > 0) {
            printf("%c : %d\n", i+'a', frequency[i]);
        }
    }
    return;
}

int main() {
    char str[50];
    printf("Enter a string (max 50 characters): ");
    scanf("%[^\n]s", str);
    count_frequency(str);
    return 0;
}