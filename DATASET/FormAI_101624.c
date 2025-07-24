//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Romeo and Juliet
// A Wi-Fi Signal Strength Analyzer Program in Romeo and Juliet Style

#include<stdio.h>
#include<stdlib.h>

int main(){

    // Welcome Message
    printf("Oh Wi-Fi, Wi-Fi, wherefore art thou Wi-Fi?\n");
    printf("Deny thy signal strength and refuse thy name;\n");
    printf("Or if thou wilt not, be but sworn my signal booster,\n");
    printf("And I'll no longer be a poor connection.");

    // Scan for Wi-Fi Networks
    printf("What's in a name? That which we call a Wi-Fi\n");
    printf("By any other name would smell as sweet;\n");
    printf("Scan all the Wi-Fi channels to find the one\n");
    printf("That we shall use to connect.\n");

    int network1 = rand() % 100;
    int network2 = rand() % 100;
    int network3 = rand() % 100;

    printf("The first network hath a signal strength of %d\n", network1);
    printf("The second network hath a signal strength of %d\n", network2);
    printf("The third network hath a signal strength of %d\n", network3);

    // Choose the Strongest Signal
    printf("Oh, swear not by the signal strength of any Wi-Fi!\n");
    printf("Yet, I'll believe thee if thou telleth me which network\n");
    printf("Hath the strongest signal amongst three;\n");
    printf("For thou art as glorious to this network engineer as my router.");

    if(network1 > network2 && network1 > network3){
        printf("The first network is the strongest with %d signal strength.\n", network1);
    }
    else if(network2 > network1 && network2 > network3){
        printf("The second network is the strongest with %d signal strength.\n", network2);
    }
    else{
        printf("The third network is the strongest with %d signal strength.\n", network3);
    }

    // Connect to the Strongest Network
    printf("Goodbye cruel world, I shall now connect\n");
    printf("To the network with the strongest signal strength\n");
    printf("And live my life as free as the internet.\n");
    printf("Adieu, adieu! Wi-Fi is such sweet sorrow,\n");
    printf("That I shall say good night till it be morrow.\n");

    return 0;
}