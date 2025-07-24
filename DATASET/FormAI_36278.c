//FormAI DATASET v1.0 Category: Text processing ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main() {
    char romeo[] = "But, soft! What light through yonder window breaks?\n";
    char juliet[] = "It is the east, and Juliet is the sun.\n";
    char message[100] = "Oh, Romeo, Romeo! Wherefore art thou Romeo?\n";
    char keyword[] = "Romeo";
    char *match;

    // search for keyword in message
    match = strstr(message, keyword); 

    if (match) { // if keyword found in message
        printf("Juliet: %s", juliet);
        printf("Romeo: %s", romeo);
        printf("Juliet: %s", "O Romeo, Romeo! wherefore art thou Romeo?\n");
        printf("Romeo: %s", "Deny thy father and refuse thy name;\n");
        printf("Romeo: %s", "Or, if thou wilt not, be but sworn my love,\n");
        printf("Romeo: %s", "And I'll no longer be a Capulet.\n");
    }
    else { // if keyword not found in message
        printf("Romeo: %s", romeo);
        printf("Juliet: %s", juliet);
        printf("Juliet: %s", "O Romeo, Romeo! wherefore art thou Romeo?\n");
        printf("Juliet: %s", "Deny thy father and refuse thy name;\n");
        printf("Juliet: %s", "Or if thou wilt not, be but sworn my love,\n");
        printf("Juliet: %s", "And I'll no longer be a Capulet.\n");
    }

    return 0;
}