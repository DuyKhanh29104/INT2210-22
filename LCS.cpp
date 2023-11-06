#include<iostream>
using namespace std;

int LCS(int **arr, string a, string b,int m, int n)
{
    for (int i = 0; i <= m; i++)
        arr[i][0] = 0;
    for (int i = 0; i <= n; i++)
        arr[0][i] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            //nếu 2 kí tự bằng nhau thì cộng thêm 1 vào độ dài lớn nhất trước nó
            if(a[i-1] == b[j-1])
                arr[i][j] = arr[i-1][j-1] + 1;
            //Nếu không ta gán bằng max của 2 giá trị trước đó
            else
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
        }
    }
    return arr[m][n];
}

int main()
{
    string a,b;
    cin >> a >> b;
    int m = a.size();
    int n = b.size();
    // arr[i][j] là xâu con dài nhất của i phần tử đầu dãy a và j phần tử đầu dãy b
    int **arr = new int*[m + 1];
    for (int i = 0; i <= m; i++)
        arr[i] = new int[n + 1];
    cout << LCS(arr,a,b,m,n) << endl;
    for (int i = 0; i <= m; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}
