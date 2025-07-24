//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

#define ROW_SIZE 10
#define COL_SIZE 10
#define MAX_STEPS 50

int maze[ROW_SIZE][COL_SIZE] = {    //The maze matrix.
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int x_start = 1, y_start = 1;    //Starting point of the maze.

/* Stack implementation */

struct node{     //Node for the stack.
    int x, y, steps;
};
typedef struct node Node;

struct stack{    //Stack implementation.
    Node arr[MAX_STEPS];
    int top;
};
typedef struct stack Stack;

int is_empty(Stack *s){     //Check if the stack is empty.
    return (s->top == -1);
}

int is_full(Stack *s){      //Check if the stack is full.
    return (s->top == MAX_STEPS-1);
}

void push(Stack *s, Node data){   //Push node on to the stack.
    if(is_full(s)){
        printf("Stack full!\n");
    }
    else{
        s->top++;
        s->arr[s->top] = data;
    }
}

Node pop(Stack *s){     //Remove node from the stack.
    Node data = {0, 0, 0};
    if(is_empty(s)){
        printf("Stack empty!\n");
    }
    else{
        data = s->arr[s->top];
        s->top--;
    }
    return data;
}

Node peek(Stack *s){    //Return top element of the stack.
    Node data = {0, 0, 0};
    if(is_empty(s)){
        printf("Stack empty!\n");
    }
    else{
        data = s->arr[s->top];
    }
    return data;
}

/* Maze route finder */

void maze_route(){     //Function to find the route through the maze.
    Stack s;
    s.top = -1;        //Empty stack.
    int visited[ROW_SIZE][COL_SIZE] = {0};    //Visited array to keep track of cells visited.
    int x = x_start, y = y_start, steps = 0;
    Node n = {x, y, steps};
    push(&s, n);

    while(!is_empty(&s)){     //While stack is not empty.
        Node cur = pop(&s);
        x = cur.x;
        y = cur.y;
        steps = cur.steps;
        if(x == ROW_SIZE-2 && y == COL_SIZE-2){     //Exit condition.
            printf("Route found! Steps taken: %d.\n", steps);
            printf("Route: ");
            while(!is_empty(&s)){
                Node prev = pop(&s);
                printf("(%d, %d) -> ", prev.x, prev.y);
            }
            printf("(%d, %d)\n", x, y);
            return;
        }
        if(!visited[x][y]){     //If cell not visited.
            visited[x][y] = 1;
            if(maze[x-1][y] == 0){    //Check North.
                Node next = {x-1, y, steps+1};
                push(&s, next);
            }
            if(maze[x][y+1] == 0){    //Check East.
                Node next = {x, y+1, steps+1};
                push(&s, next);
            }
            if(maze[x+1][y] == 0){    //Check South.
                Node next = {x+1, y, steps+1};
                push(&s, next);
            }
            if(maze[x][y-1] == 0){    //Check West.
                Node next = {x, y-1, steps+1};
                push(&s, next);
            }
        }
    }
    printf("No route found.\n");
}

/* Main function */

int main(){    //Main function.
    printf("Starting point: (%d, %d)\n", x_start, y_start);
    maze_route();     //Call function to find route through maze.
    return 0;
}