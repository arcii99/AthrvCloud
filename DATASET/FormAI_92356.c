//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void surrealist_cluster(char *input) {
    srand(time(NULL));
    int cluster_size = rand() % 10 + 3;
    int input_length = strlen(input);
    int clusters = input_length / cluster_size + 1;
    int cluster_start = 0;
    char *output[clusters];

    for(int i = 0; i < clusters; i++) {
        int cluster_end = cluster_start + cluster_size;
        if(cluster_end > input_length) {
            cluster_end = input_length;
        }
        output[i] = malloc((cluster_end - cluster_start) * sizeof(char));

        int k = 0;
        for(int j = cluster_start; j < cluster_end; j++) {
            output[i][k++] = input[j];
        }
        cluster_start = cluster_end;
    }

    printf("Surrealist clustering result:\n");
    for(int i = 0; i < clusters; i++) {
        for(int j = 0; j < strlen(output[i]); j++) {
            printf("%c", output[i][j]);
            if(j != strlen(output[i]) - 1) {
                printf("-");
            }
        }
        printf("\n");
    }

    printf("Cluster size: %d\n", cluster_size);
}

int main() {
    char input[] = "The quick brown fox jumps over the lazy dog.";
    surrealist_cluster(input);
    return 0;
}