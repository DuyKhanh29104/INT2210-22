#include<bits/stdc++.h>
using namespace std;

struct Queue
{
    stack<int> a,b;

    void EnQueue(int n)
    {
        a.push(n);
    }

    int DeQueue()
    {
        // neu 2 stack rong thi queue rong
        if(a.empty()&&b.empty())
        {
            cout << "Queue is empty.";
            return 0;
        }
        // neu b rong thi dao thu tu ngan xep cua stack a vao stack b
        if(b.empty())
        {
            while(a.empty() == false)
            {
                b.push(a.top());
                a.pop();
            }
        }
        //phan tu day cua a thanh dinh cua b -> lay phan tu o dinh b la phan tu vao dau tien
        int n = b.top();
        b.pop();
        return n;
    }
};

int main()
{
    Queue *Q = new Queue;
    for(int i = 1; i < 10;i++)
        Q->EnQueue(i);
    for(int i = 1; i < 10;i++)
        cout << Q->DeQueue() << endl;

}
