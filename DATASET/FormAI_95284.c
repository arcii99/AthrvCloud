//FormAI DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char str[MAX_LEN];
    int option;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Choose an option:\n");
    printf("1. Convert to uppercase\n");
    printf("2. Convert to lowercase\n");
    printf("3. Remove whitespace\n");
    printf("4. Reverse string\n");
    printf("5. Exit\n");

    do {
        printf("\nEnter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                for(int i=0; i < strlen(str); i++) {
                    str[i] = toupper(str[i]);
                }
                printf("Uppercase string: %s\n", str);
                break;
            case 2:
                for(int i=0; i < strlen(str); i++) {
                    str[i] = tolower(str[i]);
                }
                printf("Lowercase string: %s\n", str);
                break;
            case 3:
                int i=0, j=0;
                while(str[i]) {
                    if(str[i] != ' ') {
                        str[j++] = str[i];
                    }
                    i++;
                }
                str[j] = '\0';
                printf("String with whitespace removed: %s\n", str);
                break;
            case 4:
                for(int i=0, j=strlen(str)-1; i<j; i++, j--) {
                    char temp = str[i];
                    str[i] = str[j];
                    str[j] = temp;
                }
                printf("Reversed string: %s\n", str);
                break;
            case 5:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
        
    } while(option != 5);

    return 0;
}