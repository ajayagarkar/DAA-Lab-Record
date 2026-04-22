#include <stdio.h>
#define MAX 10
#define INF 9999

int main() {
    int n, i, j, u, v, min;
    int graph[MAX][MAX], dist[MAX], visited[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if(graph[i][j] == 0 && i != j)
                graph[i][j] = INF; // No edge
        }
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Initialize
    for(i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    // Dijkstra's Algorithm
    for(i = 0; i < n - 1; i++) {
        min = INF;

        // Find minimum distance vertex
        for(j = 0; j < n; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        // Update distances of neighbors
        for(v = 0; v < n; v++) {
            if(!visited[v] && graph[u][v] != INF &&
               dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Output
    printf("\nShortest distances from source %d:\n", source);
    for(i = 0; i < n; i++) {
        printf("To %d -> %d\n", i, dist[i]);
    }

    return 0;
}
