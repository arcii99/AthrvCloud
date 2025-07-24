//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ROWS 10
#define COLS 10
#define INF 1000000000

// defining the structure for each cell in the grid
typedef struct node{
    bool blocked;
    int f, g, h;
    int x, y;
    struct node* parent;
} Node;

// creating grid of nodes
Node grid[ROWS][COLS];

// function to initialize the grid with blocked cells
void initialize_grid(){
   int i, j;

   for(i=0; i<ROWS; i++){
      for(j=0; j<COLS; j++){
         grid[i][j].blocked = false;
         grid[i][j].f = grid[i][j].g = grid[i][j].h = INF;
         grid[i][j].x = i;
         grid[i][j].y = j;
         grid[i][j].parent = NULL;

         // randomly block some cells
         if((rand()%100) < 30)
            grid[i][j].blocked = true;
      }
   }
}

//heuristic function declaration
int heuristic(Node node1, Node node2);

// function to perform A* pathfinding algorithm
void a_star_pathfinding(Node start_node, Node end_node){
   int i, j, x, y, new_cost;
   bool found_path = false;
   Node open_list[ROWS*COLS], current_node, neighbor_node;
   int num_open_list = 0;

   // set cost of start node and add to open list
   start_node.g = 0;
   start_node.h = heuristic(start_node, end_node);
   start_node.f = start_node.g + start_node.h;
   open_list[num_open_list++] = start_node;

   // keep searching until path is found or open list is empty
   while(num_open_list > 0){

      //get node with lowest f cost
      int min_index = 0;
      for(i=0; i<num_open_list; i++){
         if(open_list[i].f < open_list[min_index].f){
            min_index = i;
         }
      }

      current_node = open_list[min_index];

      // if end node is found, then path is found and break the loop
      if(current_node.x == end_node.x && current_node.y == end_node.y){
         found_path = true;
         break;
      }

      //remove current node from open list
      for(i=min_index; i<num_open_list-1; i++){
         open_list[i] = open_list[i+1];
      }
      num_open_list--;

      //get neighbors of current node
      x = current_node.x;
      y = current_node.y;

      for(i=-1; i<=1; i++){
         for(j=-1; j<=1; j++){
            if((i==0 && j==0) || x+i<0 || x+i>=ROWS || y+j<0 || y+j>=COLS || grid[x+i][y+j].blocked){
               continue;
            }

            neighbor_node = grid[x+i][y+j];
            new_cost = current_node.g + heuristic(current_node, neighbor_node);

            if(new_cost < neighbor_node.g){
               neighbor_node.g = new_cost;
               neighbor_node.h = heuristic(neighbor_node, end_node);
               neighbor_node.f = new_cost + neighbor_node.h;
               neighbor_node.parent = &grid[x][y];

               //check if neighbor is already on open list
               bool already_in_open_list = false;
               for(int k=0; k<num_open_list; k++){
                  if(open_list[k].x == neighbor_node.x && open_list[k].y == neighbor_node.y){
                     already_in_open_list = true;
                     break;
                  }
               }

               //if neighbor not in open list, add it
               if(!already_in_open_list){
                  open_list[num_open_list++] = neighbor_node;
               }
            }
         }
      }
   }

   // if path is found, print it
   if(found_path){
      printf("Path found:\n");
      Node node = end_node;
      while(node.parent){
         printf("(%d,%d) -> ", node.x, node.y);
         node = *(node.parent);
      }
      printf("(%d,%d)\n", start_node.x, start_node.y);
   }
   else{
      printf("No path found.\n");
   }
}

// main function
int main(){
   srand(0); // initialize random number generator
   initialize_grid(); // initialize grid of nodes

   Node start_node, end_node;

   // randomly select start and end nodes
   start_node = grid[rand()%ROWS][rand()%COLS];
   end_node = grid[rand()%ROWS][rand()%COLS];

   printf("Start node: (%d,%d)\n", start_node.x, start_node.y);
   printf("End node: (%d,%d)\n", end_node.x, end_node.y);

   a_star_pathfinding(start_node, end_node);

   return 0;
}

// heurisitic function implementation
int heuristic(Node node1, Node node2){
   return abs(node1.x - node2.x) + abs(node1.y - node2.y);
}