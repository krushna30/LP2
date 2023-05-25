#include<bits/stdc++.h>
using namespace std;


bool ispos(int st[]){
    int cnt = 0;
    for (int i = 0; i< 9 ; i++){
        if(st[i]<= 1)
            continue;
    //     for (int j = i + 1; i < 9; i++){
    //         if(st[])
    //     }
  }

        return cnt & 1 ? 0 : 1;
}


signed main(){
    int st[9], f[9];
    cout << "Enter start :-\n";
    for (int i = 0; i < 9; i++)
        cin >> st[i];
     for (int i = 0; i < 9; i++)
        cin >> f[i];

     bool ch = ispos(st);
}