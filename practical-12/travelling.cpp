#include <iostream>
using namespace std;

int cost[10][10], visited[10];
int n, minCost = 9999;

void tsp(int city, int count, int totalCost, int start)
{
    if(count == n && cost[city][start] != 0)
    {
        int finalCost = totalCost + cost[city][start];

        if(finalCost < minCost)
            minCost = finalCost;

        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(!visited[i] && cost[city][i] != 0)
        {
            visited[i] = 1;

            tsp(i, count + 1,
                totalCost + cost[city][i], start);

            visited[i] = 0;
        }
    }
}

int main()
{
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;
    tsp(0, 1, 0, 0);

    if(minCost == 9999)
        cout << "No possible tour";
    else
        cout << "Minimum cost: " << minCost;

    return 0;
}