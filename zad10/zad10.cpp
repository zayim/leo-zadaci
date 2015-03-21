#include <iostream>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;
int stepen2(int n)
{
    int k=0;
    while (n%2==0)
    {
        n=n/2;
        k++;
    }
    return k;
}
int dvana(int n)
{
    int k=1;
    for (int i=1; i<=n; i++)
        k*=2;
    return k;
}
string str(int k)
{
    stringstream ss;
    ss << k;
    return ss.str();
}
void f(int n, stack<string> &s)
{
    if (n==1) return;

    int k = stepen2(n);
    int m = n/dvana(k);

    if (k!=0)
    {
        s.push(string("SHL A,") + str(k));
        f(m,s);
        return;
    }

    if ((n+1)%4==0)
    {
        s.push(string("SUB A,B"));
        f(n+1,s);
        return;
    }

    s.push(string("ADD A,B"));
    f(n-1,s);

}
void g(int n)
{

    stack<string> s;
    f(n,s);
    s.push(string("MOV A,B"));

    while(!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}
int main()
{
    g(417);
}


