//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 100

int adj_matrix[MAX_NODES][MAX_NODES];   //Adjacency Matrix to represent circuit
int node_voltage[MAX_NODES];            //Array to store node voltages
int node_number;

void add_component(int node1, int node2, int resistance);
void delete_component(int node1, int node2);
void print_circuit();
void solve_circuit();

void main() {
   int choice,node1,node2,resistance;
   int done = 0;
   node_number = 0;

   //Initialise adjacency matrix with zeroes.
   for(int i=0; i<MAX_NODES; i++) {
      for(int j=0; j<MAX_NODES;j++) {
         adj_matrix[i][j] = 0;
      }
   }

   while(!done) {
      printf("\n1. Add Component\n2. Delete Component\n3. Print Circuit\n4. Solve Circuit\n5. Exit\nEnter your choice: ");
      scanf("%d",&choice);
      switch(choice) {
         case 1:
            printf("Enter node1: ");
            scanf("%d",&node1);
            printf("Enter node2: ");
            scanf("%d",&node2);
            printf("Enter resistance: ");
            scanf("%d",&resistance);
            add_component(node1,node2,resistance);
            break;
         case 2:
            printf("Enter node1: ");
            scanf("%d",&node1);
            printf("Enter node2: ");
            scanf("%d",&node2);
            delete_component(node1,node2);
            break;
         case 3:
            print_circuit();
            break;
         case 4:
            solve_circuit();
            break;
         case 5:
            done = 1;
            break;
         default:
            printf("Invalid choice. Try again.\n");
            break;
      }
   }
}

//Function to add resistor as an edge in the adjacency matrix
void add_component(int node1, int node2, int resistance) {
   adj_matrix[node1][node2] = resistance;
   adj_matrix[node2][node1] = resistance;
}

//Function to delete an edge from the adjacency matrix
void delete_component(int node1, int node2) {
   adj_matrix[node1][node2] = 0;
   adj_matrix[node2][node1] = 0;
}

//Function to print the circuit in a human-readable format
void print_circuit() {
   printf("\nCircuit:\n");
   for(int i=0;i<node_number;i++) {
      printf("Node%d Voltage: %d\n",i,node_voltage[i]);
      for(int j=0;j<node_number;j++) {
         if(adj_matrix[i][j] != 0) {
            printf("\tNode%d -- %d ohm -- Node%d\n",i,adj_matrix[i][j],j);
         }
      }
      printf("\n");
   }
}

//Function to solve the circuit using Kirchhoff's laws and output node voltages
void solve_circuit() {
   int num_edges,edge_count = 0;
   int edges[MAX_NODES];
   int edge_resistance[MAX_NODES];

   //Get the number of edges and store them in an array
   for(int i=0;i<node_number;i++) {
      for(int j=0;j<i;j++) {
         if(adj_matrix[i][j] !=0) {
            edges[edge_count] = i*node_number + j;
            edge_resistance[edge_count] = adj_matrix[i][j];
            edge_count++;
         }
      }
   }

   num_edges = edge_count;

   //Build the matrix equation for Kirchhoff's laws
   int A[MAX_NODES][MAX_NODES];
   int b[MAX_NODES];

   for(int i=0;i<node_number-1;i++) {
      for(int j=0;j<node_number-1;j++) {
         A[i][j] = 0;
      }
      b[i] = 0;
   }

   //Equation for each node except the last
   for(int i=0;i<node_number-1;i++) {
      //Add up all resistances that are connected to the node
      int total_resistance = 0;
      for(int j=0;j<num_edges;j++) {
         if(edges[j] / node_number == i) {
            total_resistance += edge_resistance[j];
         }
         if(edges[j] % node_number == i) {
            total_resistance += edge_resistance[j];
         }
      }

      //Loop through all edges connected to the node
      for(int j=0;j<num_edges;j++) {
         //If edge is connected to the node on one end
         if(edges[j] / node_number == i || edges[j] % node_number == i) {
            int u = edges[j] / node_number;
            int v = edges[j] % node_number;
            if(i == u) {
               A[i][v] = -(edge_resistance[j]*10/total_resistance);
            }
            else {
               A[i][u] = -(edge_resistance[j]*10/total_resistance);
            }
            b[i] = 0;
         }
      }
   }

   //Add equation for last node
   for(int i=0;i<num_edges;i++) {
      if(edges[i] / node_number == node_number-1) {
         b[node_number-1] -= edge_resistance[i];
      }
      if(edges[i] % node_number == node_number-1) {
         b[node_number-1] += edge_resistance[i];
      }
   }

   //Solve the matrix equation
   for(int k=0;k<node_number-1;k++) {
      for(int i=k+1;i<node_number-1;i++) {
         double factor = A[i][k] / A[k][k];
         for(int j=k+1;j<node_number-1;j++) {
            A[i][j] = A[i][j] - factor*A[k][j];
         }
         b[i] = b[i] - factor*b[k];
      }
   }

   node_voltage[node_number-1] = 0;
   for(int i=node_number-2;i>=0;i--) {
      double s = 0;
      for(int j=i+1;j<node_number-1;j++) {
         s += A[i][j] * node_voltage[j];
      }
      node_voltage[i] = (b[i] - s) / A[i][i];
   }

   printf("\nNode Voltages:\n");
   for(int i=0;i<node_number;i++) {
      printf("Node%d: %d V\n",i,node_voltage[i]);
   }
}