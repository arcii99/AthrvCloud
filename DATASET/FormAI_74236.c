//FormAI DATASET v1.0 Category: String manipulation ; Style: calm
#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    int choice, len, i, j;
    char temp;

    printf("Enter a string: ");
    fgets(str, 100, stdin);
    len = strlen(str);

    printf("Options:\n1. Reverse the string\n2. Remove vowels from the string\nEnter your choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1:
            for (i=0, j=len-1; i<j; i++, j--){
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
            printf("Reversed string: %s\n", str);
            break;
        
        case 2:
            for (i=0; i<len; i++){
                if (str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' ||
                    str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U'){
                    for (j=i; j<len; j++)
                        str[j] = str[j+1];
                    len--;
                    i--;
                }
            }
            printf("String without vowels: %s\n", str);
            break;
        
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}