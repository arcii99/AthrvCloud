//FormAI DATASET v1.0 Category: Syntax parsing ; Style: innovative
#include<stdio.h>

int main() {
    char c = getchar();

    while(c != EOF) {
        if(c == '/') {
            char c2 = getchar();
            if(c2 == '/') {  // Single line comment
                while(getchar() != '\n') {}  // Ignore rest of the line
            }
            else if(c2 == '*') {  // Multi-line comment
                int flag = 0;
                while(1) {
                    char c3 = getchar();
                    if(c3 == '/') {
                        char c4 = getchar();
                        if(c4 == '*') {  // Nested comment detected
                            flag++;
                        }
                        else if(c4 == '/') {  // End of the comment
                            if(flag == 0) {
                                break;
                            }
                            else {
                                flag--;
                            }
                        }
                    }
                    else if(c3 == '*') {
                        char c4 = getchar();
                        if(c4 == '/') {  // End of the comment
                            if(flag == 0 ) {
                                break;
                            }
                            else {
                                flag--;
                            }
                        }
                    }
                }
            }
            else {  // Character is not a comment
                putchar(c);
                putchar(c2);
            }
        }
        else {  // Character is not a comment
            putchar(c);
        }
        c = getchar();
    }

    return 0;
}