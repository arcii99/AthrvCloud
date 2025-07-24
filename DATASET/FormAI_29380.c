//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_N 10000
#define MAX_M 100000
#define MAX_K 10

int n, m, k;          // n:vertex number; m:edge number; k:node type number
int head[MAX_N];      // the start of each chain
int ver[MAX_M], nxt[MAX_M], edge[MAX_M];  // ver represents the vertex, nxt represents the next edge, edge represents the weight of the edge.

int map[MAX_N][MAX_K];   //vertex property table

int vis[MAX_N];     // array used to record whether the node has entered the queue
int cnt[MAX_N];     // array used to count the number of edges that point to the node
int presum[MAX_N];  // array used to record the prefix sum of cnt

int queue[MAX_N], front, tail;  // queue

void add(int a, int b, int c) {   //add edge
    ver[++m] = b, edge[m] = c, nxt[m] = head[a], head[a] = m;
}

void init() {  //initialize
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    memset(presum, 0, sizeof(presum));
    memset(map, -1, sizeof(map));
    front = tail = 0;
}

void topoSort() {  //topological sort
    for(int i = 1; i <= n; i++) if(cnt[i] == 0) queue[++tail] = i;
    while(front < tail) {
        int x = queue[++front];
        vis[x] = 1;
        for(int i = head[x]; ~i; i = nxt[i]) {
            int y = ver[i];
            cnt[y]--, presum[y] += presum[x] + edge[i];
            if(cnt[y] == 0) queue[++tail] = y;
        }
    }
}

int main() {
    printf("Welcome to the Intrusion Detection System!\n");
    printf("Please input the number of vertices, edge number and node type number:\n");
    scanf("%d%d%d", &n, &m, &k);
    printf("Please input the vertex properties (one line for each vertex):\n");
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < k; j++) scanf("%d", &map[i][j]);
    }
    init();
    printf("Please input the edges (start_node, end_node, weight):\n");
    for(int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        cnt[b]++;
    }
    topoSort();    //topological sort
    printf("The prefix sum of all nodes:\n");
    for(int i = 1; i <= n; i++) printf("%d\n", presum[i]);
    printf("\n\nIntrusion Detection Complete. Have a nice day!\n");
    return 0;
}