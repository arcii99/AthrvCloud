//FormAI DATASET v1.0 Category: String manipulation ; Style: synchronous
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100],str3[100], temp[100];

    printf("Enter a string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;

    printf("Entered string is: %s\n", str1);

    //Reversing a string
    int len = strlen(str1);
    for(int i=0;i<len/2;i++){
        temp[i] = str1[i];
        str1[i] = str1[len-i-1];
        str1[len-i-1] = temp[i];
    }
    printf("Reversed string is: %s\n", str1);

    //Converting to upper case
    int i =0;
    while(str1[i]){
        str1[i] = toupper(str1[i]);
        i++;
    }
    printf("Uppercase string is: %s\n", str1);

    //Concatenating two strings
    printf("Enter another string to concatenate: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;

    strcat(str1, str2);
    printf("Concatenated string is: %s\n", str1);

    //Copying a string
    strcpy(str3, str1);
    printf("Copied string is: %s\n", str3);

    //Finding the length of a string
    printf("Length of the string is: %ld\n", strlen(str1));

    //Finding the occurence of a character in a string
    char ch;
    printf("Enter a character to find its occurence: ");
    scanf("%c", &ch);
    int count=0;
    for(int i=0;i<len;i++){
        if(str1[i]==ch){
            count++;
        }
    }
    printf("Occurrence of %c in the string is: %d\n", ch, count);

    return 0;
}