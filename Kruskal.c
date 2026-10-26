#include <stdio.h>
#define V 4
#define E 5
int parent[V];
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void unionSet(int u, int v) {
    int a = find(u);
    int b = find(v);
    parent[a] = b;
}

int main() {
    int graph[E][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int i, j, temp;
    int cost = 0, count = 0;

    for (i = 0; i < E - 1; i++) {
        for (j = 0; j < E - i - 1; j++) {
            if (graph[j][2] > graph[j + 1][2]) {
                for (int k = 0; k < 3; k++) {
                    temp = graph[j][k];
                    graph[j][k] = graph[j + 1][k];
                    graph[j + 1][k] = temp;
                }
            }
        }
    }

    for (i = 0; i < V; i++)
        parent[i] = i;

    printf("Edges in Minimum Spanning Tree:\n");

    for (i = 0; i < E && count < V - 1; i++) {
        int u = graph[i][0];
        int v = graph[i][1];
        int w = graph[i][2];

        if (find(u) != find(v)) {
            printf("%d - %d : %d\n", u, v, w);
            unionSet(u, v);
            cost += w;
            count++;
        }
    }

    printf("Minimum Cost = %d\n", cost);

    return 0;
}