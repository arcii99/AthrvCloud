//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: excited
#include<stdio.h>
#define ROW 10
#define COL 10
#define MAX 100

int dx[]={ 1,-1, 0, 0}; //to move up, down, right, left
int dy[]={ 0, 0, 1,-1};

int dist[ROW][COL]; //distance of each cell from source

int grid[ROW][COL]=   //obstacle matrix
{
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

void printPath(int sx,int sy,int ex,int ey)
{
    if (sx==ex && sy==ey)
    {
        printf("(%d,%d) ", sx, sy);
        return;
    }
    int temp=dist[ex][ey];
    for(int i=0;i<4;i++)
    {
        int x = ex + dx[i];
        int y = ey + dy[i];
        if(x>=0&&x<ROW&&y>=0&&y<COL&&dist[x][y]==temp-1)
        {
            printPath(sx, sy, x, y);
            printf("(%d,%d) ", ex, ey);
            break;
        }
    }
}

void Astar(int sx,int sy,int ex,int ey)
{
    memset(dist, -1, sizeof(dist)); //initializing distance of all cells to -1
    int q[MAX][2];
    dist[sx][sy]=0; //distance of source from itself is 0
    int f=-1,r=-1;
    q[++r][0]=sx;
    q[r][1]=sy;
    while(f!=r)
    {
        //dequeue a cell
        int x=q[++f][0];
        int y=q[f][1];
        if(x==ex&&y==ey) //if we have reached the destination
        {
            printPath(sx,sy,ex,ey);
            return;
        }
        //push all its neighbors in the queue
        for(int i=0; i<4; i++)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if(nx>=0&&nx<ROW&&ny>=0&&ny<COL&&grid[nx][ny]==0&&dist[nx][ny]==-1) //if the cell is walkable
            {
                dist[nx][ny]=dist[x][y]+1; //calculate its distance from source
                q[++r][0]=nx;
                q[r][1]=ny;
            }
        }
    }
    printf("Path not found");
}

int main()
{
    int sourceX=0, sourceY=0, destX=9, destY=9;
    printf("Path from (%d,%d) to (%d,%d): ", sourceX, sourceY, destX, destY);
    Astar(sourceX,sourceY,destX,destY);
    return 0;
}