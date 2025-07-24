//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10
#define MAX_LENGTH 100

typedef struct {
    int x;
    int y;
} Point;

int map[ROW][COL] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};

Point start = {0, 0};
Point end = {9, 9};

typedef struct {
    Point list[MAX_LENGTH];
    int length;
} PointList;

int gn[ROW][COL];
int hn[ROW][COL];
int fn[ROW][COL];
int mark[ROW][COL];

PointList opened_list;
PointList closed_list;

void CalculateHn() {
    int i, j;
    int dx, dy;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            dx = i - end.x;
            dy = j - end.y;

            dx = dx < 0 ? -dx : dx;
            dy = dy < 0 ? -dy : dy;

            hn[i][j] = dx + dy;
        }
    }
}

int IsInClosedList(Point pt) {
    int i;
    for (i = 0; i < closed_list.length; i++) {
        if (closed_list.list[i].x == pt.x && closed_list.list[i].y == pt.y) {
            return 1;
        }
    }
    return 0;
}

int IsInOpenedList(Point pt) {
    int i;
    for (i = 0; i < opened_list.length; i++) {
        if (opened_list.list[i].x == pt.x && opened_list.list[i].y == pt.y) {
            return i;
        }
    }
    return -1;
}

void AddToOpenedList(Point pt) {
    int idx;
    if ((idx = IsInOpenedList(pt)) != -1) {
        if (gn[pt.x][pt.y] < gn[opened_list.list[idx].x][opened_list.list[idx].y]) {
            opened_list.list[idx] = pt;
        }
    } else {
        opened_list.list[opened_list.length++] = pt;
    }
}

int GetMinFnPoint() {
    Point min_pt;
    int min_fn = 0x7fffffff;
    int idx = 0, i;

    for (i = 0; i < opened_list.length; i++) {
        min_pt = opened_list.list[i];
        if (fn[min_pt.x][min_pt.y] < min_fn) {
            min_fn = fn[min_pt.x][min_pt.y];
            idx = i;
        }
    }

    return idx;
}

void GetSurroundPoints(Point pt, Point around[4], int *count) {
    if (pt.x - 1 >= 0  && map[pt.x - 1][pt.y] == 0) {
        around[*count].x = pt.x - 1;
        around[*count].y = pt.y;
        (*count)++;
    }

    if (pt.x + 1 < ROW && map[pt.x + 1][pt.y] == 0) {
        around[*count].x = pt.x + 1;
        around[*count].y = pt.y;
        (*count)++;
    }

    if (pt.y - 1 >= 0 && map[pt.x][pt.y - 1] == 0) {
        around[*count].x = pt.x;
        around[*count].y = pt.y - 1;
        (*count)++;
    }

    if (pt.y + 1 < COL && map[pt.x][pt.y + 1] == 0) {
        around[*count].x = pt.x;
        around[*count].y = pt.y + 1;
        (*count)++;
    }
}

void AStar() {
    int i, j;
    Point pt, cur_pt, around[4];
    int count;

    opened_list.list[opened_list.length++] = start;
    while (opened_list.length > 0) {
        i = GetMinFnPoint();
        cur_pt = opened_list.list[i];

        if (cur_pt.x == end.x && cur_pt.y == end.y) {
            return;
        }

        if (closed_list.length >= MAX_LENGTH) {
            printf("Too long!\n");
            return;
        }

        opened_list.list[i] = opened_list.list[--opened_list.length];
        closed_list.list[closed_list.length++] = cur_pt;
        mark[cur_pt.x][cur_pt.y] = 1;

        GetSurroundPoints(cur_pt, around, &count);
        for (j = 0; j < count; j++) {
            pt = around[j];

            if (IsInClosedList(pt)) {
                continue;
            }

            gn[pt.x][pt.y] = gn[cur_pt.x][cur_pt.y] + 1;
            fn[pt.x][pt.y] = gn[pt.x][pt.y] + hn[pt.x][pt.y];

            if (!mark[pt.x][pt.y]) {
                AddToOpenedList(pt);
                mark[pt.x][pt.y] = 1;
            }
        }
    }
}

void PrintPath() {
    int i;
    Point pt = end;
    Point path[MAX_LENGTH];
    int path_length = 0;

    while (pt.x != start.x || pt.y != start.y) {
        path[path_length++] = pt;
        pt = closed_list.list[IsInClosedList(pt) - 1];
    }

    path[path_length++] = pt;

    for (i = path_length - 1; i >= 0; i--) {
        printf("(%d,%d)", path[i].x, path[i].y);
        if (i > 0) {
            printf(" -> ");
        }
    }
    printf("\n");
}

int main() {
    int i, j;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if ((i + j) % 2 == 0) {
                map[i][j] = 1;
            }
        }
    }

    CalculateHn();

    AStar();

    printf("PATH: ");
    PrintPath();

    return 0;
}