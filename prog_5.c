#include <stdio.h>
#include <stdlib.h>

#define MAX 10   // max vertices taken as 10 for simplicity

// using global arrays to avoid passing everywhere
// this is easier to manage for small program
int graph[MAX][MAX];
int seen[MAX];
int totalV;

// queue used only for BFS
int q[MAX];
int f = -1;
int r = -1;

// initialize adjacency matrix and visited array
void setupGraph(int v) {
    totalV = v;
    int i, j;
    for (i = 0; i < totalV; i++) {
        seen[i] = 0;   // marking all vertex unvisited
        for (j = 0; j < totalV; j++) {
            graph[i][j] = 0;   // no edge initially
        }
    }
}

// adding edge for undirected graph
// so both direction marked
void connect(int a, int b) {
    graph[a][b] = 1;
    graph[b][a] = 1;
}

// insert element in queue
void pushQ(int x) {
    if (r == MAX - 1)
        return;   // queue full, ignoring

    if (f == -1)
        f = 0;

    r++;
    q[r] = x;
}

// remove element from queue
int popQ() {
    if (f == -1 || f > r)
        return -1;

    return q[f++];
}

// check queue empty or not
int isQEmpty() {
    if (f == -1 || f > r)
        return 1;
    return 0;
}

// BFS traversal logic
void runBFS(int start) {
    int i;

    // resetting visited array
    for (i = 0; i < totalV; i++)
        seen[i] = 0;

    // resetting queue
    f = -1;
    r = -1;

    printf("BFS starting from %d : ", start);

    seen[start] = 1;
    pushQ(start);

    while (!isQEmpty()) {
        int curr = popQ();
        printf("%d ", curr);

        for (i = 0; i < totalV; i++) {
            if (graph[curr][i] == 1 && seen[i] == 0) {
                seen[i] = 1;
                pushQ(i);
            }
        }
    }
    printf("\n");
}

// DFS recursive function
void dfsUtil(int v) {
    int i;
    printf("%d ", v);
    seen[v] = 1;

    for (i = 0; i < totalV; i++) {
        if (graph[v][i] == 1 && seen[i] == 0) {
            dfsUtil(i);
        }
    }
}

// DFS wrapper function
void runDFS(int start) {
    int i;

    // resetting visited before DFS
    for (i = 0; i < totalV; i++)
        seen[i] = 0;

    printf("DFS starting from %d : ", start);
    dfsUtil(start);
    printf("\n");
}

int main() {
    int i, j;

    // creating graph with 5 vertices
    setupGraph(5);

    // adding edges manually
    connect(0, 1);
    connect(0, 2);
    connect(1, 3);
    connect(2, 3);
    connect(2, 4);
    connect(3, 4);

    printf("Adjacency Matrix is:\n");
    for (i = 0; i < totalV; i++) {
        for (j = 0; j < totalV; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // calling BFS and DFS
    runBFS(0);
    runDFS(0);

    return 0;
}
