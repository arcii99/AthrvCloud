//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_NODES 50
#define MAX_ITERATIONS 5000
#define MAX_ERROR 0.005

int numNodes;
double c[MAX_NODES][MAX_NODES], g[MAX_NODES][MAX_NODES], b[MAX_NODES], v[MAX_NODES], oldV[MAX_NODES];
int groundNode;

void initialize();
void input();
void solve();
void display();

int main()
{
    printf("\nCIRCUIT SIMULATOR\n");
    initialize();
    input();
    solve();
    display();
    return 0;
}

void initialize()
{
    for(int i = 0; i<MAX_NODES; i++)
    {
        for(int j = 0; j<MAX_NODES; j++)
        {
            c[i][j] = 0;
            g[i][j] = 0;
        }
        b[i] = 0;
        v[i] = 0;
        oldV[i] = 0;
    }
    numNodes = 0;
    groundNode = 0;
}

void input()
{
    printf("\nEnter the number of nodes: ");
    scanf("%d", &numNodes);
    printf("\nEnter the nodes connected by the capacitor(Ci): "); //Input node pairs
    int node1, node2;
    double capacitance;
    while(1)
    {
        scanf("%d%d%lf", &node1, &node2, &capacitance);
        if(node1 == 0 && node2 == 0 && capacitance == 0)
        {
            break;
        }
        else
        {
            c[node1][node1] += capacitance;
            c[node2][node2] += capacitance;
            c[node1][node2] -= capacitance;
            c[node2][node1] -= capacitance;
        }
    }
    printf("\nEnter the nodes connected by the resistance(Ri) and current source(Is): "); //Input node pairs or node and current pair
    int nodes[2];
    double val;
    char type;
    while(1)
    {
        scanf("%d%d", &nodes[0], &nodes[1]);
        if(nodes[0] == 0 && nodes[1] == 0)
        {
            break;
        }
        else
        {
            scanf("%c", &type);
            switch(type)
            {
                case 'R': printf("Enter resistance value: ");
                          scanf("%lf", &val);
                          g[nodes[0]][nodes[0]] += 1/val;
                          g[nodes[0]][nodes[1]] -= 1/val;
                          g[nodes[1]][nodes[0]] -= 1/val;
                          g[nodes[1]][nodes[1]] += 1/val;
                          break;
                case 'I': printf("Enter current value: ");
                          scanf("%lf", &val);
                          b[nodes[0]] -= val;
                          b[nodes[1]] += val;
                          break;
            }
        }
    }
    printf("\nEnter the ground node: "); //Enter the ground node index
    scanf("%d", &groundNode);
}

void solve()
{
    double error = 1;
    int iter = 0;
    while(error > MAX_ERROR && iter < MAX_ITERATIONS)
    {
        for(int i = 1; i<=numNodes; i++)
        {
            b[i] = 0;
            for(int j = 1; j<=numNodes; j++)
            {
                b[i] += g[i][j]*(oldV[j]);
            }
            v[i] = (b[i]*c[i][i] + oldV[i])/c[i][i];
        }
        error = 0;
        for(int i = 1; i<=numNodes; i++)
        {
            if(v[i] != 0)
            {
                double diff = fabs((v[i] - oldV[i])/v[i]);
                if(diff > error)
                {
                    error = diff;
                }
            }
        }
        for(int i = 1; i<=numNodes; i++)
        {
            oldV[i] = v[i];
        }
        iter++;
    }
}

void display()
{
    printf("\nNode Voltages: ");
    for(int i = 1; i<=numNodes; i++)
    {
        printf("\nNode %d: %lf", i, v[i]);
    }
}