#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long int lli;
typedef pair<lli, lli> ii;
typedef vector<lli> vi;

#define endl '\n'
#define f first
#define s second
#define pb push_back
#define sz(s) lli(s.size())
#define all(s) begin(s), end(s)
#define fore(i, a, b) for(lli i = (a), TT = (b); i < TT; ++i)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


const lli MOD = 1e9 + 7;


int main() { _
    lli n; cin>>n;
    lli m; cin>>m;
    lli x,y;

 
    vector<vi> g(n);
    fore(i,0,m){
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    fore(i,0,n){
        cout<<i<<": ";
        fore(a,0,sz(g[i])){
            if(a==sz(g[i])-1){
                cout<<g[i][a];
            }else{
                cout<<g[i][a]<<"->";
            }
        }
        cout<<endl;
    }
    return 0;
}