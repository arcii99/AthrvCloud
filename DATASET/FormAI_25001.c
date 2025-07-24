//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max_size 10

struct point{
    int x, y;
};

struct cluster{
    int size;
    struct point *points;
};

double get_distance(struct point p1,struct point p2){
    double distance=sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2));
    return distance;
}

void cluster(struct cluster *c,double max_distance){
    int i,j,k,n;
    int cluster_count=0;
    double distance;
    int visited[max_size];
    for (i=0;i<c[0].size;i++) visited[i]=0;
    for (i=0;i<c[0].size;i++){
        if (visited[i]==0){
            visited[i]=1;
            c[cluster_count].points=realloc(c[cluster_count].points,(c[cluster_count].size+1)*sizeof(struct point));
            c[cluster_count].points[c[cluster_count].size]=c[0].points[i];
            n=c[cluster_count].size;
            c[cluster_count].size++;
            for (j=i+1;j<c[0].size;j++){
                if (visited[j]==0){
                    distance=get_distance(c[0].points[i],c[0].points[j]);
                    if (distance<=max_distance){
                        visited[j]=1;
                        c[cluster_count].points=realloc(c[cluster_count].points,(c[cluster_count].size+1)*sizeof(struct point));
                        c[cluster_count].points[c[cluster_count].size]=c[0].points[j];
                        c[cluster_count].size++;
                        for (k=0;k<n;k++){
                            distance=get_distance(c[cluster_count].points[k],c[0].points[j]);
                            if (distance<=max_distance){
                                cluster(c,max_distance);
                                return;
                            }
                        }
                        n=c[cluster_count].size;
                    }
                }
            }
            cluster_count++;
        }
    }
}

int main(){
    int i,max_distance,n;
    struct point p[max_size];
    struct cluster c[5];
    printf("Enter the number of points(minimum 2, maximum %d): ",max_size);
    scanf("%d",&n);
    while (n<=1||n>max_size){
        printf("Invalid number! Enter a number between 2 and %d: ",max_size);
        scanf("%d",&n);
    }
    printf("Enter the points:\n");
    for (i=0;i<n;i++){
        scanf("%d %d",&p[i].x,&p[i].y);
        c[0].points=realloc(c[0].points,(c[0].size+1)*sizeof(struct point));
        c[0].points[c[0].size]=p[i];
        c[0].size++;
    }
    printf("Enter the maximum distance: ");
    scanf("%d",&max_distance);
    cluster(c,max_distance);
    printf("\nClusters:\n");
    for (i=0;i<5;i++){
        if (c[i].size!=0){
            printf("Cluster %d: ",i+1);
            for (int j=0;j<c[i].size;j++) printf("(%d,%d) ",c[i].points[j].x,c[i].points[j].y);
            printf("\n");
        }
    }
    return 0;
}