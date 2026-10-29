
#include <stdio.h>
#include <limits.h>

#define MAX 10
#define INF INT_MAX

const char *cities[MAX] = {
    "Central Bus Stand",
    "Railway Station",
    "Airport",
    "City Hospital",
    "College",
    "Shopping Mall"
};

int graph[MAX][MAX] = {0};
int n = 6;

/* Display all available locations */
void displayLocations(void) {
    int i;

    printf("\n===== AVAILABLE LOCATIONS =====\n");

    for (i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, cities[i]);
    }
}

/* Add a road between two locations */
void addRoad(void) {
    int u, v, distance;

    displayLocations();

    printf("\nEnter starting location number: ");
    if (scanf("%d", &u) != 1) return;

    printf("Enter destination location number: ");
    if (scanf("%d", &v) != 1) return;

    printf("Enter distance between them (km): ");
    if (scanf("%d", &distance) != 1) return;

    if (u < 1 || u > n || v < 1 || v > n ||
        u == v || distance <= 0) {
        printf("Invalid input! Please try again.\n");
        return;
    }

    graph[u - 1][v - 1] = distance;
    graph[v - 1][u - 1] = distance;

    printf("Road added successfully!\n");
}

/* Find the unvisited location with minimum distance */
int minimumDistance(int dist[], int visited[]) {
    int min = INF;
    int minIndex = -1;
    int i;

    for (i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

/* Display the shortest route */
void shortestRoute(void) {
    int source, destination;
    int dist[MAX], visited[MAX] = {0};
    int parent[MAX];
    int i, count, u, v;
    int path[MAX], pathLength = 0;

    displayLocations();

    printf("\nEnter starting location number: ");
    if (scanf("%d", &source) != 1) return;

    printf("Enter destination location number: ");
    if (scanf("%d", &destination) != 1) return;

    if (source < 1 || source > n ||
        destination < 1 || destination > n) {
        printf("Invalid location number!\n");
        return;
    }

    source--;
    destination--;

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (count = 0; count < n - 1; count++) {
        u = minimumDistance(dist, visited);

        if (u == -1) break;

        visited[u] = 1;

        for (v = 0; v < n; v++) {
            if (!visited[v] &&
                graph[u][v] > 0 &&
                dist[u] != INF &&
                dist[u] <= INF - graph[u][v] &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    if (dist[destination] == INF) {
        printf("\nNo route available between these locations.\n");
        printf("Please add the required roads first.\n");
        return;
    }

    v = destination;

    while (v != -1 && pathLength < MAX) {
        path[pathLength++] = v;
        v = parent[v];
    }

    printf("\n===== SHORTEST ROUTE =====\n");

    for (i = pathLength - 1; i >= 0; i--) {
        printf("%s", cities[path[i]]);

        if (i > 0) {
            printf(" -> ");
        }
    }

    printf("\nTotal Distance: %d km\n", dist[destination]);
}

/* Main menu */
int main(void) {
    int choice;

    printf("====================================\n");
    printf("     SMART CITY ROUTE FINDER\n");
    printf("====================================\n");

    while (1) {
        printf("\n1. Display Available Locations\n");
        printf("2. Add Road and Distance\n");
        printf("3. Find Shortest Route\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please restart the program.\n");
            break;
        }

        switch (choice) {
            case 1:
                displayLocations();
                break;

            case 2:
                addRoad();
                break;

            case 3:
                shortestRoute();
                break;

            case 4:
                printf("Thank you for using Smart City Route Finder!\n");
                return 0;

            default:
                printf("Invalid choice! Enter a number from 1 to 4.\n");
        }
    }

    return 0;
}
