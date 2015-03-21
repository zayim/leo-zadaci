#include <iostream>
using namespace std;
bool leap(int y)
{
    if (y%100==0) return y%400==0;
    return y%4==0;
}
static int a[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int f(int y, int m, int d)
{
    int k = 0;
    for (int i=0; i<m-1; i++)
        k += a[i];
    k += d;
    if (m>2)
        k += leap(y);

    return k;
}
int main()
{
    int y, m, d;

    cout << "Input (y m d)? ";
    cin >> y >> m >> d;

    int x = f(y, m, d);

    cout << "Output: " << x << endl;

    return 0;
}
