#include <iostream>
using namespace std;
void stars(int n)
{
    for (int i=0; i<n; i++)
        cout << '*';
    cout << endl;
}
// Sta za parne? Pretpostavio sam da za n=6 treba izgledati:
// *
// ***
// *****
// ******
// *****
// ***
// *
void f(int n)
{
    for (int i=1; i<=n; i+=2)
        stars(i);
    if (n%2==0)
        stars(n);
    for (int i= n%2 ? n-2 : n-1; i>=1; i-=2)
        stars(i);
}
int main()
{
    int n;
    cout << "Input? ";
    cin >> n;

    cout << "Output: " << endl;
    f(n);

    return 0;
}
