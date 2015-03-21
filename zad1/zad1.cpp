#include <iostream>
#include <cstdlib>
using namespace std;
struct point
{
    double d;
    double x;
    int i;

    point(int N, double* a, int i)
    {
        d = 0.0;
        for (int i=0; i<N; i++)
            d += a[i] * a[i];

        x = a[0];

        this->i = i;
    }
};

// Sta znaci dublje? Ja sam uzeo: sto veca x koordinata, to dublje.
int comparePoints (const void * a, const void * b)
{
    point* a_ = *(point**) a;
    point* b_ = *(point**) b;

    if (a_->d < b_->d) return -1;
    if (a_->d > b_->d) return 1;
    if (a_->x > b_->x) return -1;
    if (a_->x < b_->x) return 1;
    return 0;
}
/*
 * Posto je takt procesora 1GHz, to znaci da ce se sat u sekundi okinuti 1 / (1/(1024*1024*1024)) puta, tj. izvrsice se
 * 1073741824 operacija. Vidimo da se u ovoj funkciji izvrsi cca 10 operacija izvan bilo koje petlje, te u for i=0..n-1 petlji
 * se izvrsi cca 8 operacija (racunajuci i konstruktor za point), te jos po jedna for i=0..N-1 petlja unutar tog konstruktora u
 * kojoj se izvrsi cca 5 operacija.
 * Dakle, to je otprilike 10 + 8n + n*5*N operacija, te uzmimo u obzir i sortiranje, njegova kopmpleksnost je O(nlogn), pa neka i
 * na to ode nekih 20nlogn operacija. Ukupno, to je 10 + 8n + n*5*N + 20nlogn operacija. Za N=100, to je:
 * 10 + 8n + 500n + 20nlogn. Dakle, treba rijesiti jednacinu 20nlogn + 508n + 10 = 1073741824.
 * Aproksimativno rjesenje je n ~= 1.35842*10^6, dakle oko 1.3 miliona tacaka bi se trebalo moci obraditi za 1s.
 */
int* f(int N, int n, double** a)
{
    point** pts = new point*[n];

    for (int i=0; i<n; i++)
        pts[i] = new point(N, a[i], i);

    qsort(pts, n, sizeof(point*), comparePoints);

    int* res = new int[n];

    for (int i=0; i<n; i++)
    {
        res[i] = pts[i]->i;
        delete pts[i];
    }

    delete[] pts;

    return res;
}
int main()
{
    int N, n;
    double** a;

    cout << "Input (N n)? ";
    cin >> N >> n;

    cout << "Input (point, every in new line: n1 n2 ... nN)?" << endl;
    a = new double*[n];

    for (int i=0; i<n; i++)
    {
        cout << i << ". point? ";
        a[i] = new double[N];
        for (int j=0; j<N; j++)
            cin >> a[i][j];
    }

    int* x = f(N, n, a);

    cout << "Output (zero-based): ";
    for (int i=0; i<n; i++)
        cout << x[i] << " ";

    for (int i=0; i<n; i++)
        delete[] a[i];
    delete[] a;
    delete[] x;
    return 0;
}
