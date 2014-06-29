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
#define X first
#define Y second
#define all(c) c.begin(),c.end()

#define tr(c, itr) for(itr = (c).begin(); itr != (c).end(); itr++)
//#define tr(container,it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define present(container, element) (container.find(element) != container.end()) //for set,map,etc
#define cpresent(container, element) (find(all(container),element) != container.end()) //for vectors

 typedef long long ll;
 typedef vector<int> vi; 
 typedef vector< vi > vvi; 
 typedef pair< int,int > ii; 

#define sz(a) int((a).size())]
#define clr(a) memset(a,0,sizeof(a))
#define ini(a) memset(a,-1,sizeof(a))


//i/o
#define inp(n) scanf("%d",&n)
#define inp2(n,m) scanf("%d%d",&n,&m)
#define ins(s) scanf("%s",s);

#define inll(n) scanf("%I64d",&n)

#define inll2(n,m) scanf("%I64d%I64d",&n,&m)

#define out(n) printf("%d\n",n)
#define out2(n,m) printf("%d %d\n",n,m)
#define outll(n) printf("%I64d\n",n)
#define outll2(n,m) printf("%I64d %I64d\n",n,m)
#define inc(n) scanf("%c",&n)



//cost
#define MOD 1000000007
#define MOD_INV 1000000006
#define MAX 100009
#define INF 999999999
string ans;
int rem[100000],par[100000],val[100000],vis[20009];
int bfs(int n)
{
	
	{
		int t=0,pt=-1,cur=0,fstrem,sndrem,prrem;
		rem[cur]=1;
		par[cur]=pt;
		val[cur]=1;
		pt=cur;
		cur++;
			while(pt<=cur)
			{
				prrem=rem[pt];
				fstrem=(prrem*10)%n;
				par[cur]=pt;
				rem[cur]=fstrem;
				val[cur]=0;
				if(fstrem==0)
				{
					return cur;
				}
				else if(!vis[fstrem])
				{
					vis[fstrem]=1;
					cur++;
				}
				
				sndrem=(prrem*10+1)%n;
				par[cur]=pt;
				rem[cur]=sndrem;
				val[cur]=1;
				if(sndrem==0)
				{
					return cur;
				}
				else if(!vis[sndrem])
				{
					vis[sndrem]=1;
					cur++;
				}
				pt++;
			}
				
		
		
	}
}
int main()
{
	int t,cur,n;
	inp(t);
	while(t--)
	{
		scanf("%d",&n);
		if(n==1)
		printf("1\n");
		else
		{
			clr(vis);
			cur=bfs(n);
			ans="";
			while(cur>=0)
			{
				//cout<<val[cur]<<endl;
				ans=(char)(val[cur]+'0')+ans;	
				cur=par[cur];
			}
			cout <<ans<<endl;
		}
		
	}
	return 0;
}





