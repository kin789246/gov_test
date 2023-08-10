#include<iostream>
using std::cout;

int fib(int n)
{
    int i;
    int fib_n;
    int fib_n_1;
    int fib_n_2;
    if (n == 0) return(0);
    else if (n == 1) return(1);
    else
    {
        fib_n_2 = 0;
        fib_n_1 = 1;
        for (i = 2; i <= n; i++)
        {
            fib_n = fib_n_2 + fib_n_1;
            fib_n_2 = fib_n_1;
            fib_n_1 = fib_n;

            cout << fib_n << " ";
        }
        return(fib_n);
    }
}
int main()
{
    fib(12);
    std::cout << '\n';
    return 0;
}