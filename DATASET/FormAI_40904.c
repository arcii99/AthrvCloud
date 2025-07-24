//FormAI DATASET v1.0 Category: Digital Auction System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main(){
    int num_bidders;
    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);

    // allocate memory for bidder information arrays
    char **names = (char**) malloc(num_bidders * sizeof(char*));
    double *bids = (double*) malloc(num_bidders * sizeof(double));
    int *ids = (int*) malloc(num_bidders * sizeof(int));

    // input bidder information
    for(int i = 0; i < num_bidders; i++){
        names[i] = (char*) malloc(20 * sizeof(char));
        printf("Enter name of bidder %d: ", i+1);
        scanf("%s", names[i]);
        printf("Enter bid of bidder %d: ", i+1);
        scanf("%lf", &bids[i]);
        ids[i] = i+1;
    }

    // find the highest bidder
    int highest_bidder_index = 0;
    for(int i = 1; i < num_bidders; i++){
        if(bids[i] > bids[highest_bidder_index]){
            highest_bidder_index = i;
        }
    }

    // output the winner
    printf("\nThe winner is:\nName: %s\nID: %d\nBid: %.2lf\n", names[highest_bidder_index], ids[highest_bidder_index], bids[highest_bidder_index]);

    // free memory
    for(int i = 0; i < num_bidders; i++){
        free(names[i]);
    }
    free(names);
    free(bids);
    free(ids);

    return 0;
}