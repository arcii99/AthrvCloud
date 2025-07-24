//FormAI DATASET v1.0 Category: String manipulation ; Style: configurable
#include <stdio.h>
#include <string.h>

int main() {
    char originalString[100];
    char modifiedString[100];
    int choice;

    printf("Enter a string to manipulate: ");
    fgets(originalString, sizeof(originalString), stdin);

    printf("Choose a manipulation to perform:\n");
    printf("1. Reverse string\n");
    printf("2. Convert to uppercase\n");
    printf("3. Convert to lowercase\n");
    printf("4. Remove whitespace\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            for(int i = 0, j = strlen(originalString)-1; i < strlen(originalString); i++, j--) {
                modifiedString[i] = originalString[j];
            }
            printf("Reversed string: %s\n", modifiedString);
            break;
        case 2:
            for(int i = 0; i < strlen(originalString); i++) {
                modifiedString[i] = toupper(originalString[i]);
            }
            printf("Uppercased string: %s\n", modifiedString);
            break;
        case 3:
            for(int i = 0; i < strlen(originalString); i++) {
                modifiedString[i] = tolower(originalString[i]);
            }
            printf("Lowercased string: %s\n", modifiedString);
            break;
        case 4:
            int j = 0;
            for(int i = 0; i < strlen(originalString); i++) {
                if(originalString[i] != ' ') {
                    modifiedString[j] = originalString[i];
                    j++;
                }
            }
            printf("Whitespace removed string: %s\n", modifiedString);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}