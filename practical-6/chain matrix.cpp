#include <iostream>
using namespace std;

class MatrixChain
{
private:
    int p[20];
    int c[20][20];
    int n;

public:
    void getInput()
    {
        cout << "Enter number of matrices: ";
        cin >> n;

        cout << "Enter dimensions: ";
        for (int i = 0; i <= n; i++)
        {
            cin >> p[i];
        }
    }

    void matrixChain()
    {
        for (int i = 1; i <= n; i++)
        {
            c[i][i] = 0;
        }

        for (int d = 1; d < n - 1 + 1; d++)
        {
            for (int i = 1; i <= n - d; i++)
            {
                int j = i + d;
                int min = 32767;

                for (int k = i; k <= j - 1; k++)
                {
                    int q = c[i][k] + c[k + 1][j]
                          + p[i - 1] * p[k] * p[j];

                    if (q < min)
                    {
                        min = q;
                    }
                }

                c[i][j] = min;
            }
        }

        cout << "\nMinimum number of scalar multiplications = "
             << c[1][n] << endl;
    }

    void display()
    {
        cout << "\nDP Table:\n";

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j < i)
                    cout << "0 ";
                else
                    cout << c[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    MatrixChain obj;

    obj.getInput();
    obj.matrixChain();
    obj.display();

    return 0;
}