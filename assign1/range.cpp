#include <cstdio>
#include <cstring>

#define N 10004
int A[N];

int main()
{
    memset(A, 0, sizeof(A));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        for (int j = a; j < b; ++j)
        {
            A[j] = 1;
        }
    }
    bool flag = true;
    int s = -1, t = -1;
    for (int i = 0; i < N; ++i)
    {
        if (A[i] == 1)
        {
            if (s == -1)
                s = i;
            if (t != -1)
            {
                flag = false;
                break;
            }
        }
        else if ((s != -1) && (t == -1))
            t = i;
    }
    if (flag)
        printf("%d %d", s, t);
    else
        printf("no");
}