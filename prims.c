#include <stdio.h>
#include <limits.h>
int main() {
    int V = 4;
    int graph[4][4] = {
        {0, 2, 3, 0},
        {2, 0, 1, 4},
        {3, 1, 0, 5},
        {0, 4, 5, 0}
    };
    int visited[4] = {0};
    visited[0] = 1;  

    int edges = 0, totalCost = 0;

    while (edges < V - 1) {
        int minWeight = INT_MAX;
        int u = -1, v = -1;

        for (int i = 0; i < V; i++) {
            if (visited[i]) {
                for (int j = 0; j < V; j++) {
                    if (!visited[j] &&
                        graph[i][j] != 0 &&
                        graph[i][j] < minWeight) {

                        minWeight = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (v == -1) {
            printf("Graph is disconnected\n");
            return 0;
        }

        printf("%c - %c : %d\n",
               'A' + u, 'A' + v, minWeight);

        visited[v] = 1;
        totalCost += minWeight;
        edges++;
    }

    printf("Minimum cost = %d\n", totalCost);

    return 0;
}
