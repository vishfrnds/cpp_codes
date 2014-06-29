
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

#define inp(n) scanf("%d",&n)
#define inp2(n,m) inp(n);inp(m)


//#define inll(n) scanf("%I64d",&n)

#define inll(n) scanf("%lld",&n)

#define inll2(n,m) scanf("%I64d%I64d",&n,&m)
#define out(n) printf("%d\n",n)
#define out2(n,m) printf("%d %d\n",n,m)
#define outll(n) printf("%I64d\n",n)
#define outll2(n,m) printf("%I64d %I64d\n",n,m)
#define inc(n) scanf("%c",&n)

#define MOD 1000000007
#define MOD_INV 1000000006
#define MAX 100009
#define INF 999999999
int main()
{
	int n,m,i,j,t;
	inp(t);
	while(t--)
	{
	inp2(n,m);
	int a1[n+2][m+2],a2[n+2][m+2],a3[n+2][m+2],a4[n+2][m+2],arr[n+2][m+2];
	ini(a1);
	ini(a2);
	ini(a3);
	ini(a4);
	rep(i,n)
	{

	getchar();
	rep(j,m)
	{arr[i+1][j+1]=getchar()-'0';if(arr[i+1][j+1]){a1[i+1][j+1]=a3[i+1][j+1]=a4[i+1][j+1]=0;a2[i+1][j+1]=0;}}}
	
	rep(i,n+2)
	{
		a1[i][0]=a1[i][m+1]=a3[i][0]=a3[i][m+1]=a4[i][0]=a4[i][m+1]=99999999;a2[i][0]=a2[i][m+1]=99999999;
	}
	rep(i,m+2)
	{
		a1[0][i]=a1[n+1][i]=a3[0][i]=a3[n+1][i]=a4[0][i]=a4[n+1][i]=99999999;a2[0][i]=a2[n+1][i]=99999999;
	}
	rep(i,n)	
	rep(j,m)
	{
		if(a1[i+1][j+1])
		{
			a1[i+1][j+1]=min(a1[i+1][j],a1[i][j+1])+1;
		}
	}
	for(i=n;i>0;i--)
	{
		for(j=m;j>0;j--)
		{
			if(a2[i][j])
			a2[i][j]=min(a2[i+1][j],a2[i][j+1])+1;
		}
	}
	for(i=n;i>0;i--)
	{
		for(j=1;j<=m;j++)
		{
			if(a3[i][j])
			a3[i][j]=min(a3[i+1][j],a3[i][j-1])+1;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=m;j>0;j--)
		{
			if(a4[i][j])
			a4[i][j]=min(a4[i-1][j],a4[i][j+1])+1;
		}
	}
	rep(i,n)
	{
	rep(j,m)
	//printf("%d ",a1[i+1][j+1]);//
	//printf("%d,%d,%d,%d/t",a3[i+1][j+1],a4[i+1][j+1],a1[i+1][j+1],a2[i+1][j+1]);//
printf("%d ",min(min(a3[i+1][j+1],a4[i+1][j+1]),min(a1[i+1][j+1],a2[i+1][j+1])));
	printf("\n");
	}
	
	}
	return 0;
	
	
}
