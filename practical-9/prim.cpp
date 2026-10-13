#include <iostream>
using namespace std;

class Graph
{
public:
    int cost[10][10];
    int visited[10];
    int n;

    void getInput()
    {
        cout << "Enter number of vertices: ";
        cin >> n;

        cout << "Enter cost adjacency matrix:\n";

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> cost[i][j];
            }
        }
    }

    void prim()
    {
        int edges = 0;
        int min;
        int u = 0, v = 0;
        int totalCost = 0;

        for(int i = 0; i < n; i++)
        {
            visited[i] = 0;
        }

        visited[0] = 1;

        cout << "\nEdges in Minimum Spanning Tree:\n";

        while(edges < n - 1)
        {
            min = 9999;

            for(int i = 0; i < n; i++)
            {
                if(visited[i] == 1)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(visited[j] == 0 && cost[i][j] != 0)
                        {
                            if(cost[i][j] < min)
                            {
                                min = cost[i][j];
                                u = i;
                                v = j;
                            }
                        }
                    }
                }
            }

            cout << u << " - " << v << " = " << min << endl;

            totalCost = totalCost + min;

            visited[v] = 1;

            edges++;
        }

        cout << "\nMinimum Cost = " << totalCost << endl;
    }
};

int main()
{
    Graph g;

    g.getInput();

    g.prim();

    return 0;
} 