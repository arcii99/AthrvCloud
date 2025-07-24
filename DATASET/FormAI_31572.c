//FormAI DATASET v1.0 Category: String manipulation ; Style: immersive
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int i = 0;
  
    printf("Enter a string: ");
    scanf("%[^\n]", str);
  
    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
  
    printf("\nUpper case string is: %s", str);

    return 0;
}