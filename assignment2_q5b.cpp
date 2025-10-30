#include <iostream>
using namespace std;

class node
{
public:
    int rem, maxv, idx;
    int arr[100];
    node* next;
    node(int r, int m, int i, int a[])
    {
        rem = r;
        maxv = m;
        idx = i;
        for (int k = 0; k < i; k++) arr[k] = a[k];
        next = 0;
    }
};

class stacklist
{
public:
    node* top;
    stacklist() { top = 0; }
    void push(int r, int m, int i, int a[]) { node* n = new node(r, m, i, a); n->next = top; top = n; }
    void pop() { if (!top) return; node* t = top; top = top->next; delete t; }
    bool empty() { return top == 0; }
    node* peek() { return top; }
    ~stacklist() { while (!empty()) pop(); }
};

class frame
{
public:
    int rem, maxv, idx;
    int arr[100];
};

class stackarray
{
public:
    frame st[1000];
    int top;
    stackarray() { top = -1; }
    void push(int r, int m, int i, int a[])
    {
        top++;
        st[top].rem = r;
        st[top].maxv = m;
        st[top].idx = i;
        for (int k = 0; k < i; k++) st[top].arr[k] = a[k];
    }
    void pop() { if (top >= 0) top--; }
    bool empty() { return top == -1; }
    frame peek() { return st[top]; }
};

void printpattern_list(int n)
{
    stacklist s;
    int a[100];
    s.push(n, n, 0, a);
    while (!s.empty())
    {
        node* cur = s.peek();
        s.pop();
        if (cur->rem == 0)
        {
            for (int i = 0; i < cur->idx; i++)
            {
                if (i) cout << ' ';
                cout << cur->arr[i];
            }
            cout << '\n';
            continue;
        }
        for (int i = 1; i <= (cur->rem < cur->maxv ? cur->rem : cur->maxv); i++)
        {
            int b[100];
            for (int k = 0; k < cur->idx; k++) b[k] = cur->arr[k];
            b[cur->idx] = i;
            s.push(cur->rem - i, i, cur->idx + 1, b);
        }
    }
}

void printpattern_arr(int n)
{
    stackarray s;
    int a[100];
    s.push(n, n, 0, a);
    while (!s.empty())
    {
        frame cur = s.peek();
        s.pop();
        if (cur.rem == 0)
        {
            for (int i = 0; i < cur.idx; i++)
            {
                if (i) cout << ' ';
                cout << cur.arr[i];
            }
            cout << '\n';
            continue;
        }
        for (int i = 1; i <= (cur.rem < cur.maxv ? cur.rem : cur.maxv); i++)
        {
            int b[100];
            for (int k = 0; k < cur.idx; k++) b[k] = cur.arr[k];
            b[cur.idx] = i;
            s.push(cur.rem - i, i, cur.idx + 1, b);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    cout << "linked list stack:\n";
    printpattern_list(n);
    cout << "---\narray stack:\n";
    printpattern_arr(n);
}
