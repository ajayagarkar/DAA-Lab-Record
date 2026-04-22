#include <stdio.h>
#define MAX 10
#define INF 9999

int main() {
    int n, i, j, u, v, w;
    int graph[MAX][MAX], dist[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            // Convert 0 (no edge) to INF
            if(graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Step 1: Initialize distances
    for(i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;

    // Step 2: Relax edges (n-1 times)
    for(i = 1; i <= n - 1; i++) {
        for(u = 0; u < n; u++) {
            for(v = 0; v < n; v++) {
                if(graph[u][v] != INF && dist[u] != INF &&
                   dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Step 3: Check for negative weight cycle
    for(u = 0; u < n; u++) {
        for(v = 0; v < n; v++) {
            if(graph[u][v] != INF && dist[u] != INF &&
               dist[u] + graph[u][v] < dist[v]) {
                printf("Negative weight cycle detected!\n");
                return 0;
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
