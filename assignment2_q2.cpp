#include <iostream>
using namespace std;

class feature
{
public:
    string name;
    virtual void analyze() = 0;
    virtual ~feature() {}
};

class landfeature : public feature
{
public:
    landfeature(string n) { name = n; }
    void analyze() { cout << name << " land area detected\n"; }
};

class waterfeature : public feature
{
public:
    waterfeature(string n) { name = n; }
    void analyze() { cout << name << " water body detected\n"; }
};

class node
{
public:
    int id;
    feature* f;
    node* next;
    node(int i, feature* fe) { id = i; f = fe; next = 0; }
    ~node() { delete f; }
};

class singlylinkedlist
{
public:
    node* head;
    singlylinkedlist() { head = 0; }

    void insertatend(int id, feature* f)
    {
        node* n = new node(id, f);
        if (!head) head = n;
        else {
            node* t = head;
            while (t->next) t = t->next;
            t->next = n;
        }
    }

    void deletebyid(int id)
    {
        if (!head) return;
        if (head->id == id) {
            node* del = head;
            head = head->next;
            delete del;
            return;
        }
        node* t = head;
        while (t->next && t->next->id != id) t = t->next;
        if (t->next) {
            node* del = t->next;
            t->next = del->next;
            delete del;
        }
    }

    void displayall()
    {
        node* t = head;
        while (t) {
            t->f->analyze();
            t = t->next;
        }
    }

    void reverselist()
    {
        node* prev = 0;
        node* cur = head;
        node* next = 0;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

    singlylinkedlist operator+(singlylinkedlist& other)
    {
        singlylinkedlist res;
        node* t = head;
        while (t) {
            res.insertatend(t->id, new landfeature(t->f->name));
            t = t->next;
        }
        t = other.head;
        while (t) {
            res.insertatend(t->id, new landfeature(t->f->name));
            t = t->next;
        }
        return res;
    }

    singlylinkedlist& operator=(const singlylinkedlist& other)
    {
        if (this == &other) return *this;
        node* t = head;
        while (t) {
            node* tmp = t;
            t = t->next;
            delete tmp;
        }
        head = 0;
        node* o = other.head;
        while (o) {
            insertatend(o->id, new landfeature(o->f->name));
            o = o->next;
        }
        return *this;
    }

    ~singlylinkedlist()
    {
        node* t = head;
        while (t) {
            node* tmp = t;
            t = t->next;
            delete tmp;
        }
    }
};

int main()
{
    singlylinkedlist l;
    l.insertatend(1, new landfeature("forest"));
    l.insertatend(2, new waterfeature("river"));
    l.insertatend(3, new landfeature("mountain"));
    l.insertatend(4, new waterfeature("lake"));

    l.displayall();
    cout << "---\n";
    l.deletebyid(2);
    l.displayall();
    cout << "---\n";
    l.reverselist();
    l.displayall();
}
