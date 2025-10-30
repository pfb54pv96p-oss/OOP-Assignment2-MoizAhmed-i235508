#include <iostream>
using namespace std;

void rec_print(int rem, int maxv, int a[], int idx)
{
    if (rem == 0) {
        for (int i = 0; i < idx; i++) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
        return;
    }
    for (int i = (rem < maxv ? rem : maxv); i >= 1; i--) {
        a[idx] = i;
        rec_print(rem - i, i, a, idx + 1);
    }
}

void printpattern(int &n)
{
    int a[100];
    rec_print(n, n, a, 0);
}

int main()
{
    int n;
    cin >> n;
    printpattern(n);
}
