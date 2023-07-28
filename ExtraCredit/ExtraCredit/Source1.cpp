#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Structure to represent an edge between two cities
struct Edge {
    string destination;
    int weight;
    Edge(const string& dest, int w) : destination(dest), weight(w) {}
};

// Graph class representing the map of cities and their connections
class Graph {
public:
    // Function to add an edge between two cities
    void addEdge(const string& source, const string& destination, int weight) {
        edges[source].emplace_back(destination, weight);
        edges[destination].emplace_back(source, weight); // For an undirected graph
    }

    // Function to find the shortest path using Dijkstra's algorithm
    vector<string> findShortestPath(const string& start, const string& end) {
        unordered_map<string, int> distance;
        unordered_map<string, string> previous;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

        for (const auto& entry : edges) {
            const string& city = entry.first;
            distance[city] = (city == start) ? 0 : INT_MAX;
            pq.push({ distance[city], city });
        }

        while (!pq.empty()) {
            string current = pq.top().second;
            pq.pop();

            if (current == end)
                break;

            for (const auto& edge : edges[current]) {
                int newDist = distance[current] + edge.weight;
                if (newDist < distance[edge.destination]) {
                    distance[edge.destination] = newDist;
                    previous[edge.destination] = current;
                    pq.push({ newDist, edge.destination });
                }
            }
        }

        vector<string> path;
        string current = end;
        while (current != start) {
            path.push_back(current);
            current = previous[current];
        }
        path.push_back(start);

        reverse(path.begin(), path.end());
        return path;
    }

private:
    unordered_map<string, vector<Edge>> edges;
};

int main() {
    Graph cityMap;
    cityMap.addEdge("A", "B", 3);
    cityMap.addEdge("A", "C", 2);
    cityMap.addEdge("B", "C", 1);
    cityMap.addEdge("B", "D", 4);
    cityMap.addEdge("C", "D", 6);
    cityMap.addEdge("D", "E", 2);
    cityMap.addEdge("C", "E", 5);

    string start = "A";
    string end = "D";

    vector<string> shortestPath = cityMap.findShortestPath(start, end);

    cout << "Shortest path from " << start << " to " << end << ": ";
    for (const string& city : shortestPath) {
        cout << city << " -> ";
    }
    cout << "End" << endl;

    return 0;
}
