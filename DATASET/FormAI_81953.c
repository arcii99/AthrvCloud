//FormAI DATASET v1.0 Category: Text processing ; Style: recursive
#include<stdio.h>
#include<string.h>

void recursive_print(char *str, int i){
    if(str[i] == '\0') return;
    printf("%c", str[i]);
    recursive_print(str, ++i);
}

int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]", str);

    printf("Entered string: %s\n", str);
    printf("String length: %d\n", (int)strlen(str));

    printf("Printing string recursively: ");
    recursive_print(str, 0);
    printf("\n");

    int vowel_count = 0;
    for(int i=0; i < strlen(str); i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
           str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
            vowel_count++;
        }
    }
    printf("Number of vowels in the string: %d\n", vowel_count);

    char reversed_str[100];
    int j = 0;
    for(int i = strlen(str)-1; i >= 0; i--){
        reversed_str[j++] = str[i];
    }
    reversed_str[j] = '\0';

    printf("Reversed string: %s\n", reversed_str);

    return 0;
}