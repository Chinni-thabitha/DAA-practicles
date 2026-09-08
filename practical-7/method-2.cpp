#include <iostream>
#include <algorithm>
using namespace std;

class ChangeMaking {
private:
    int coins[10];
    int n, w;
    int A[100][100];
public:
    void getInput() {
        cout << "Enter number of coin types: ";
        cin >> n;

        cout << "Enter coin values: ";
        for (int i = 1; i <= n; i++)
            cin >> coins[i];

        cout << "Enter amount: ";
        cin >> w;
    }
    void solve() {
        for (int i = 0; i <= n; i++)
            A[i][0] = 0;
        for (int j = 1; j <= w; j++)
            A[0][j] = 999;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= w; j++) {

                if (coins[i] > j)
                    A[i][j] = A[i - 1][j];
                else
                    A[i][j] = min(A[i - 1][j],
                                  1 + A[i][j - coins[i]]);
            }
        }
    }
    void printTable() {
        cout << "\nDP Table:\n";
        cout << "      ";
        for (int j = 0; j <= w; j++)
            cout << j << "   ";
        cout << endl;
        for (int i = 0; i <= n; i++) {
            cout << "i=" << i << "  ";

            for (int j = 0; j <= w; j++) {

                if (A[i][j] == 999)
                    cout << "0   ";
                else
                    cout << A[i][j] << "   ";
            }

            cout << endl;
        }
    }
    void showResult() {
        if (A[n][w] == 999)
            cout << "\nAmount cannot be formed.";
        else
            cout << "\nMinimum number of coins = "
                 << A[n][w];
    }
};
int main() {
    ChangeMaking c;
    c.getInput();
    c.solve();
    c.printTable();
    c.showResult();
    return 0;
}