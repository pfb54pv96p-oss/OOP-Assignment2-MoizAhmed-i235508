#include <iostream>
using namespace std;

void changelocation(char *a, int b1, int b2)
{
    if (b1 >= b2) return;
    char t = a[b1];
    a[b1] = a[b2];
    a[b2] = t;
    changelocation(a, b1 + 1, b2 - 1);
}

int main()
{
    char a[8] = {'C','O','M','P','U','T','E','R'};
    changelocation(a, 2, 6);
    for (int i = 0; i < 8; i++) cout << a[i];
}
