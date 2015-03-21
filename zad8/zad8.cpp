#include <iostream>
#include <fstream>
typedef long long llong;
using namespace std;
inline llong log10(llong n)
{
    if (n==0) return 0;

    llong k=0;
    while (n!=0)
    {
        n=n/10;
        k++;
    }
    return k-1;
}
llong f(llong n)
{
    llong lg=log10(n), sum=0, k=1, s=1;

    for (int i=1; i<=lg; i++)
    {
        s = k*10 - k;
        k *= 10;
        sum += s*i;
    }

    sum += (n-k+1)*(lg+1);

    return sum;
}
int main(int argc, char *argv[])
{
    llong n;

    char* input_path = "M_ulaz.dat";
    char* output_path = "M_izlaz.dat";

    if (argc > 1) input_path = argv[1];
    if (argc > 2) output_path = argv[2];

    ifstream input(input_path);
    ofstream output(output_path);

    input >> n;

    llong x = f(n);

    output << x << endl;

    return 0;
}
