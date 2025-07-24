//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: medieval
#include <stdio.h>
#include <string.h>

int main()
{
    char word[100];
    int length, i, flag = 0;

    printf("Hear ye, hear ye! I, the Palindrome Checker, shall check if thine word be a true palindrome!\n");
    printf("Enter thy word: ");
    scanf("%s", word);

    length = strlen(word);

    for(i=0; i < length ;i++){
        if(word[i] != word[length-i-1]){
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("Verily, thy word \"%s\" is naught but a mere imposter, for it is not a true palindrome. \n", word);
    }    
    else {
        printf("Behold, thy word \"%s\" is a true and noble palindrome! Thou hast done well! \n", word);
    }

    return 0;
}