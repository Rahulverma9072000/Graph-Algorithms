#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
//Adjacency List Representation Node Class , Each Node represents city 

class Node
{
public:
    string name;
    list<string> nbrs;
    Node(string name)
    {
        this->name = name;
    }
};

class Graph
{
    // All Nodes
    // Hashmap(String,Node*)
    unordered_map<string, Node *> m;

public:
    Graph(vector<string> cities)
    {
        for (auto city : cities)
        {
            m[city] = new Node(city);
        }
    }

    void AddEdge(string x, string y, bool undir = false)
    {
        m[x]->nbrs.push_back(y);
        if (undir)
        {
            m[y]->nbrs.push_back(x);
        }
    }

    void printAdjList()
    {
        for (auto cityPair : m)
        {
            auto city = cityPair.first;
            cout<<city<<"-->";
            Node *node = cityPair.second;
            for (auto nbr : node->nbrs)
            {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    vector<string> cities = {"Delhi", "London", "Paris", "NewYork"};
    Graph g(cities);
    g.AddEdge("Delhi", "London");
    g.AddEdge("NewYork", "London");
    g.AddEdge("Delhi", "Paris");
    g.AddEdge("Paris", "NewYork");
    g.printAdjList();
    return 0;
}