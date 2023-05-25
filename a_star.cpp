#include <bits/stdc++.h>
using namespace std;

int g = 0;
void print(int arr[])
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
            cout << endl;
        cout << setw(5) << arr[i];
    }
    cout << endl;
}
bool ispos(int st[])
{
    int cnt = 0;
    for (int i = 0; i < 9; i++)
    {
        if (st[i] <= 1)
            continue;
        for (int j = i + 1; j < 9; j++)
        {
            if (st[j] == -1)
                continue;
            if (st[j] < st[i])
                cnt++;
        }
    }
    // cout << cnt << endl;
    return cnt & 1 ? 0 : 1;
}
void copy(int a1[], int a2[])
{
    for (int i = 0; i < 9; i++)
        a2[i] = a1[i];
}

// movetile functions
void moveleft(int empty, int arr[])
{
    swap(arr[empty], arr[empty - 1]);
}
void moveright(int empty, int arr[])
{
    swap(arr[empty], arr[empty + 1]);
}
void movetop(int empty, int arr[])
{
    swap(arr[empty], arr[empty - 3]);
}
void movebottom(int empty, int arr[])
{
    swap(arr[empty], arr[empty + 3]);
}

// heuristic function
int heu(int st[], int f[])
{
    int h = 0;
    // cout << "heu" << endl;
    for (int i = 0; i < 9; i++)
    {
        if (st[i] == -1)
            continue;
        for (int j = 0; j < 9; j++)
        {

            if (st[i] == f[j])
            {
                h += (abs(j - i) / 3 + abs(j - i) % 3);
                break;
            }
        }
    }

    return h + g;
}
void solve(int st[], int f[])
{

    g++;
    print(st);
    int left[9], right[9], top[9], bottom[9], l, r, t, b;
    l = r = t = b = INT_MAX;
    copy(st, left);
    copy(st, right);
    copy(st, top);
    copy(st, bottom);

    int empty = 0;
    for (int i = 0; i < 9; i++)
    {
        if (st[i] == -1)
        {
            empty = i;
            break;
        }
    }

    int x = empty / 3;
    int y = empty % 3;

    if (x - 1 >= 0)
    {
        movetop(empty, top);
        t = heu(top, f);
    }
    if (x + 1 < 3)
    {
        movebottom(empty, bottom);
        b = heu(bottom, f);
    }
    if (y - 1 >= 0)
    {
        moveleft(empty, left);
        l = heu(left, f);
    }
    if (y + 1 < 3)
    {
        moveright(empty, right);
        r = heu(right, f);
    }

    if (t <= l && t <= r && t <= b)
    {
        movetop(empty, st);
    }
    else if (b <= l && b <= t && b <= r)
    {
        movebottom(empty, st);
    }
    else if (l <= t && l <= b && l <= r)
    {
        moveleft(empty, st);
    }
    else
    {
        moveright(empty, st);
    }
    int val = heu(st, f);
    if (val == g)
    {
        print(st);
        cout << "Solved in " << g << "steps\n";
        return;
    }
    solve(st, f);
}

signed main()
{
    int st[9], f[9];
    cout << "Enter start :-\n";
    for (int i = 0; i < 9; i++)
        cin >> st[i];
    cout << "Enter final :-\n";
    for (int i = 0; i < 9; i++)
        cin >> f[i];

    bool ch = ispos(st);
    //  1 2 -1 4 5 3 7 8 6
    //  1 2 -1 4 5 3 7 8 6
    if (ch)
    {
        solve(st, f);
    }
    else
    {
        cout << "Impossible to solve\n";
    }
}