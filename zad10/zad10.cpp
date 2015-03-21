#include <iostream>
#include <stack>
#include <queue>
#include <sstream>
#include <fstream>

using namespace std;
int log2(int n)
{
    int k=0;
    while (n%2==0)
    {
        n=n/2;
        k++;
    }
    return k;
}
int power2(int n)
{
    int k=1;
    for (int i=0; i<n; i++)
        k*=2;
    return k;
}
string str(int k)
{
    stringstream ss;
    ss << k;
    return ss.str();
}
void g(int n, stack<string> &s)
{
    if (n==1) return;

    int k = log2(n);
    int m = n/power2(k);

    if (k!=0)
    {
        s.push(string("SHL A,") + str(k));
        g(m, s);
        return;
    }

    if ((n+1)%4==0)
    {
        s.push(string("SUB A,B"));
        g(n+1, s);
        return;
    }

    s.push(string("ADD A,B"));
    g(n-1, s);
}
stack<string> f(int n)
{
    stack<string> s;
    g(n, s);
    s.push(string("MOV B,A"));

    return s;
}
int main(int argc, char *argv[])
{
    int n;

    char* input_path = "M_ulaz.dat";
    char* output_path = "M_izlaz.dat";

    if (argc > 1) input_path = argv[1];
    if (argc > 2) output_path = argv[2];

    ifstream input(input_path);
    ofstream output(output_path);

    input >> n;
    stack<string> s = f(n);
    while(!s.empty())
    {
        output << s.top() << endl;
        s.pop();
    }
}


