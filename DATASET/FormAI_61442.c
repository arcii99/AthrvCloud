//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Romeo and Juliet
/* Two star-crossed lovers, Romeo and Juliet,
   Sat upon their computers with great regret.
   Their internet connection was frustratingly slow,
   So they devised a plan to test it, they did go. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int speed = rand() % 100 + 1; // generate a random number between 1 and 100
    
    printf("Oh Juliet, my love, our internet speed is a mystery,\n");
    printf("Let us test it, and find out if we can finally be merry.\n");
    printf("With a little code, we can make our connection run fast,\n");
    printf("And our love, like our internet, will never be surpassed.\n");
    
    if (speed >= 80) {
        printf("Oh how the heavens smile upon us, my dearest,\n");
        printf("Our internet speed is lightning fast, it is the clearest.\n");
        printf("Our love and our internet will never falter,\n");
        printf("For our connection is as strong as our love, this we shall alter.\n");
    } else if (speed >= 50) {
        printf("My dear Juliet, our internet speed is fair,\n");
        printf("Neither lightning nor sluggish, it is a bear.\n");
        printf("But fear not, for I shall improve our connection,\n");
        printf("And with our love, it will be a perfect combination.\n");
    } else {
        printf("Oh my love, our internet speed is slow,\n");
        printf("Like molasses in winter, it makes us blow.\n");
        printf("But worry not, for I shall fix this woe,\n");
        printf("And our love and our internet shall be aglow.\n");
    }
    
    return 0;
}