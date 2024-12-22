#include "Graph.h"
// Main function with menu
int main() {
    Graph g;
    int choice, u, v, start;

    do {
        cout << "\nMenu: \n";
        cout << "1. Add Vertex\n";
        cout << "2. Add Edge\n";
        cout << "3. Perform DFS\n";
        cout << "4. Perform BFS\n";
        cout << "5. Display Graph\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter vertex to add: ";
            cin >> v;
            g.addVertex(v);
            break;

        case 2:
            cout << "Enter two vertices to add an edge: ";
            cin >> u >> v;
            g.addEdge(u, v);
            break;

        case 3:
            cout << "Enter starting vertex for DFS: ";
            cin >> start;
            cout << "DFS starting from vertex " << start << ": ";
            g.DFS(start);
            break;

        case 4:
            cout << "Enter starting vertex for BFS: ";
            cin >> start;
            cout << "BFS starting from vertex " << start << ": ";
            g.BFS(start);
            break;

        case 5:
            cout << "Graph representation:\n";
            g.display();
            break;

        case 6:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}