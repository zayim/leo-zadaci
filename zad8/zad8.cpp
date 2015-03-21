#include <iostream>
#include <fstream>
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
