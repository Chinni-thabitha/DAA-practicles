#include <iostream>
using namespace std;

int main()
{
    int n, dist[10][10];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter cost adjacency matrix (999 for no edge):\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dist[i][k] != 999 &&
                   dist[k][j] != 999 &&
                   dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "\nShortest Distance Matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << dist[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}