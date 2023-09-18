#include<bits/stdc++.h>
using namespace std;

struct Stack
{
    queue<int> a,b;

    void Push(int n)
    {
        //chuyen het hang doi o A sang B
        while(!a.empty())
        {
            b.push(a.front());
            a.pop();
        }
        //them phan tu moi nhat vao A
        a.push(n);
        //chuyen cac hang doi o B ve A
        while(!b.empty())
        {
            a.push(b.front());
            b.pop();
        }
        //Phan tu vao cuoi se o dau hang doi A
    }
    int Pop()
    {
        int x = a.front();
        a.pop();
        return x;
    }
};

int main()
{
    Stack *S = new Stack;
    for(int i = 1; i < 10;i++)
        S->Push(i);
    for(int i = 1; i < 10;i++)
        cout << S->Pop() << " " << endl;
}
