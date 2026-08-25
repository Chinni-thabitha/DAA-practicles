#include <iostream>
using namespace std;

class Factorial
{
public:
    int factr(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        else
        {
            int result = n * factr(n - 1);
            return result;
        }
    }
};

int main()
{
    int n, result;
    Factorial obj;

    cout << "Enter the value to find its factorial: ";
    cin >> n;

    result = obj.factr(n);

    cout << "Factorial of " << n << " is " << result << endl;

    return 0;
}
