#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> up;
int cols;
int depth(int x){
    int count = 0;
    for(int j=cols-1;j>=0;j--){
        if(up[x][j] != -1){
            count +=(1<<j);
            x = up[x][j];
            // if(x == 1) break;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin >> n >> q;
    cols = log2(n)+1;
    up.assign(n+1,vector<int>(cols,-1));


    for(int i=2;i<=n;i++){
        int in;
        cin >> in;
        up[i][0]=in;
    }

    for(int j=1;j<cols;j++){
        for(int node=2;node<=n;node++){
            if(up[node][j-1] != -1)
                up[node][j] = up[up[node][j-1]][j-1];
        }
    }



    for(int i=0;i<q;i++){
        int x,y;
        cin >> x >> y;
        int f = depth(x);
        int s = depth(y);
        // cout << f <<" "<< s<<"\n";
        
        if(f < s){
            int diff = s-f;
            for(int j=cols-1;j>=0;j--){
                if(diff&(1LL<<j)){
                    y = up[y][j];
                }
            }
        }else if(f > s){
            int diff = f-s;
            for(int j=cols-1;j>=0;j--){
                if(diff&(1LL<<j)){
                    x = up[x][j];
                }
            }
        }
        if(x == y) {
            cout << x <<"\n";
            continue;
        }
        // cout << x <<" " << y <<"\n";

        for(int j=cols-1;j>=0;j--){
            if(up[x][j] != up[y][j]){
                x = up[x][j];
                y = up[y][j];
            }
            // cout << x <<" " << y << "\n";
        }

        cout << up[x][0] <<"\n";
    }
    return 0;
}
