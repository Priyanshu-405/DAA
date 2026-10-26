#include <stdio.h>
#include <limits.h>
#define V 5
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int visited[V] = {0};

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);

        if (u == -1)
            break;
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] &&
                graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tShortest Distance from Source\n");

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("%d\tUnreachable\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 0, 5},
        {10, 0, 1, 0, 2},
        {0, 1, 0, 4, 0},
        {0, 0, 4, 0, 3},
        {5, 2, 0, 3, 0}
    };
    int source = 0;
    dijkstra(graph, source);
    return 0;
}