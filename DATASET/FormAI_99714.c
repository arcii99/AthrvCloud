//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int answer;
    time_t t;
    srand((unsigned) time(&t));

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please keep in mind that the future is unpredictable and ever-changing.\n");
    printf("Your fate lies in the hands of this program...\n");

    printf("Ask a yes or no question about your future: ");
    scanf("%d", &answer);

    if(answer % 2 == 0) {
        printf("The answer is yes. But be careful, because sometimes what appears to be a blessing can actually be a curse.\n");
    }
    else {
        printf("The answer is no. But perhaps that is for the best. Sometimes ignorance is bliss.\n");
    }

    printf("Thank you for using the Automated Fortune Teller. But remember, the future is not set in stone...\n");
    printf("You never know who could be watching, so you had better be careful who you trust...\n");
    printf("Goodbye.\n");

    return 0;
}