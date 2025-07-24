//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n=10;//size of the matrix
int open[1000][1000];//matrix for open sites
int uf[100000];//array for union-find operations
int size[100000]={0};//array for size of the components
int top[100000]={0};//array for the top of the components
int bottom[100000]={0};//array for the bottom of the components

//function to initialize the matrix for percolation
void initialize(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            open[i][j]=0;//initially all sites are closed
        }
    }
}

//function to generate random number between two limits
int rand_lim(int limit){
    int divisor = RAND_MAX/(limit+1);
    int retval;
    do{
        retval = rand() / divisor;
    }while (retval > limit);
    return retval;
}

//function to convert matrix indices to linear array index
int convert(int i, int j){
    int p = (i-1)*n + j;//row major mapping
    return p;
}

//function to perform find operation for union-find data structure
int find(int p){
    while(p!=uf[p]){
        p=uf[p];
    }
    return p;
}

//function to perform union operation for union-find data structure
void unionn(int p, int q){
    int root_p = find(p);
    int root_q = find(q);
    if(root_p==root_q){
        return;
    }
    if(size[root_p]<size[root_q]){
        uf[root_p]=root_q;
        size[root_q]+=size[root_p];
        top[root_q]=top[root_p];
        bottom[root_q]=bottom[root_p];
    }
    else{
        uf[root_q]=root_p;
        size[root_p]+=size[root_q];
        top[root_p]=top[root_q];
        bottom[root_p]=bottom[root_q];
    }
}

//function to check if a site is open or not
int isopen(int i, int j){
    if(i<1 || i>n || j<1 || j>n){
        return 0;
    }
    return open[i][j];
}

//function to open a site
void openn(int i, int j){
    if(open[i][j]==1){
        return;
    }
    open[i][j]=1;
    int p=convert(i,j);
    size[p]=1;
    uf[p]=p;
    top[p]=p;
    bottom[p]=p;
    if(i==1){
        unionn(p,n*n+1);
    }
    if(i==n){
        unionn(p,n*n+2);
    }
    if(isopen(i-1,j)==1){
        unionn(p,convert(i-1,j));
    }
    if(isopen(i+1,j)==1){
        unionn(p,convert(i+1,j));
    }
    if(isopen(i,j-1)==1){
        unionn(p,convert(i,j-1));
    }
    if(isopen(i,j+1)==1){
        unionn(p,convert(i,j+1));
    }
}

//function to check if percolation has occurred
int percolates(){
    int root_1=find(n*n+1);//root of virtual top site
    int root_2=find(n*n+2);//root of virtual bottom site
    
    //if both virtual top and virtual bottom sites have same root, then percolation has occurred
    if(root_1==root_2){
        return 1;
    }
    return 0;
}

int main(){
    srand(time(NULL));
    initialize();
    int count=0;
    while(percolates()==0){//keep opening random sites till percolation occurs
        int i=rand_lim(n)+1;
        int j=rand_lim(n)+1;
        openn(i,j);
        count++;
    }
    printf("Percolation occurs after opening %d sites\n",count);
    return 0;
}