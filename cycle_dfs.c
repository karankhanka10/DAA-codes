#include<stdio.h>
#include<stdlib.h>
 
int s[5], j=0, res[5]; /*GLOBAL VARIABLES */
 

 
void dfs(int u, int n, int a[][5]) { /* DFS */
 
    int v;
    s[u] = 1;
    for (v = 0; v < n ; v++) {
        if (a[u][v] == 1 && s[v] == 0) {
            dfs(v, n, a);
        }
    }
    j += 1;
    res[j] = u;
}
 
void topological_order(int n, int a[][5]) { /* TO FIND TOPOLOGICAL ORDER*/
 
    int i, u;
    for (i = 0; i < n-1; i++) {
        s[i] = 0;
    }
    j = 0;
    for (u = 0; u < n; u++) {
        if (s[u] == 0) {
            dfs(u, n, a);
        }
    }
    return;
}
int main() {
    int n=5, i, j;
    int a[][5] = {
        {0, 0, 1, 0, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };
 
    printf("\t\tAdjacency Matrix of the graph\n"); /* PRINT ADJACENCY MATRIX */
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("\t%d", a[i][j]);
        }
        printf("\n");
    }
    printf("\nTopological order:\n");
 
    topological_order(n, a);
 
    for (i = n; i >= 1; i--) {
        printf("-->%d", res[i]);
    }
    return 0;
}