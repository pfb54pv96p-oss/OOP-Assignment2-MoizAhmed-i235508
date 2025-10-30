#include <iostream>
using namespace std;

class node
{
public:
    char data;
    node* next;
    node(char d) { data = d; next = 0; }
};

class stacklist
{
public:
    node* top;
    stacklist() { top = 0; }
    void push(char c)
    {
        node* n = new node(c);
        n->next = top;
        top = n;
    }
    void pop()
    {
        if (!top) return;
        node* t = top;
        top = top->next;
        delete t;
    }
    bool empty() { return top == 0; }
    char peek() { return top->data; }
    ~stacklist() { while (!empty()) pop(); }
};

class stackarray
{
public:
    char* arr;
    int top;
    int cap;
    stackarray(int c = 100)
    {
        cap = c;
        arr = new char[cap];
        top = -1;
    }
    void push(char c)
    {
        if (top == cap - 1) return;
        arr[++top] = c;
    }
    void pop()
    {
        if (top >= 0) top--;
    }
    bool empty() { return top == -1; }
    char peek() { return arr[top]; }
    ~stackarray() { delete[] arr; }
};

void changelocation_iter(char* a, int b1, int b2)
{
    stacklist s;
    for (int i = b1; i <= b2; i++) s.push(a[i]);
    for (int i = b1; i <= b2; i++)
    {
        a[i] = s.peek();
        s.pop();
    }
}

void changelocation_iter_arr(char* a, int b1, int b2)
{
    stackarray s(b2 - b1 + 1);
    for (int i = b1; i <= b2; i++) s.push(a[i]);
    for (int i = b1; i <= b2; i++)
    {
        a[i] = s.peek();
        s.pop();
    }
}

int main()
{
    char a[8] = {'C','O','M','P','U','T','E','R'};
    changelocation_iter(a, 2, 6);
    for (int i = 0; i < 8; i++) cout << a[i];
    cout << "\n";
    char b[8] = {'C','O','M','P','U','T','E','R'};
    changelocation_iter_arr(b, 2, 6);
    for (int i = 0; i < 8; i++) cout << b[i];
}
