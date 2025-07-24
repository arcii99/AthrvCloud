//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Alan Touring
#include <regex.h>
#include <stdio.h>

int main() {
    char *regex = "^(FREE|BUY NOW|LIMITED TIME OFFER)\\s*[\\w\\s]*\\s*(CLICK HERE|CLAIM NOW|GET IT NOW)$";
    regex_t preg;
    int ret, spam = 0;
    char input[256];
    
    // Compile the regular expression
    if (regcomp(&preg, regex, REG_EXTENDED | REG_NOSUB) != 0) {
        printf("Error compiling regular expression\n");
        return 1;
    }
    
    // Loop to check multiple inputs
    while (1) {
        printf("Enter message: ");
        fgets(input, sizeof(input), stdin);
        
        // End program if input is "quit"
        if (strcmp(input, "quit\n") == 0) {
            break;
        }
        
        // Test regular expression against input
        ret = regexec(&preg, input, 0, NULL, 0);
        if (ret == 0) {
            printf("Message is likely spam.\n");
            spam++;
        } else if (ret == REG_NOMATCH) {
            printf("Message is not spam.\n");
        } else {
            printf("Error testing regular expression\n");
            return 1;
        }
    }
    
    regfree(&preg);
    printf("%d messages detected as spam.\n", spam);
    
    return 0;
}