#include <iostream>
using namespace std;
int* pascal(int n)
{
    int* a = new int[n];
    int* b = new int[n];

    a[0] = 1;
    if (n==1)
    {
        return a;
    }
    a[1] = 1;
    if (n==2)
    {
        return a;
    }

    for (int i=3; i<=n; i++)
    {
        swap (a,b);
        a[0] = 1;
        for (int j=1; j<i-1; j++)
            a[j] = b[j-1] + b[j];
        a[i-1] = 1;
    }

    delete[] b;
    return a;
}
int main()
{
    int n;
    int* a;

    cout << "Input? ";
    cin >> n;

    a = pascal(n);

    cout << "Output: ";
    for (int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    delete[] a;
    return 0;
}
