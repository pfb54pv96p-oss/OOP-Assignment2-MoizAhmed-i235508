#include <iostream>
using namespace std;

class node
{
public:
    int id;
    string name;
    int tickets;
    node* next;
    node(int i, string n, int t)
    {
        id = i;
        name = n;
        tickets = t;
        next = 0;
    }
};

class queue
{
public:
    node* front;
    node* rear;
    queue()
    {
        front = 0;
        rear = 0;
    }

    void enqueue(int i, string n, int t)
    {
        node* newn = new node(i, n, t);
        if (!rear) front = rear = newn;
        else {
            rear->next = newn;
            rear = newn;
        }
    }

    void dequeue()
    {
        if (!front) return;
        node* temp = front;
        front = front->next;
        if (!front) rear = 0;
        delete temp;
    }

    void display()
    {
        node* t = front;
        while (t)
        {
            cout << t->id << " " << t->name << " " << t->tickets << "\n";
            t = t->next;
        }
    }

    ~queue()
    {
        while (front) dequeue();
    }
};

class priorityqueue
{
public:
    node* front;
    priorityqueue() { front = 0; }

    void enqueue(int i, string n, int t)
    {
        node* newn = new node(i, n, t);
        if (!front || t > front->tickets)
        {
            newn->next = front;
            front = newn;
            return;
        }
        node* temp = front;
        while (temp->next && temp->next->tickets >= t)
            temp = temp->next;
        newn->next = temp->next;
        temp->next = newn;
    }

    void dequeue()
    {
        if (!front) return;
        node* temp = front;
        front = front->next;
        delete temp;
    }

    void display()
    {
        node* t = front;
        while (t)
        {
            cout << t->id << " " << t->name << " " << t->tickets << "\n";
            t = t->next;
        }
    }

    ~priorityqueue()
    {
        while (front) dequeue();
    }
};

int main()
{
    queue q;
    q.enqueue(1, "ali", 2);
    q.enqueue(2, "ahmed", 4);
    q.enqueue(3, "sara", 1);
    q.display();
    cout << "---\n";
    q.dequeue();
    q.display();
    cout << "---\n";

    priorityqueue pq;
    pq.enqueue(1, "ali", 2);
    pq.enqueue(2, "ahmed", 4);
    pq.enqueue(3, "sara", 1);
    pq.display();
    cout << "---\n";
    pq.dequeue();
    pq.display();
}
