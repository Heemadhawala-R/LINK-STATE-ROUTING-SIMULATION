// routing.h
#ifndef ROUTING_H
#define ROUTING_H

#include <stdio.h>
#include <stdlib.h>

#define INF 9999

// Global pointers
extern int **graph;   // Adjacency matrix
extern int **dist;    // Distance table
extern int **goTo;    // Routing table
extern int numNodes;

// Function declarations
void createNetworkTopology();
void dijkstra(int src);
void initializeRoutingTables();
void printRoutingTables();
void printPath(int src, int dest);
void updateLinkCost(int u, int v, int cost);
void routePacket(int src, int dest);

#endif
