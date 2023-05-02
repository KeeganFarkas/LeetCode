// Alice and Bob have an undirected graph of n nodes and three types of edges:

// Type 1: Can be traversed by Alice only.
// Type 2: Can be traversed by Bob only.
// Type 3: Can be traversed by both Alice and Bob.
// Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional
// edge of type typei between nodes ui and vi, find the maximum number of edges you 
// can remove so that after removing the edges, the graph can still be fully traversed 
// by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from 
// any node, they can reach all other nodes.

// Return the maximum number of edges you can remove, or return -1 if Alice and Bob 
// cannot fully traverse the graph.


//       1
//    / /  \
//   A AB   A
//  / /      \
//  2----AB---3
//   \       /
//    A     B
//     \   /
//       4

// Example 1:
// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
// Output: 2
// Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still 
// be fully traversable by Alice and Bob. Removing any additional edge will not make 
// it so. So the maximum number of edges we can remove is 2.


//       1
//     /| |
//   AB | |
//   /  | |
//  2---A-B---3
//      | |
//      | |
//      | |
//       4

// Example 2:
// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
// Output: 0
// Explanation: Notice that removing any edge will not make the graph fully traversable 
// by Alice and Bob.


//      1
//     /
//    A
//   /
//  2---AB---3
//          /
//         B
//        /
//       4

// Example 3:
// Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
// Output: -1
// Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. 
// Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
 

// Constraints:
// 1 <= n <= 105
// 1 <= edges.length <= min(105, 3 * n * (n - 1) / 2)
// edges[i].length == 3
// 1 <= typei <= 3
// 1 <= ui < vi <= n
// All tuples (typei, ui, vi) are distinct.

// Accepted: 4/30/2023 - 679ms beats 50.73% - 154.3MB beats 43.12%

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // create two disjoint sets, one for Alice and one for Bob
        vector<int> parentA(n + 1);
        vector<int> parentB(n + 1);
        for (int i = 1; i <= n; i++) {
            parentA[i] = i;
            parentB[i] = i;
        }

        // create two size vectors to keep track of the size of each set
        vector<int> sizeA(n + 1, 1);
        vector<int> sizeB(n + 1, 1);

        // sort edges by type
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });

        // create vector to hold the edges that are needed to make the graph 
        // fully traversable
        vector<vector<int>> edgesNeeded;
        for (int i = 0; i < edges.size(); i++) {
            // if the graph is fully traversable by both Alice and Bob, stop
            if (sizeA[find(parentA, 1)] == n && sizeB[find(parentB, 1)] == n) 
                break;
            int type = edges[i][0];
            int node1 = edges[i][1];
            int node2 = edges[i][2];

            // if the edge is of type 3, check if it connects two nodes that are 
            // already connected
            if (type == 3) {
                if (find(parentA, node1) == find(parentA, node2)) continue;
                combine(parentA, sizeA, node1, node2);
                combine(parentB, sizeB, node1, node2);
                edgesNeeded.push_back(edges[i]);
            } else if (type == 1) {
                // if the edge is of type 1, check if it connects two nodes that are 
                // already connected
                if (find(parentA, node1) == find(parentA, node2)) continue;
                combine(parentA, sizeA, node1, node2);
                edgesNeeded.push_back(edges[i]);
            } else {
                // if the edge is of type 2, check if it connects two nodes that are 
                // already connected
                if (find(parentB, node1) == find(parentB, node2)) continue;
                combine(parentB, sizeB, node1, node2);
                edgesNeeded.push_back(edges[i]);
            }
        }
        // if the graph is not fully traversable by both Alice and Bob, return -1
        if (sizeA[find(parentA, 1)] != n || sizeB[find(parentB, 1)] != n) 
            return -1;

        // return the number of edges that were not needed
        return edges.size() - edgesNeeded.size();
    }

    // finds the parent(root) node of x
    int find(vector<int>& parent, int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent, parent[x]);
    }

    // combines the two sets that x and y belong to making the smaller set 
    // a child of the larger set
    void combine(vector<int>& parent, vector<int>& size, int x, int y) {
        x = find(parent, x);
        y = find(parent, y);

        if (x == y) return;

        if (size[x] < size[y]) {
            parent[x] = y;
            size[y] += size[x];
        } else {
            parent[y] = x;
            size[x] += size[y];
        }
    }
};