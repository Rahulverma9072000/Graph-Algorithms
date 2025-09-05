#include <iostream>
#include <list>
#include <vector>
using namespace std;
// https://leetcode.com/problems/find-center-of-star-graph/description/
//This is using vector instead of using array of list 
int findCenter(vector<vector<int>> &edges)
{
    int n = edges.size(); // number of edges
    vector<list<int>> adjList(n + 2);

    // build graph
    for (int i = 0; i < n; i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }

    // find center
    for (int i = 1; i <= n + 1; i++)
    {
        if (adjList[i].size() == n)
        {
            return i;
        }
    }
    return -1;
}

int findCenter(vector<vector<int>> &edges)
{
    // Undirected Star Graph consisting of n nodes 1 to n
    // Center Node will be connected with n-1 edges
    // Form a graph
    int n = edges.size(); // THere is n number of edges
    // What will be the number of vertices in Star graph
    // number of edges + 1 : vertices
    list<int> *adjList = new list<int>[n + 2];
    // Form the graph
    for (int i = 0; i < n; i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
    // Now form the result
    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << adjList[i].size() << endl;
        if ((adjList[i].size()) == n)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> edges[i][j];
        }
    }
    cout << findCenter(edges) << endl;
    return 0;
}