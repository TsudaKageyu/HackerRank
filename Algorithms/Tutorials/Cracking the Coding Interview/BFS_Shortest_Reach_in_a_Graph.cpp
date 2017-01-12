// https://www.hackerrank.com/challenges/ctci-bfs-shortest-reach

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Graph {
private:
    int size;
    vector<bool> edges;

public:
    Graph(int n) : size(n), edges(n * n) {

    }

    void add_edge(int u, int v) {
        edges[u * size + v] = true;
        edges[v * size + u] = true;
    }

    vector<int> shortest_reach(int start) {
        vector<int> nodes;
        nodes.push_back(start);

        vector<int> reaches(size, -1);
        find_reaches(nodes, 0, reaches);

        return reaches;
    }

private:
    void find_reaches(const vector<int> &nodes, int depth, vector<int> &reaches) {
        for (auto x : nodes)
            reaches[x] = depth * 6;

        vector<int> nextNodes;
        for (auto x : nodes) {
            for (int y = 0; y < size; ++y) {
                if (edges[x * size + y] && reaches[y] < 0)
                    nextNodes.push_back(y);
            }
        }

        if (!nextNodes.empty())
            find_reaches(nextNodes, depth + 1, reaches);
    }
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
        int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
