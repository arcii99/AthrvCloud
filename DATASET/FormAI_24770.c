//FormAI DATASET v1.0 Category: Text processing ; Style: future-proof
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1000

int main() {
    char input[MAX_LEN];
    printf("Enter some text: ");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline char from input
    
    int alpha_count = 0;
    int num_count = 0;
    int space_count = 0;
    int punct_count = 0;
    int upper_count = 0;
    int lower_count = 0;
    
    for (int i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            alpha_count++;
            if (isupper(input[i])) {
                upper_count++;
            } else {
                lower_count++;
            }
        } else if (isdigit(input[i])) {
            num_count++;
        } else if (isspace(input[i])) {
            space_count++;
        } else {
            punct_count++;
        }
    }
    
    printf("Text statistics:\n");
    printf("   - Characters: %d\n", strlen(input));
    printf("   - Alphabetic chars: %d (%d uppercase, %d lowercase)\n", alpha_count, upper_count, lower_count);
    printf("   - Numerals: %d\n", num_count);
    printf("   - Whitespace chars: %d\n", space_count);
    printf("   - Punctuation chars: %d\n", punct_count);
    
    return 0;
}