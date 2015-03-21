#include <iostream>
typedef long long llong;
using namespace std;
llong f(llong n)
{
    llong lg=0, sum=0, k=1, s=1, tmp=n/10;

    while (tmp != 0)
    {
        lg++;
        s = k*10 - k;
        k *= 10;
        sum += s*lg;
        tmp /= 10;
    }

    sum += (n-k+1)*(lg+1);

    return sum;
}
int main(int argc, char *argv[])
{
    llong n;

    cout << "Input? ";
    cin >> n;

    llong x = f(n);
    cout << "Output: " << x << endl;

    return 0;
}
