//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct node{
    int node1,node2;
    float value;
};

int main()
{
    int choice = 1;
    int branches, sources;
    printf("Enter the number of branches and sources: ");
    scanf("%d%d", &branches, &sources);
    struct node *n = malloc((branches + sources) * sizeof(*n));

    for(int i=0; i<branches; i++){
        printf("Enter the values for branch number %d (Node 1, Node 2, Value): ", i+1);
        scanf("%d%d%f", &n[i].node1, &n[i].node2, &n[i].value);
    }

    for(int i=branches; i<branches+sources; i++){
        printf("Enter the values for source number %d (Node 1, Node 2): ", i-branches+1);
        scanf("%d%d", &n[i].node1, &n[i].node2);
    }

    int voltages[branches + sources][branches + sources];
    memset(voltages, 0, sizeof(voltages[0][0]) * (branches + sources) * (branches + sources));
    int currents[branches + sources];
    memset(currents, 0, sizeof(currents[0]) * (branches + sources));

    for(int i=0; i<branches+sources; i++){
        for(int j=i+1; j<branches+sources; j++){
            for(int k=0; k<branches; k++){
                if(n[k].node1 == i+1 && n[k].node2 == j+1){
                    voltages[i][j] = -1;
                    voltages[j][i] = -1; 
                    break;
                }
                else if(n[k].node2 == i+1 && n[k].node1 == j+1){
                    voltages[i][j] = -1;
                    voltages[j][i] = -1; 
                    break;
                }
            }
            if(i == j){
                voltages[i][j] = 1;
            }
        }
    }

    while(choice) {
        printf("Enter a branch number and requested current (Enter 0 to quit): ");
        int n1 = 0, n2 = 0, curr;
        scanf("%d", &n1);
        if(n1==0){
            break;
        }
        scanf("%d", &curr);

        for(int i=0; i<branches+sources; i++){
            if(i == n1-1){
                currents[n1-1] = curr;
                for(int j=0; j<branches+sources; j++){
                    voltages[n1-1][j] = 0;
                }
                voltages[n1-1][n1-1] = 1;

            }
            else{
                currents[i] = 0;
                voltages[n1-1][i] = 0;
            }
        }

        int count = 0;
        float x[branches+sources];
        memset(x, 0, sizeof(x[0]) * (branches + sources));
        while(count<100){
            float delta = 0;
            for(int i=0; i<branches+sources; i++){
                float sum = 0;
                for(int j=0; j<branches+sources; j++){
                    sum += voltages[i][j] * x[j];
                }
                float temp = (currents[i] - sum)/voltages[i][i];
                delta += abs(temp-x[i]);
                x[i] = temp;
            }
            if(delta<0.0001){
                break;
            }
            count++;
        }
        printf("Current = %.4f\n", x[n2-1]-x[n1-1]);
    }

    return 0;
}