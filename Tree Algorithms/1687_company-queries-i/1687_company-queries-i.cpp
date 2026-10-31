#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> up;
    int n,q;
    cin >> n >> q;
    int cols = log2(n)+1;
    // intialize ancestor table
    up.resize(n+1,vector<int>(cols,-1));

    for(int i=2;i<=n;i++){
        int in;
        cin >> in;
        up[i][0] = in;
    }
    // build the ancestor table
    for(int i=1;i<cols;i++){
        for(int node=2;node<=n;node++){
            if(up[node][i-1] != -1)
            up[node][i] = up[up[node][i-1]][i-1];
        }
    }

    for(int i=0;i<q;i++){
        int x,k;
        cin >> x >> k;
        int node = x;
        for(int j=0;j<cols;j++){
            if(k&(1<<j)){
                node = up[node][j];
                if(node == -1) break;
            }
        }
        cout << node <<"\n";
    }








    return 0;
}
