#include <stdio.h>
#define MAX 10
#define INF 9999

int main() {
    int n, i, j, k;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if(graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    // Floyd-Warshall Algorithm
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    // Output
    printf("\nShortest distance matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(graph[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
