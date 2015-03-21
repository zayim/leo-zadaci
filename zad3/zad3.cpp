#include <iostream>
#include <algorithm>
using namespace std;
int f(int n, bool a[])
{
    int k=0;
    while (n != 0)
    {
        a[k++] = n%2;
        n /= 2;
    }
    for (int i=0, j=k-1; i<k/2; i++, j--)
        swap(a[i], a[j]);

    return k;
}
int main()
{
    int n;
    bool a[10000];

    cout << "Input? ";
    cin >> n;

    int len = f(n, a);

    cout << "Output: ";
    for (int i=0; i<len; i++)
        cout << a[i];
    cout << endl;

    return 0;
}
