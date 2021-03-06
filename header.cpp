/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
 * Created By : Vishwas Tripathi 
 * CSE, MNNIT-ALLAHABAD 
 * vishfrnds@gmail.com
 _._._._._._._._._._._._._._._._._._._._._.*/


#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

#define MP make_pair
#define pb push_back
#define rep(i,n) for(i=0;i<n;i++)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define PER(i,a,b) for(i=b;i>=a;i--)
#define X first
#define Y second
#define all(c) c.begin(),c.end() //eg sort(all(v));

#define tr(c, itr) for(itr = (c).begin(); itr != (c).end(); itr++)
#define present(container, element) (container.find(element) != container.end()) //for set,map,etc
#define cpresent(container, element) (find(all(container),element) != container.end()) //for vectors

 typedef long long ll;
 typedef vector<int> vi; 
 typedef vector< vi > vvi; 
 typedef pair< int,int > ii; 

#define sz(a) int((a).size())
#define clr(a) memset(a,0,sizeof(a))
#define ini(a) memset(a,-1,sizeof(a))


//i/o
#define inp(n) scanf("%d",&n)
#define inp2(n,m) scanf("%d%d",&n,&m)
#define ins(s) scanf("%s",s);
#define out(n) printf("%d\n",n)
#define out2(n,m) printf("%d %d\n",n,m)
#define inc(n) scanf("%c",&n)

/*
// for Codeforces
#define inll(n) scanf("%I64d",&n)
#define inll2(n,m) scanf("%I64d%I64d",&n,&m)
#define outll(n) printf("%I64d\n",n)
#define outll(n) printf("%I64d\n",n)
#define outll2(n,m) printf("%I64d %I64d\n",n,m)
*/

#define inll(n) scanf("%lld",&n)
#define inll2(n,m) scanf("%lld%lld",&n,&m)
#define outll(n) printf("%lld\n",n)
#define outll(n) printf("%lld\n",n)
#define outll2(n,m) printf("%lld %lld\n",n,m)



//cost
#define MOD 1000000007
#define MOD_INV 1000000006
#define MAX 100009
#define INF 999999999

int main()
{
    return 0;
}
//debugging
//#define NDEBUG 
//#include <cassert>
 
 /*
  ********BFS**********
Graph is considered to be stored as adjacent vertices list.
Also we considered graph undirected.
 
vvi is vector< vector<int> >
W[v] is the list of vertices adjacent to v
*/
 
 int N; // number of vertices
 vvi W; // lists of adjacent vertices
vi V;// V is visiting flag   
   
 bool check_graph_connected_bfs() { 
      int start_vertex = 0; 
      V = vi(N, false); 
      queue<int> Q; 
      Q.push(start_vertex); 
      V[start_vertex] = true; 
      while(!Q.empty()) { 
           int i = Q.front(); 
           // get the tail element from queue
           Q.pop(); 
           tr(W[i], it) { 
                if(!V[*it]) { 
                     V[*it] = true; 
                     Q.push(*it); 
                } 
           } 
      } 
      return (find(all(V), 0) == V.end()); 
 }  
 






/*
DFS
*/
//int N; // number of vertices 
// vvi W; // graph 
 vi V; // V is a visited flag 
 
 void dfs(int i) { 
       if(!V[i]) { 
            V[i] = true; 
            for_each(all(W[i]), dfs); 
       } 
 } 
  
 bool check_graph_connected_dfs() { 
       int start_vertex = 0; 
       V = vi(N, false); 
       dfs(start_vertex); 
       return (find(all(V), 0) == V.end()); 
 } 


/*
long long gcd(long long a,long long b)
{
	while(b)
		b^=a^=b^=a%=b;
	return a;
}
long long int power(long long int b,long long int e)
{
	long long ans=1,temp;
	while(e>0)
	{
		if(e%2)
			ans=(ans*b)%MOD;
		b=(b*b)%MOD;
		e/=2;
	}
	return ans;
}*/






