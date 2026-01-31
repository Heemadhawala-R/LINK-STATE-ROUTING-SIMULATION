// routing.c
#include "routing.h"

// Global variables
int **graph;
int **dist;
int **goTo;
int numNodes;

// --------------------------------------------------------------
// Function: createNetworkTopology
void createNetworkTopology() {
    int edges, u, v, cost;
    printf("Enter number of nodes: ");
    scanf("%d", &numNodes);

    graph = malloc(numNodes * sizeof(int *));
    dist  = malloc(numNodes * sizeof(int *));
    goTo  = malloc(numNodes * sizeof(int *));
    for (int i = 0; i < numNodes; i++) {
        graph[i] = malloc(numNodes * sizeof(int));
        dist[i]  = malloc(numNodes * sizeof(int));
        goTo[i]  = malloc(numNodes * sizeof(int));
    }

    for (int i = 0; i < numNodes; i++)
        for (int j = 0; j < numNodes; j++)
            graph[i][j] = (i == j) ? 0 : INF;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges in format (u v cost):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &cost);
        graph[u][v] = graph[v][u] = cost;   // Undirected graph
    }
}

// --------------------------------------------------------------
// Function: dijkstra
void dijkstra(int src) {
    int visited[100] = {0};
    for (int i = 0; i < numNodes; i++) {
        dist[src][i] = graph[src][i];
        goTo[src][i] = (graph[src][i] < INF && i != src) ? i : -1;
    }
    visited[src] = 1;

    for (int count = 1; count < numNodes; count++) {
        int u = -1, min = INF;
        for (int i = 0; i < numNodes; i++)
            if (!visited[i] && dist[src][i] < min) {
                min = dist[src][i];
                u = i;
            }
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < numNodes; v++) {
            if (!visited[v] && graph[u][v] < INF &&
                dist[src][u] + graph[u][v] < dist[src][v]) {
                dist[src][v] = dist[src][u] + graph[u][v];
                goTo[src][v] = goTo[src][u];
            }
        }
    }
}

// --------------------------------------------------------------
// Function: initializeRoutingTables
void initializeRoutingTables() {
    for (int i = 0; i < numNodes; i++)
        dijkstra(i);
}

// --------------------------------------------------------------
// Function: printRoutingTables
void printRoutingTables() {
    printf("\n=== Routing Tables ===\n");
    for (int i = 0; i < numNodes; i++) {
        printf("Node %d:\n", i);
        for (int j = 0; j < numNodes; j++) {
            if (i == j) continue;
            if (dist[i][j] == INF)
                printf("  to %d: unreachable\n", j);
            else
                printf("  to %d: go_to=%d, cost=%d\n", j, goTo[i][j], dist[i][j]);
        }
    }
}

// --------------------------------------------------------------
// Function: printPath
void printPath(int src, int dest) {
    if (dist[src][dest] == INF) {
        printf("No path from %d to %d\n", src, dest);
        return;
    }
    int current = src;
    printf("Path from %d to %d: %d", src, dest, src);
    while (current != dest) {
        current = goTo[current][dest];
        printf(" -> %d", current);
    }
    printf(" (Cost: %d)\n", dist[src][dest]);
}

// --------------------------------------------------------------
// Function: updateLinkCost
void updateLinkCost(int u, int v, int cost) {
    graph[u][v] = graph[v][u] = (cost == -1) ? INF : cost;
    initializeRoutingTables();
}

// --------------------------------------------------------------
// Function: routePacket
void routePacket(int src, int dest) {
    if (dist[src][dest] == INF) {
        printf("Packet dropped: No route from %d to %d\n", src, dest);
        return;
    }

    int current = src;
    printf("Routing packet from %d to %d:\n", src, dest);
    printf("  Start at %d\n", current);

    while (current != dest) {
        int next = goTo[current][dest];
        if (next == -1) {
            printf("  Stuck at %d: No next hop. Packet dropped.\n", current);
            return;
        }
        printf("  %d -> %d\n", current, next);
        current = next;
    }

    printf("Packet delivered successfully! (Cost: %d)\n", dist[src][dest]);
}
