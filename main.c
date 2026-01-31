// main.c
#include "routing.h"

void simulateEvents() {
    int choice;
    int src, dest, u, v, cost;

    while (1) {
        printf("\n=== Event Simulator ===\n");
        printf("1. Route a Packet\n");
        printf("2. Update Link\n");
        printf("3. Print Routing Tables\n");
        printf("4. Show Path\n");
        printf("5. Exit Simulation\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter src dest: ");
            scanf("%d %d", &src, &dest);
            routePacket(src, dest);
        }
        else if (choice == 2) {
            printf("Enter u v newCost (-1 to remove link): ");
            scanf("%d %d %d", &u, &v, &cost);
            updateLinkCost(u, v, cost);
        }
        else if (choice == 3) {
            printRoutingTables();
        }
        else if (choice == 4) {
            printf("Enter source and destination: ");
            scanf("%d %d", &src, &dest);
            printPath(src, dest);
        }
        else {
            printf("Exiting simulation...\n");
            break;
        }
    }
}

int main() {
    createNetworkTopology();
    initializeRoutingTables();
    printRoutingTables();

    simulateEvents();

    // Free memory
    for (int i = 0; i < numNodes; i++) {
        free(graph[i]);
        free(dist[i]);
        free(goTo[i]);
    }
    free(graph);
    free(dist);
    free(goTo);

    return 0;
}
