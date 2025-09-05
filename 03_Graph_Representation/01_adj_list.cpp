#include <iostream>
using namespace std;
#include <list> //Doubly Linked List

class Graph
{
    int V;
    list<int> *l; // Pointer to an Array of list

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        // If its undirected graph than reverse will also be true
        if (undir)
        {
            l[j].push_back(i);
        }
    }
    void printAdjList()
    {
        // iterate over all the rows
        for (int i = 0; i < V; i++)
        {
            cout << i << "-->";
            for (auto node : l[i])
            {
                cout << node << " ";
            }
            cout << endl;
        }
    }
};

// Use Graph
int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(2, 1);
    g.printAdjList();
    return 0;
}