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

#define N 26
#define M 26
#define P 26
#define type int


void matrix_mul(type matA[N][M], type matB[M][P], type matAns[N][P])
{
	type temp[N][P];
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < P; j++)
		{
			temp[i][j] = 0;
			for(int k = 0; k < M; k++)
			{
				temp[i][j] += matA[i][k] * matB[k][j];
			}
		}
	}
	copy(temp, temp + N*P, matAns);
}


void matrix_pow(type mat[N][N], int n, type ans[N][N])
{
	if(!n)
	{
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				if(i == j)
					ans[i][j] = 1;
				else
					ans[i][j] = 0;
	}
	else
	{
		matrix_pow(mat, n / 2, ans);
		matrix_mul(ans, ans, ans);
		if(n & 1)
			matrix_mul(ans, mat, ans);
	}
}
int main()
{
	return 0;
}
