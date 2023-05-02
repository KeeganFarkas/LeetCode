// An undirected graph of n nodes is defined by edgeList, where 
// edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and vi with 
// distance disi. Note that there may be multiple edges between two nodes.

// Given an array queries, where queries[j] = [pj, qj, limitj], your task is 
// to determine for each queries[j] whether there is a path between pj and qj 
// such that each edge on the path has a distance strictly less than limitj .

// Return a boolean array answer, where answer.length == queries.length and 
// the jth value of answer is true if there is a path for queries[j] is true, 
// and false otherwise.


//         e2
//       4/  \8
//       /    \
//     e1------e0
//        2, 16

// Example 1:
// Input: n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], 
//        queries = [[0,1,2],[0,2,5]]
// Output: [false,true]
// Explanation: The above figure shows the given graph. Note that there are 
// two overlapping edges between 0 and 1 with distances 2 and 16.
// For the first query, between 0 and 1 there is no path where each distance 
// is less than 2, thus we return false for this query.
// For the second query, there is a path (0 -> 1 -> 2) of two edges with 
// distances less than 5, thus we return true for this query.


//          e4      e0
//       13/       /
//        /       /10
//       e3     e1
//        9\    /
//          \  /5
//           e2

// Example 2:
// Input: n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], 
//        queries = [[0,4,14],[1,4,13]]
// Output: [true,false]
// Exaplanation: The above figure shows the given graph.
 

// Constraints:
// 2 <= n <= 10^5
// 1 <= edgeList.length, queries.length <= 10^5
// edgeList[i].length == 3
// queries[j].length == 3
// 0 <= ui, vi, pj, qj <= n - 1
// ui != vi
// pj != qj
// 1 <= disi, limitj <= 10^9
// There may be multiple edges between two nodes.

// Accepted: 4/29/2023 - 684ms beats 27.80% - 110.1MB beats 78.84%

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, 
                                                vector<vector<int>>& queries) {
        vector<bool> answer(queries.size());
        vector<int> parent(n);
        for (int i = 1; i < n; ++i) parent[i] = i;
        vector<int> size(n, 1);
        for (int i = 0; i < queries.size(); ++i) queries[i].push_back(i);
        vector<int> temp;

        sort(queries.begin(), queries.end(), 
            [](const vector<int>& a, const vector<int>& b) {
                return a[2] < b[2];
            });
        sort(edgeList.begin(), edgeList.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[2] < b[2];
            });

        int j = 0;
        for (int i = 0; i < queries.size(); ++i) {
            int limit = queries[i][2];

            while (j < edgeList.size()) {
                if (edgeList[j][2] < limit) {
                    combine(edgeList[j][0], edgeList[j][1], parent, size);
                    ++j;
                } else {
                    break;
                }
            }

            if (find(queries[i][0], parent) == find(queries[i][1], parent)) {
                answer[queries[i][3]] = true;
            }
        }

        return answer;
    }

    int find(int x, vector<int>& parent) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }

    void combine(int x, int y, vector<int>& parent, vector<int>& size) {
        x = find(x, parent);
        y = find(y, parent);

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