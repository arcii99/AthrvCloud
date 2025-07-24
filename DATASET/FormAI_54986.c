//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 50 // Size of the matrix
#define P 0.5 // Probability of a site being open

int parent[N*N], rank[N*N], open[N][N];
int size=0;

int find(int p);
void union_set(int p, int q);
int get_random_int(int min, int max);
void percolate();
void print_matrix();

int main() {
    srand((unsigned int)time(NULL));
    percolate(); // Run the percolation simulation
    return 0;
}

// Find operation for Union-Find algorithm
int find(int p) {
    while(parent[p]!=p) {
        parent[p]=parent[parent[p]];
        p=parent[p];
    }
    return p;
}

// Union operation for Union-Find algorithm
void union_set(int p, int q) {
    int i=find(p);
    int j=find(q);
    if(i==j) return;
    if(rank[i]<rank[j]) {
        parent[i]=j;
    } else if(rank[i]>rank[j]) {
        parent[j]=i;
    } else {
        parent[j]=i;
        rank[i]++;
    }
}

// Generate a random integer between min and max (inclusive)
int get_random_int(int min, int max) {
    return rand()%(max-min+1)+min;
}

// Run the percolation simulation
void percolate() {
    int i,j,k,num_open=0;
    for(i=0;i<N*N;i++) {
        parent[i]=i; // Initialize parent array for Union-Find algorithm
        rank[i]=0; // Initialize rank array for Union-Find algorithm
    }
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            if((double)rand()/RAND_MAX<=P) {
                open[i][j]=1; // Open the site with probability P
                num_open++;
                if(i>0 && open[i-1][j]==1) union_set(i*N+j, (i-1)*N+j); // Union neighboring open sites
                if(i<N-1 && open[i+1][j]==1) union_set(i*N+j, (i+1)*N+j);
                if(j>0 && open[i][j-1]==1) union_set(i*N+j, i*N+(j-1));
                if(j<N-1 && open[i][j+1]==1) union_set(i*N+j, i*N+(j+1));
            }
        }
    }
    printf("Number of open sites: %d\n", num_open);
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            if(open[i][j]==1 && find(i*N+j)==find(0)) { // If site is open and is connected to the top node
                size++;
            }
        }
    }
    printf("Size of the top cluster: %d\n", size);
    print_matrix(); // Print the matrix with open and blocked sites
}

// Print the matrix with open and blocked sites
void print_matrix() {
    int i,j;
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            if(open[i][j]==1) {
                printf(". ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}