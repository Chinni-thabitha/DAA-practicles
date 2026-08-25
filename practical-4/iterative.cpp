#include <iostream>
using namespace std;

class Factorial
{
public:
    int fact(int n)
    {
        int result = 1;

        for (int i = 1; i <= n; i++)
        {
            result = result * i;
        }

        return result;
    }
};

int main()
{
    int n,result;
    Factorial obj;


    cout << "Enter the value to find its factorial: ";
    cin >> n;


    result = obj.fact(n);

    cout << "Factorial of " << n << " is " << result << endl;

    return 0;
}
