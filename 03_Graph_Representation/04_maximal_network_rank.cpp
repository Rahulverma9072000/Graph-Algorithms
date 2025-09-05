// https://leetcode.com/problems/maximal-network-rank/description/
#include <iostream>
#include <algorithm>
#include<list>
#include <vector>
using namespace std;


int maximalNetworkRank(int n, vector<vector<int>> &roads)
{
    //make a Adjacency Matrix 
    vector<vector<int> > data(n,vector<int> (n+1,0));
    for(int i = 0;i < roads.size();i++){
        data[roads[i][1]][roads[i][0]] = 1;
        data[roads[i][0]][roads[i][1]] = 1;
        //Making degree as last colloumn 
        data[roads[i][0]][n] +=1;
        data[roads[i][1]][n] += 1;
    }
    //Form the result 
    int maxNetworkRank = 0;
    for(int i = 0;i < n;i++){
        for(int j = i+1;j < n;j++){
            //We have pair (i,j)
            int currNetworkRank = data[i][n] + data[j][n] - data[i][j];
            maxNetworkRank = max(currNetworkRank,maxNetworkRank);
        }
    }
    return maxNetworkRank;
}

//Optimisation : 
//We can make a vector that store degree and use 2d matrix of bool 
int maximalNetworkRank1(int n, vector<vector<int>>& roads) {
    vector<int> degree(n, 0);
    vector<vector<bool>> connected(n, vector<bool>(n, false));

    for (auto &road : roads) {
        int u = road[0], v = road[1];
        degree[u]++, degree[v]++;
        connected[u][v] = connected[v][u] = true;
    }

    int maxRank = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int rank = degree[i] + degree[j] - (connected[i][j] ? 1 : 0);
            maxRank = max(maxRank, rank);
        }
    }
    return maxRank;
}

int main(){
    int n,m;cin>>n>>m;
    vector<vector<int> > roads(m,vector<int> (2,0));
    for(int i = 0;i < m;i++){
        for(int j = 0;j < 2;j++){
            cin>>roads[i][j];
        }
    }
    cout<<maximalNetworkRank(n,roads)<<endl;
    return 0;
}