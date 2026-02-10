#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5   // total vertices in graph

/* find vertex having minimum distance */
int findMinDist(int distArr[], bool done[])
{
    int minVal = INT_MAX;
    int idx = -1;

    for (int i = 0; i < V; i++)
    {
        if (done[i] == false && distArr[i] <= minVal)
        {
            minVal = distArr[i];
            idx = i;
        }
    }
    return idx;
}

/* print final shortest distance */
void showResult(int distArr[])
{
    printf("Vertex   Distance from source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, distArr[i]);
}

/* dijkstra logic */
void runDijkstra(int cost[V][V], int source)
{
    int distArr[V];
    bool done[V];

    // initialize arrays
    for (int i = 0; i < V; i++)
    {
        distArr[i] = INT_MAX;
        done[i] = false;
    }

    distArr[source] = 0;   // source distance is zero

    for (int step = 0; step < V - 1; step++)
    {
        int u = findMinDist(distArr, done);
        done[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!done[v] && cost[u][v] != 0 && distArr[u] != INT_MAX)
            {
                if (distArr[u] + cost[u][v] < distArr[v])
                    distArr[v] = distArr[u] + cost[u][v];
            }
        }
    }

    showResult(distArr);
}

int main()
{
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    runDijkstra(graph, 0);   // starting from node 0

    return 0;
}
