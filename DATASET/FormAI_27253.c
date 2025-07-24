//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: immersive
#include <stdio.h> 

#define MAX_ROW 20 
#define MAX_COL 30 

char maze[MAX_ROW][MAX_COL+1] = {
    "########## ###########", 
    "#     #   ####  #    #", 
    "# ### # ####     #  ##", 
    "# ### #    # ####   ##", 
    "#     ##### # ##     #", 
    "# #####   ## ##  #####", 
    "# ##### ### # ##  ## #", 
    "# ##### ### # ##    ##", 
    "#       ### # #######", 
    "##########     ######", 
    "########## #### #####", 
    "#          ## ## #  ##", 
    "## ###### ## ## ##  ##", 
    "## #    ## ## #  #  ##", 
    "## # #  ## ## #  ## ###", 
    "   # #  ## ## #     ###", 
    "   # #  ##    # ### ###", 
    "   # #  ###### ### ###", 
    "   # #  ######      ###", 
    "   # #       #########", 
};

int start_row, start_col, end_row, end_col; 

int dir_row[] = { -1, 0, 1, 0 }; 
int dir_col[] = { 0, 1, 0, -1 }; 
int visited[MAX_ROW][MAX_COL];

typedef struct {
    int row;
    int col;
    int parent_row;
    int parent_col;
} node;

node queue[MAX_ROW * MAX_COL];

int front_idx = 0;
int rear_idx = 0;

void enqueue(node n) {
    queue[rear_idx] = n;
    rear_idx++;
}

node dequeue() {
    front_idx++;
    return queue[front_idx - 1];
}

int is_empty() {
    return front_idx == rear_idx;
}

void find_start_end() {
    int i, j;
    
    for (i = 0; i < MAX_ROW; i++) {
        for (j = 0; j < MAX_COL; j++) {
            if (maze[i][j] == 'S') {
                start_row = i;
                start_col = j;
            }
            if (maze[i][j] == 'E') {
                end_row = i;
                end_col = j;
            }
        }
    }
}

void visit(int row, int col, int parent_row, int parent_col) {
    visited[row][col] = 1;
    
    node n = { row, col, parent_row, parent_col };
    enqueue(n);
}

int bfs() {
    find_start_end();
    visit(start_row, start_col, start_row, start_col);
    
    while (!is_empty()) {
        node current = dequeue();
        
        int i;
        for (i = 0; i < 4; i++) {
            int new_row = current.row + dir_row[i];
            int new_col = current.col + dir_col[i];
            
            if (new_row < 0 || new_col < 0 || new_row >= MAX_ROW || new_col >= MAX_COL) {
                continue;
            }
            
            if (maze[new_row][new_col] == '#') {
                continue;
            }
            
            if (visited[new_row][new_col]) {
                continue;
            }
            
            visit(new_row, new_col, current.row, current.col);
            
            if (new_row == end_row && new_col == end_col) {
                return 1;
            }
        }
    }
    
    return 0;
}

void print_path() {
    int row = end_row;
    int col = end_col;
    int parent_row = queue[rear_idx-1].parent_row;
    int parent_col = queue[rear_idx-1].parent_col;
    
    while (row != start_row || col != start_col) {
        int i;
        for (i = 0; i < 4; i++) {
            int new_row = row + dir_row[i];
            int new_col = col + dir_col[i];
            
            if (new_row == parent_row && new_col == parent_col) {
                if (i == 0) {
                    printf("U");
                } else if (i == 1) {
                    printf("R");
                } else if (i == 2) {
                    printf("D");
                } else if (i == 3) {
                    printf("L");
                }
                row = parent_row;
                col = parent_col;
                parent_row = queue[i].parent_row;
                parent_col = queue[i].parent_col;
                break; 
            }
        }
    }
}

int main() {
    if (bfs()) {
        printf("Shortest path: ");
        print_path();
    } else {
        printf("No path found!");
    }
    return 0;
}