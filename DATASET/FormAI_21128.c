//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: romantic
#include<stdio.h>//standard input-output library
#define ROW 6//row size
#define COL 6//column size

int grid[ROW][COL]={
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0}
};//grid representation of the map

struct node{
    int row, col;//node position in the grid
    int f, g, h;//cost values for a node
    struct node* parent;//parent node for backtracking
};

struct node* startNode(int row, int col){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));//dynamically allocate memory

    newNode->row=row;//initialize node position
    newNode->col=col;

    newNode->f=0;//initialize cost values
    newNode->g=0;
    newNode->h=0;

    newNode->parent=NULL;//initialize parent node to NULL

    return newNode;//return newly created node structure
}

int heuristic(struct node* current, struct node* goal){
    int x=current->row-goal->row;//difference of row values
    int y=current->col-goal->col;//difference of column values

    return sqrt(pow(x, 2)+pow(y, 2));//return Euclidean distance
}

void pathFind(){
    char foundPath[ROW][COL];//array for visual output of path finding
    memset(foundPath, ' ', sizeof(foundPath));//fill entire array with empty spaces

    struct node* openList[ROW*COL]={NULL};//array for open list nodes
    struct node* closedList[ROW*COL]={NULL};//array for closed list nodes

    struct node* start=startNode(0, 0);//create start node
    struct node* goal=startNode(4, 5);//create goal node

    int openListCounter=0;//counter for open list

    openList[openListCounter++]=start;//add starting node to open list

    int i, j;//variables for loop iteration
    while(openListCounter>0){
        struct node* current=openList[0];
        int currentIndex=0;

        for(i=0;i<openListCounter;i++){//find node with the lowest cost
            if(openList[i]->f<current->f){
                current=openList[i];
                currentIndex=i;
            }
        }

        openList[currentIndex]=openList[--openListCounter];//remove current node from open list

        closedList[currentIndex]=current;//add current node to closed list

        if(current->row==goal->row && current->col==goal->col){
            while(current->parent!=NULL){//backtracking to find optimal path
                foundPath[current->row][current->col]='*';
                current=current->parent;
            }

            foundPath[current->row][current->col]='S';//mark start node
            foundPath[goal->row][goal->col]='G';//mark goal node

            printf("\n");

            for(i=0;i<ROW;i++){
                for(j=0;j<COL;j++){
                    printf("%c ", foundPath[i][j]);//display map with path
                }
                printf("\n");
            }

            return;
        }

        int row, col;
        struct node* successor;

        for(i=-1;i<=1;i++){
            for(j=-1;j<=1;j++){
                if(abs(i)!=abs(j)){//ignore current node and diagonal nodes
                    row=current->row+i;
                    col=current->col+j;

                    if(row>=0 && row<ROW && col>=0 && col<COL && !grid[row][col]){
                        successor=startNode(row, col);
                        successor->parent=current;

                        successor->g=current->g+1;//increase cumulative cost
                        successor->h=heuristic(successor, goal);
                        successor->f=successor->g+successor->h;

                        int inOpenList=0, inClosedList=0;//flag variables

                        for(int k=0;k<openListCounter;k++){
                            if(successor->row==openList[k]->row && successor->col==openList[k]->col){
                                inOpenList=1;
                                break;
                            }
                        }

                        for(int k=0;k<openListCounter;k++){
                            if(successor->row==closedList[k]->row && successor->col==closedList[k]->col){
                                inClosedList=1;
                                break;
                            }
                        }

                        if(!inOpenList && !inClosedList){//add new node to open list
                            openList[openListCounter++]=successor;
                        }
                    }
                }
            }
        }
    }

    printf("\nPath not found.\n");//if no path can be found
}

int main(){
    printf("Map Representation:\n");

    int i, j;//iterator variables

    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            printf("%d ", grid[i][j]);//display map
        }
        printf("\n");
    }

    printf("\nPath Finding:\n");
    pathFind();

    return 0;//finish
}