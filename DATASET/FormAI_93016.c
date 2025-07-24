//FormAI DATASET v1.0 Category: Data mining ; Style: detailed
#include<stdio.h>
#include<stdlib.h>

// function to implement apriori algorithm
void apriori(int trans[][100], int num_trans, int num_items, float min_sup) {
    int itemset[num_items];
    int i, j, k, l;
    int candidate[100];
    int freq[100], freq_set[100];
    int num_sets = 0;
    int num_candidates = 0;

    for(i = 1; i < num_items + 1; i++) {
        itemset[i-1] = i;
        freq_set[i-1] = 0;
    }

    int count[num_items][num_items];
    for(i = 0; i < num_items; i++)
        for(j = 0; j < num_items; j++)
            count[i][j] = 0;

    for(i = 0; i < num_trans; i++) {
        for(j = 0; j < num_items; j++) {
            if(trans[i][j] != 0) {
                freq_set[j]++;
                for(k = j+1; k < num_items; k++) {
                    if(trans[i][k] != 0) {
                        count[j][k]++;
                    }
                }
            }
        }
    } 

    for(i = 0; i < num_items; i++) {
        if((float)freq_set[i]/num_trans >= min_sup) {
            candidate[num_candidates++] = itemset[i];
        }
    }

    while(num_candidates > 0) {
        printf("\nFrequent Itemsets: ");
        for(i = 0; i < num_candidates; i++) {
            printf("{%d} ", candidate[i]);
        }

        num_sets++;

        for(i = 0; i < num_candidates; i++) {
            int x = candidate[i];
            for(j = i+1; j < num_candidates; j++) {
                int y = candidate[j];
                int found = 0;
                for(k = 0; k < num_trans; k++) {
                    if(trans[k][x-1] != 0 && trans[k][y-1] != 0) {
                        found = 1;
                        count[x-1][y-1]++;
                    }
                }

                if(found == 1) {
                    if(!contains(candidate, num_candidates, x, y)) {
                        candidate[num_candidates++] = x*10 + y;
                    }
                }
            }
        }

        for(i = 0; i < num_items; i++) {
            freq_set[i] = 0;
        }

        printf("\nNew Candidates: ");
        for(i = 0; i < num_candidates; i++) {
            int x = candidate[i]/10;
            int y = candidate[i]%10;

            if((float)count[x-1][y-1]/num_trans >= min_sup) {
                freq[num_sets-1]++;
                freq_set[x-1]++;
                freq_set[y-1]++;         
                printf("{%d,%d} ", x, y);
            } 
        }

        for(i = 0; i < num_items; i++) {
            if(freq_set[i] >= min_sup*num_trans) {
                if(!contains(candidate, num_candidates, i+1)) {
                    candidate[num_candidates++] = i+1;    
                }
            }
        }

        for(i = 0; i < num_candidates; i++) {
            int x = candidate[i]/10;
            int y = candidate[i]%10;
            count[x-1][y-1] = 0;
        }

    }
}

// function to check if an element exists in an array
int contains(int arr[], int n, int a, int b) {
    int i;
    for(i = 0; i < n; i++) {
        if(arr[i] == a*10 + b || arr[i] == b*10 + a) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int trans[5][100] = {
        {1,1,0,0,0,1,1,0,0,0},
        {1,0,0,1,1,0,1,0,0,0},
        {0,0,1,0,1,1,1,0,0,0},
        {0,1,0,0,1,0,1,0,0,1},
        {0,0,0,1,0,1,0,1,1,0}
    };

    apriori(trans, 5, 10, 0.4);

    return 0;
}