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

void BFS(vector<vector<char>> &matrix, ii startingPoint){
    queue<ii> q;
    q.push(startingPoint);
    while(q.size()){
        ii currPosition=q.front();
        q.pop();
        lli r=currPosition.f;
        lli c=currPosition.s;
      

        if(r-1>=0 && matrix[r-1][c]=='.'){
              matrix[r-1][c]='#';
            q.push(make_pair(r-1,c));
        } 
        if(c-1>=0 && matrix[r][c-1]=='.'){
              matrix[r][c-1]='#';
            q.push(make_pair(r,c-1));
        }
        if(r+1<matrix.size() && matrix[r+1][c]=='.'){
              matrix[r+1][c]='#';
            q.push(make_pair(r+1,c));
        }
        if(c+1<matrix[r].size()&& matrix[r][c+1]=='.'){
              matrix[r][c+1]='#';
            q.push(make_pair(r,c+1));
        }
    }
}

int main() { _
    lli r; cin>>r;
    lli c; cin>>c;
    char x;
    vector<vector<char>> matrix(r,vector<char>(c));
    ii startPoint;
    fore(i,0,r){
        fore(a,0,c){
            cin>>x;
            matrix[i][a] = x;
            if(x=='#') {
                startPoint.f=i;
                startPoint.s=a;
            }
        }
    }
    BFS(matrix,startPoint);

    fore(i,0,r){
        fore(a,0,c){
            cout<<matrix[i][a];
        }
        cout<<endl;
    }



    return 0;
}