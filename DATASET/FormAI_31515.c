//FormAI DATASET v1.0 Category: Recursive ; Style: Romeo and Juliet
// Romeo and Juliet Style Recursive Function Example Program

#include <stdio.h>

void myLove(int timeSpentTogether);

int main() {
    printf("O Romeo, Romeo! wherefore art thou Romeo?\n");
    printf("Deny thy father and refuse thy name;\n");
    printf("Or, if thou wilt not, be but sworn my love,\n");
    printf("And I'll no longer be a Capulet.\n");
    
    myLove(0);
    
    return 0;
}

void myLove(int timeSpentTogether) {
    if(timeSpentTogether >= 10){
        printf("Good night, good night! parting is such sweet sorrow,\n");
        printf("That I shall say good night till it be morrow.\n");
    }else{
        printf("My bounty is as boundless as the sea,\n");
        printf("My love as deep; the more I give to thee,\n");
        printf("The more I have, for both are infinite.\n");
        
        timeSpentTogether++;
        myLove(timeSpentTogether);
    }
}