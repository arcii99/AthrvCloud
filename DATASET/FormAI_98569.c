//FormAI DATASET v1.0 Category: Word Count Tool ; Style: satisfied
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[1000], ch;
    int count = 0;
    
    printf("Enter a string: ");
    gets(str);
    
    printf("Enter a character to count: ");
    scanf("%c", &ch);
    
    for(int i = 0; str[i] != '\0'; i++) {
        if(tolower(str[i]) == tolower(ch))
            count++;
    }
    
    printf("The character '%c' appears %d times in the string.", ch, count);
    
    return 0;
}