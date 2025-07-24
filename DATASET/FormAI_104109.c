//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: curious
#include<stdio.h>

int main(){
   int n,start,end;
   printf("Enter the number of nodes: ");
   scanf("%d",&n);

   int graph[n][n],visited[n],distance[n],prev[n];
   for(int i=0;i<n;i++){
       visited[i]=0;
       distance[i]=999999;
   }

   printf("Enter the weights of the edges: ");
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           scanf("%d",&graph[i][j]);
       }
   }

   printf("Enter the starting and ending nodes: ");
   scanf("%d %d",&start,&end);
   start--;
   end--;

   distance[start]=0;
   int current=start;

   while(current!=end){
       visited[current]=1;

       int minDistance=999999;
       int nextNode=0;

       for(int i=0;i<n;i++){
           if(graph[current][i]>0 && !visited[i]){
               int totalDistance=distance[current]+graph[current][i];
               if(totalDistance<distance[i]){
                   distance[i]=totalDistance;
                   prev[i]=current;
               }
               if(distance[i]<minDistance){
                   minDistance=distance[i];
                   nextNode=i;
               }
           }
       }
       current=nextNode;
   }

   printf("\nShortest Path: ");
   int path[n];
   int count=1;
   int temp=end;

   while(temp!=start){
       path[count]=temp;
       count++;
       temp=prev[temp];
   }

   path[count]=start;

   for(int i=count;i>=1;i--){
       printf("%d ",path[i]+1);
   }
   printf("\nShortest Distance: %d",distance[end]);

   return 0;
}