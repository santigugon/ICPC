#include <bits/stdc++.h> 

using namespace std;

typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;

#define f first
#define s second
#define endl '\n'
#define sz(s) lli(s.size())
#define all(s) s.begin(), s.end()
#define pb push_back
#define fore(i,a,b) for(lli i = (a), TT=(b);i<TT;++i)
#define _ ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

const lli INF = 1e9;
struct Segtree{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct Node{
    lli s, mx, mn;//-------
    Node(lli s = 0, lli mx = -INF, lli mn = INF): s(s), mx(mx), mn(mn) {}//---------
    Node operator + (const Node &n){
      return Node(s + n.s, max(mx, n.mx), min(mn,n.mn));
      //logica de como mergear nodos
    }
  };
  vector<Node> st;
  Segtree(int n): st(2 * n) {}
  void update(int u, int l, int r, int kth, lli val){ // O(logN)
    if(l == r){
      st[u].s = val;
      st[u].mx = val;
      st[u].mn = val;
      //-------------
      return;
    }
    if(kth <= mid) update(left(u), l, mid, kth, val);
    else update(right(u), mid + 1, r, kth, val);
    st[u] = st[left(u)] + st[right(u)];
  }
  Node query(int u, int l, int r, int ll, int rr){ // O(logN)
    if(l > r or r < ll or l > rr) return Node();
    if(ll <= l and r <= rr) return st[u];
    return query(left(u), l, mid, ll, rr) + query(right(u), mid + 1, r, ll, rr);
  }
  Node query(lli l,lli r, lli n){return query(0,0,n-1,l,r);}
  void update(lli kth,lli val, lli n){return update(0,0,n-1,kth,val);}
};



int main(){_
  lli n;cin>>n;
  lli q;cin>>q;
  Segtree st(n);
  fore(i,0,n){
    lli xd;cin>>xd;
    st.update(i,xd,n);
  }
  
  fore(i,0,q){
    lli t;cin>>t;
    if(t==2){
      lli l,r;
      cin>>l>>r;
      r--;
      auto xd = st.query(l,r,n);
      cout<<xd.s<<endl;
    }else{
      lli kth,val;
      cin>>kth>>val;
      st.update(kth,val,n);
    
    }
    
  }


  return 0;
}