//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10
#define TRIAL 10

int main(){
    srand(time(NULL));
    int open[N][N], i, j, num, count=0, connected=0;
    float p, density;
    int neighbors[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; //top, bottom, left, right neighbors
    
    //initialize the grid
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            open[i][j] = 0;
        }
    }
    
    //run trials with increasing probability of opening a site
    for(num=0; num<TRIAL; num++){
        p = (float)(num+1)/(float)TRIAL;
        count = 0;
        while(connected==0){
            //randomly open a site
            i = rand() % N;
            j = rand() % N;
            open[i][j] = 1;
            count++;
            
            //check if the site is connected to the top
            if(i==0){
                connected = 1;
            }
            else{
                for(int k=0; k<4; k++){
                    int ni = i + neighbors[k][0];
                    int nj = j + neighbors[k][1];
                    if(ni>=0 && ni<N && nj>=0 && nj<N && open[ni][nj]==1){
                        connected = 1;
                        break;
                    }
                }
            }
        }
        
        //calculate the density of the percolating cluster
        density = (float) count / (float) (N*N);
        printf("Probability of opening a site: %.2f\n", p);
        printf("Number of open sites: %d\n", count);
        printf("Percolating cluster density: %.2f\n", density);
        printf("\n");
        
        //reset the grid and connected flag
        connected = 0;
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                open[i][j] = 0;
            }
        }
    }
    
    return 0;
}