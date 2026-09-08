#include <iostream>
using namespace std;

class ChangeMaking {
private:
    int coins[10];
    int n;
    int w;
    int A[10][100];

public:

    void getInput() {
        cout << "Enter number of coin types : ";
        cin >> n;

        cout << "Enter coin values : ";
        for (int i = 1; i <= n; i++)
            cin >> coins[i];

        cout << "Enter amount : ";
        cin >> w;
    }

    void solve() {

        for (int i = 0; i <= n; i++)
            A[i][0] = 1;

        for (int j = 1; j <= w; j++)
            A[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= w; j++) {

                if (coins[i] > j)
                    A[i][j] = A[i - 1][j];

                else
                    A[i][j] = A[i - 1][j]
                            + A[i][j - coins[i]];
            }
        }
    }

    void printTable() {

        cout << "\nDP Table:\n";

        cout << "Coin ";

        for (int j = 0; j <= w; j++)
            cout << j << "   ";

        cout << endl;

        for (int i = 0; i <= n; i++) {

            if (i == 0)
                cout << "0    ";
            else
                cout << coins[i] << "    ";

            for (int j = 0; j <= w; j++)
                cout << A[i][j] << "   ";

            cout << endl;
        }
    }

    void showResult() {
        cout << "\nTotal Number of Ways = "
             << A[n][w] << endl;
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