// https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Connected Trio is a set of 3 nodes where there is edge between every pair of them
// Degree of connected trio is the number of edges where one endpoint is in the trio
int minTrioDegree(int n, vector<vector<int>> &edges)
{
    vector<int> degrees(n + 1, 0); // graph is undirected
    vector<vector<bool>> data(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < edges.size(); i++)
    {
        degrees[edges[i][0]] += 1;
        degrees[edges[i][1]] += 1;
        data[edges[i][0]][edges[i][1]] = true;
        data[edges[i][1]][edges[i][0]] = true;
    }
    // Now Check all the trios present
    // int minDegree = n; //Using n is giving wrong answer
    // So for any node : there can be n-1  edges max
    // 3*(n-1) - 6 = 3n - 9 , so for any value of n we can have values greater equal to n
    int minDegree = INT_MAX;
    for (int i = 1; i <= (n - 2); i++)
    {
        for (int j = i + 1; j <= (n - 1); j++)
        {
            for (int k = j + 1; k <= n; k++)
            {
                // Now See (i,j,k) forms a trio
                if (data[i][j] && data[j][k] && data[k][i])
                {
                    // See the degree here
                    int currDegree = degrees[i] + degrees[j] + degrees[k] - 6;
                    minDegree = min(minDegree, currDegree);
                }
            }
        }
    }
    return (minDegree == INT_MAX ? -1 : minDegree);
}
//  n = 7, edges = [[1,3],[4,1],[4,3],[2,5],[5,6],[6,7],[7,5],[2,6]]
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> edges[i][j];
        }
    }
    cout << minTrioDegree(n, edges) << endl;
    return 0;
}