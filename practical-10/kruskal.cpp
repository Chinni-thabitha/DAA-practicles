
#include <iostream>
using namespace std;

class Graph
{
public:
    int u[20], v[20], w[20];
    int parent[10];
    int n, e;

    void getInput()
    {
        cout << "Enter number of vertices: ";
        cin >> n;

        cout << "Enter number of edges: ";
        cin >> e;

        cout << "Enter source, destination and weight:\n";

        for(int i = 0; i < e; i++)
            cin >> u[i] >> v[i] >> w[i];
    }

    int find(int x)
    {
        while(parent[x] != x)
            x = parent[x];

        return x;
    }

    void kruskal()
    {
        int temp, totalCost = 0, edges = 0;
        int a, b;

        for(int i = 0; i < n; i++)
            parent[i] = i;

        for(int i = 0; i < e - 1; i++)
        {
            for(int j = 0; j < e - i - 1; j++)
            {
                if(w[j] > w[j + 1])
                {
                    temp = w[j];
                    w[j] = w[j + 1];
                    w[j + 1] = temp;

                    temp = u[j];
                    u[j] = u[j + 1];
                    u[j + 1] = temp;

                    temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
                }
            }
        }

        cout << "\nEdges in Minimum Spanning Tree:\n";

        for(int i = 0; i < e && edges < n - 1; i++)
        {
            a = find(u[i]);
            b = find(v[i]);

            if(a != b)
            {
                cout << u[i] << " - " << v[i]
                     << " = " << w[i] << endl;

                parent[a] = b;
                totalCost += w[i];
                edges++;
            }
        }

        if(edges != n - 1)
            cout << "Graph is disconnected\n";
        else
            cout << "\nMinimum Cost = " << totalCost << endl;
    }
};

int main()
{
    Graph g;

    g.getInput();
    g.kruskal();

    return 0;
}
