#include <iostream>
using namespace std;

class node
{
public:
    int id;
    string title;
    string author;
    node* next;
    node* prev;
    node(int i, string t, string a)
    {
        id = i;
        title = t;
        author = a;
        next = 0;
        prev = 0;
    }
};

class doublylinkedlist
{
public:
    node* head;
    node* tail;
    doublylinkedlist()
    {
        head = 0;
        tail = 0;
    }

    void addbeg(int i, string t, string a)
    {
        node* n = new node(i, t, a);
        if (!head) head = tail = n;
        else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    void addend(int i, string t, string a)
    {
        node* n = new node(i, t, a);
        if (!tail) head = tail = n;
        else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void addpos(int pos, int i, string t, string a)
    {
        if (pos <= 1) { addbeg(i, t, a); return; }
        node* n = new node(i, t, a);
        node* temp = head;
        for (int c = 1; temp && c < pos - 1; c++) temp = temp->next;
        if (!temp || !temp->next) { addend(i, t, a); return; }
        n->next = temp->next;
        n->prev = temp;
        temp->next->prev = n;
        temp->next = n;
    }

    void deletebyid(int i)
    {
        node* t = head;
        while (t && t->id != i) t = t->next;
        if (!t) return;
        if (t == head) head = t->next;
        if (t == tail) tail = t->prev;
        if (t->prev) t->prev->next = t->next;
        if (t->next) t->next->prev = t->prev;
        delete t;
    }

    void display()
    {
        node* t = head;
        while (t) {
            cout << t->id << " " << t->title << " " << t->author << "\n";
            t = t->next;
        }
    }

    void displayrev()
    {
        node* t = tail;
        while (t) {
            cout << t->id << " " << t->title << " " << t->author << "\n";
            t = t->prev;
        }
    }

    class it
    {
    public:
        node* cur;
        it(node* n) { cur = n; }
        it& operator++() { cur = cur->next; return *this; }
        it& operator--() { cur = cur->prev; return *this; }
        bool operator!=(const it& o) const { return cur != o.cur; }
        node& operator*() const { return *cur; }
    };

    it begin() { return it(head); }
    it end() { return it(0); }
    it rbegin() { return it(tail); }
    it rend() { return it(0); }
};

int main()
{
    doublylinkedlist l;
    l.addend(1, "booka", "authora");
    l.addend(2, "bookb", "authorb");
    l.addbeg(3, "bookc", "authorc");
    l.addpos(2, 4, "bookd", "authord");
    l.display();
    cout << "---\n";
    l.deletebyid(2);
    l.display();
    cout << "---\n";
    l.displayrev();
    cout << "---\n";
    for (auto &b : l) cout << b.id << " " << b.title << "\n";
}

