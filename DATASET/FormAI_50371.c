//FormAI DATASET v1.0 Category: String manipulation ; Style: satisfied
#include<stdio.h>
#include<string.h>

void reverse(char* str) {
    int len = strlen(str);
    for(int i=0; i<len/2; i++) {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

int main() {
    char input[100], choice;
    printf("Enter a string: ");
    fgets(input, 100, stdin); // Taking input using fgets for better string handling
    printf("\nThe original string is: %s", input);
    
    do {
        printf("\nChoose an operation:\n1.Reverse the string.\n2.Count the number of vowels.\n3.Replace all spaces with underscores.\n4.Exit.\n");
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                reverse(input);
                printf("\nThe string after reversing is: %s", input);
                break;
            case '2': {
                int count = 0;
                for(int i=0; i<strlen(input); i++) {
                    char c = input[i];
                    if(c=='a' || c=='A' || c=='e' || c=='E' || c=='i' || c=='I' || c=='o' || c=='O' || c=='u' || c=='U') {
                        count++;
                    }
                }
                printf("\nThe number of vowels in the string is: %d", count);
                break;
            }
            case '3':
                for(int i=0; i<strlen(input); i++) {
                    if(input[i]==' ') {
                        input[i] = '_';
                    }
                }
                printf("\nThe string after replacing spaces with underscores is: %s", input);
                break;
            case '4':
                printf("\nGoodbye!");
                break;
            default:
                printf("\nPlease enter a valid choice!");
        }
    } while(choice!='4');
    return 0;
}