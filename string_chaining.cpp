/**
*Given list of words. Find the longest chain that can be formed *by them. A chain is valid if every word begin with a letter *ending at the ending of last word.
*Approch =
*1)make the graph of alphabets as vertices and words as edges. 
*  In place of using multiple edges use one with weight equal to
*  number of edges.
*2)find the strongly connected component of graph with 
*  maximum edges. Temporarily discard other edges.
*3)For each vertex make its indegree equal to its outdegree.
*4)Now their exists eulerian circuit in graph. Find it.
*5)Now in remaining graph(w.r.t orignal graph find the longest 
*  trail with first vertex in chosen strongly connected 
*  component. I think this is NP hard.
*6)Include the above trail in Elerian circuit converting eulerian 
*  circuit into trail.
**/
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
#include <list>
using namespace std;


#define MP make_pair
#define pb push_back
#define rep(i,n) for(i=0;i<n;i++)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define PER(i, a, b) for(i = a; i >= b; i--)
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
#define out(n) printf("%d\n",n)
#define out2(n,m) printf("%d %d\n",n,m)
#define inc(n) scanf("%c",&n)

//cost
#define MOD 1000000007
#define MOD_INV 1000000006
#define MAX 100009
#define INF 999999999

/*
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
#include <assert.h>

list<int> lst; 
list<int> flst; 
list<int> slst; 
list<int>::iterator it;
list<int>::iterator it2;
vector< int > vec[26][26];
int pos[26][26];
int mat[26][26];
int fmat[26][26];
int pmat[26][26];
int ppmat[26][26];
int vis[26];
int ans[50], lev;
int nv[26][26];
int outdegree[26], indegree[26];
int poutdegree[26], pindegree[26];
int ppoutdegree[26], ppindegree[26];
int mark[26];
bool trying(int fr, int to, int l)
{
	//cout<<"try"<<fr<<" "<<to<<" "<<l<<endl;
	int i;
	vis[fr] = 1;
	if(mat[fr][to] >= 1)
	{
		lev = l;
		ans[l] = to;
		mat[fr][to]--;
		return true;
	}
	else
	{
		for(i = 0; i <26;i++)
		{
			if(mat[fr][i] && !vis[i])
			if(trying(i, to, l + 1))
			{
				ans[l] = i;
				mat[fr][i]--;
				return true;
			}
		}
	}
	return false;	
}

int attempt(int x, int y)
{
	int i, flag = 1;
	ans[0] = x;
	it = lst.begin();
	lst.insert(it, ans, ans + lev + 1);
	
	flag = 1;
	it = lst.begin();
	
	while(flag)
	{
		flag = 0;
		//it = lst.begin();
		while(it != lst.end())
		{
			clr(vis);
			lev = 0;			
			if(!nv[*it][*it]&&trying(*it, *it, 0))
			{
				//cout<<"here";
				it2 = it;
				it2++;
				lst.insert(it2, ans, ans + lev + 1);
				flag = 1;
				break;
			}
			else
				nv[*it][*it] = 1;
			it++;
		}
	}
	flag = 1;
	it = lst.begin();
	it2 = it;
	it2++;
	while(flag)
	{
		flag = 0;		
		while(it2 != lst.end())
		{
			clr(vis);
			lev = 0;			
			if(!nv[*it][*it2]&&trying(*it, *it2, 0))
			{
				//cout<<"here";
				lst.insert(it2, ans, ans + lev);
				flag = 1;
				it2 = it;
				it2++;
				break;
			}
			else
				nv[*it][*it2] = 1;
			
			it++;
			it2++;
		}
	}
	
}

stack<int> stk;
int trans[26][26];
int comp[26][26], cp = 0;
void DFS(int x)
{
	int i;
	mark[x] = 1;
	comp[cp][x] = 1;
	rep(i, 26)
	{
		if(trans[x][i] && !mark[i] &&( poutdegree[i]))
		DFS(i);
	}
}


void dfs(int x)
{
	int i;
	mark[x] = 1;
	rep(i, 26)
	if(pmat[x][i] && !mark[i] &&(poutdegree[i]))
	{
		dfs(i);		
	}
	stk.push(x);
}
//int G[26][26][2];
int scc()
{
	clr(mark);
	clr(comp);
	clr(trans);
	cp = 0;
	int i, j;
	rep(i, 26)
	if(!mark[i]&&( poutdegree[i]))
	dfs(i);
	rep(i, 26)
	rep(j, 26)
	trans[j][i] = pmat[i][j];
	clr(mark);
	while(!stk.empty())
	{
		int v = stk.top();
        stk.pop();
 		//clr(mark);
        // Print Strongly connected component of the popped vertex
        if (!mark[v] &&(poutdegree[v]))
        {
        	
            DFS(v);
            cp++;
        }
	}
	return cp;
}
void clean(int x)
{
	int i, j;
	rep(i, 26)
	{
		if(comp[x][i])
		rep(j, 26)
		{
			if(pmat[i][j])
			{
				poutdegree[i] -= pmat[i][j];
				pindegree[j] -= pmat[i][j];
				pmat[i][j] = 0;
			}
		}
	}
}
int depth[26], d, md, par[26], ppar[26];
void DDfs(int x)
{
	int d = depth[x], i;
	if(d > md)
	{
		memcpy(ppar, par, sizeof(par));
		md = d;
	}
	rep(i, 26)
	{
		if(mat[x][i] && depth[i] < d + 1)
		{
			par[x] = i;
			mat[x][i]--;
			depth[i] = d+1;
			DDfs(i);
			mat[x][i]++;
			depth[i] = -1;
			par[i] = -1;
		}
	}
}


int main()
{
	int n, t =10, i, x, y, j, k, l, p, q;
	//srand(time(NULL));
	inp(n);
	string s[n];    
    rep(i, n)
    {
        cin>>s[i];
        x = s[i][0] -'A';
        y = s[i][s[i].length() - 1] - 'A';
        vec[x][y].pb(i);
        mat[x][y]++;
        pmat[x][y]++;
        ppmat[x][y]++;
        poutdegree[x]++;
        ppoutdegree[x]++;
        outdegree[x]++;
        pindegree[y]++;
        ppindegree[y]++;
        indegree[y]++;
    }
    assert(scc() == 2);
 
    clean(0); //component to clean
    
    memcpy(mat, pmat, sizeof(mat));
    memcpy(outdegree, poutdegree, sizeof(outdegree));
    memcpy(indegree, pindegree, sizeof(indegree));
   //memcpy(ppmat, pmat, sizeof(mat));
//    memcpy(ppoutdegree, poutdegree, sizeof(outdegree));
  //  memcpy(ppindegree, pindegree, sizeof(indegree));
    
    //assert(scc() == 1);
    
   
   
    
    int fg = 1, ii, jj, mq;
    
    rep(k, 26)
    {
    	if(poutdegree[k] != pindegree[k])
    	{
    		if(poutdegree[k] > pindegree[k])
    		{
    			i = k;
    			int mm = poutdegree[k] - pindegree[k];
    			rep(j, 26)
    			{
    				if( mm <= 0 )
    				break;
    				if(pindegree[j] > poutdegree[j] && mat[i][j] > 0)
    				{
    					if(fg)
    					{
    						ii = i;
    						jj = j;
    						fg = 0;	
    					}
    					mq = pindegree[j] - poutdegree[j];
    					mq = min(mat[i][j], mq);
    					mq = min(mm, mq);
    					mm -= mq;
    					mat[i][j] -= mq;
    					poutdegree[i] -= mq;
    					pindegree[j] -= mq;
    				}
    			}
    		}
    		else
    		{
    			j = k;
    			int mm = pindegree[k] - poutdegree[k];
    			rep(i, 26)
    			{
    				if( mm <= 0)
    				break;
    				if(poutdegree[j] > pindegree[j] && mat[i][j] > 0)
    				{
    					mq = poutdegree[j] - pindegree[j];
    					mq = min(mat[i][j], mq);
    					mq = min(mm, mq);
    					mm -= mq;
    					mat[i][j] -= mq;
    					poutdegree[i] -= mq;
    					pindegree[j] -= mq;
    				}
    			}
    		}
    	}
    }
    
    
    
    
    
    
    rep(k, 26)
    {
    	if(poutdegree[k] != pindegree[k])
    	{
    		if(poutdegree[k] > pindegree[k])
    		{
    			i = k;
    			int mm = poutdegree[k] - pindegree[k];
    			rep(j, 26)
    			{
    				if( mm <= 0 )
    				break;
    				if(pindegree[j] > poutdegree[j] && mat[i][j] > 0)
    				{
    					mq = pindegree[j] - poutdegree[j];
    					mq = min(mat[i][j], mq);
    					mq = min(mm, mq);
    					mm -= mq;
    					mat[i][j] -= mq;
    					poutdegree[i] -= mq;
    					pindegree[j] -= mq;
    				}
    			}
    		}
    		
    	}
    }
    
    
     
    
    
    rep(k, 26)
    {
    	if(poutdegree[k] != pindegree[k])
    	{
    		if(poutdegree[k] > pindegree[k])
    		{
    			
    			i = k;
    			int mm = poutdegree[k] - pindegree[k];
    			rep(j, 26)
    			{
    				
    				if( mm <= 0)
    				break;
    				if(mat[i][j])
    				rep(l, 26)
    				{
    					if(i == j|| l == i || j == l )
    					continue;
    					if( mm <= 0 || mat[i][j] <= 0)
    				break;
    					if(mat[j][l] && pindegree[l] > poutdegree[l])
    					{
    					//	return 0;
    						mq = pindegree[l] - poutdegree[l];
    						mq = min(min(mq, mat[j][l]), min(mat[i][j], mm));
    					//	assert(mq > 0);
    						mm -= mq;
    						mat[j][l] -= mq;
    						mat[i][j] -= mq;
    						poutdegree[i] -= mq;
    						pindegree[j] -= mq;
    						poutdegree[j] -= mq;
    						pindegree[l] -= mq;   
    					//	assert(poutdegree[i] >= 0 &&poutdegree[j] >=0 && pindegree[j] >=0 && pindegree[l] >= 0 && mat[j][l] >= 0 && mat[i][j] >= 0);
    					}
    				}   				
    			}
    			
    		}
    		
    	
    		
    	
    	}
    }
    
    
    
    
     
    
    rep(k, 26)
    {
    	if(poutdegree[k] != pindegree[k])
    	{
    		if(poutdegree[k] > pindegree[k])
    		{
    			
    			i = k;
    			int mm = poutdegree[k] - pindegree[k];
    			rep(j, 26)
    			{
    				
    				if( mm <= 0)
    				break;
    				if(mat[i][j])
    				rep(l, 26)
    				{
    					if( mm <= 0)
    					break;
    					if(mat[i][j] && mat[j][l])
    					rep(q, 26)
    					{
    						if( mm <= 0)
    						break;
    						if(mat[i][j] && mat[j][l] && mat[l][q] && pindegree[q] > poutdegree[q])
    						{
    							mq = pindegree[q] - poutdegree[q];
    							mq = min(mat[l][q], min(min(mq, mat[j][l]), min(mat[i][j], mm)));
    							mm -= mq;
    							mat[l][q] -= mq;
    							mat[j][l] -= mq;
    							mat[i][j] -= mq;
    							poutdegree[i] -= mq;
    							pindegree[j] -= mq;
    							poutdegree[j] -= mq;
    							pindegree[l] -= mq;  
    							poutdegree[l] -= mq;
    							pindegree[q] -= mq;
    						}
    					}  					
    					
    				}   				
    			}
    			
    		}
    	
    	
    	}
    }
    
    
    
    
   
    
    rep(k, 26)
    {
    	if(poutdegree[k] != pindegree[k])
    	{
    		if(poutdegree[k] > pindegree[k])
    		{
    			
    			i = k;
    			int mm = poutdegree[k] - pindegree[k];
    			rep(j, 26)
    			{
    				
    				if( mm <= 0)
    				break;
    				if(mat[i][j])
    				rep(l, 26)
    				{
    					if( mm <= 0)
    					break;
    					if(mat[i][j] && mat[j][l])
    					rep(q, 26)
    					{
    						if( mm <= 0)
    							break;
    						if(mat[i][j] && mat[j][l] && mat[l][q])
    						rep(p, 26)
    						{
    							if( mm <= 0)
    							break;
    							if(mat[i][j] && mat[j][l] && mat[l][q] && mat[q][p] && pindegree[p] > poutdegree[p])
    							{
    								mq = pindegree[p] - poutdegree[p];
    								mq = min( min(mat[l][q], mat[q][p]), min(min(mq, mat[j][l]) , min(mat[i][j], mm)));
    								mm -= mq;
    								mat[l][q] -= mq;
    								mat[j][l] -= mq;
    								mat[i][j] -= mq;
    								mat[q][p] -= mq;
    								poutdegree[i] -= mq;
    								pindegree[j] -= mq;
    								poutdegree[j] -= mq;
    								pindegree[l] -= mq;  
    								poutdegree[l] -= mq;
    								pindegree[q] -= mq;
    								poutdegree[q] -= mq;
    								pindegree[p] -= mq;
    								
    							}    							
    							
    						}
    					}  					
    					
    				}   				
    			}
    			
    		}
    	
    	
    	}
    }
    
    
    int r;
    
    rep(k, 26)
    {
    	if(poutdegree[k] != pindegree[k])
    	{
    		if(poutdegree[k] > pindegree[k])
    		{
    			
    			i = k;
    			int mm = poutdegree[k] - pindegree[k];
    			rep(j, 26)
    			{
    				
    				if( mm <= 0)
    				break;
    				if(mat[i][j])
    				rep(l, 26)
    				{
    					if( mm <= 0)
    					break;
    					if(mat[i][j] && mat[j][l])
    					rep(q, 26)
    					{
    						if(mat[i][j] && mat[j][l] && mat[l][q])
    						rep(p, 26)
    						{
    							if( mm <= 0)
    							break;
    							if(mat[i][j] && mat[j][l] && mat[l][q] && mat[q][p])
    							rep(r, 26)
    							{
    								if(mat[i][j] && mat[j][l] && mat[l][q] && mat[q][p] && mat[p][r]&& pindegree[r] > poutdegree[r])
    							{
    								mq = pindegree[r] - poutdegree[r];
    								mq = min( min(mat[p][r], min(mat[l][q], mat[q][p])), min(min(mq, mat[j][l]) , min(mat[i][j], mm)));
    								mm -= mq;
    								mat[p][r] -= mq;
    								mat[q][p] -= mq;
    								mat[l][q] -= mq;
    								mat[j][l] -= mq;
    								mat[i][j] -= mq;
    								poutdegree[i] -= mq;
    								pindegree[j] -= mq;
    								poutdegree[j] -= mq;
    								pindegree[l] -= mq;  
    								poutdegree[l] -= mq;
    								pindegree[q] -= mq;
    								poutdegree[q] -= mq;
    								pindegree[p] -= mq;
    								poutdegree[p] -= mq;
    								pindegree[r] -= mq;
    								
    							}
    							}
    							
    						}
    					}  					
    					
    				}   				
    			}
    			
    		}
    		
    	
    	}
    }
    
    rep(i, 26)
    {
    	x = 0;
    	rep(j, 26)
    		x+= mat[i][j];
    	assert(x == poutdegree[i]);
    }
     
    memcpy(pmat, mat, sizeof(mat));
    memcpy(outdegree, poutdegree, sizeof(outdegree));
    memcpy(indegree, pindegree, sizeof(indegree));
    
    assert(scc() == 1);
    rep(i, 26)
    assert(indegree[i] == outdegree[i]);  
    
    stack<int> node;
    list<int> llst;
    i = 0;
    int st = 6;
    while(!outdegree[st]) st++;
    while(!node.empty() || outdegree[st])
    {
    	if(outdegree[st] == 0)
    	{
    		llst.push_front(st);
    		st = node.top();
    		node.pop();    		
    	}
    	else
    	{
    		node.push(st);
    		rep(i, 26)
    		if(mat[st][i])
    		{
    			mat[st][i]--;
    			outdegree[st]--;
    			indegree[i]--;
    			st = i;
    			break;
    		}
    	}
    }
    
    
    rep(i, 26)
    {
    	ppoutdegree[i] -= poutdegree[i];
    	ppindegree[i] -= pindegree[i];
    }
    rep(i,26)
    rep(j, 26)
    ppmat[i][j] -= pmat[i][j];
    
  
    
    
    rep(k, 26)
   	rep(l, 26)
   		pmat[i][j] = mat[k][l] = ppmat[k][l];
   	rep(i, 26)
    {
    	outdegree[i] = poutdegree[i] = ppoutdegree[i];
    	indegree[i] = pindegree[i] = ppindegree[i];
    }	
    
    
    
	
	
	
	
	
	int  mx = 0;
	
   rep(i, 1)
   if(comp[1][i])
   {
   		
   }
    
    
    l = flst.front();
    it = llst.begin();
    while(*it != l)
    {
    	it++;
    	
    }
    it++;
   // l = ii;assert(ii == flst.front());
    x = *it;
    it++;
    i = 0;
    k = 0;
    rep(i, 26)
   if(comp[0][i])
   k++;
   i = 0;
   k = -1;
   // k = cp;
    //l  = l/10;
    //l = cp;
    //l = flst.size();
    while(it != llst.end())
    {
    	if(i == k)
    	return 0;
    	i++;
    	y = *it;
    	cout<<s[vec[x][y][pos[x][y]++]]<<endl;
    	x = y;
    	it++;
    }
    it = llst.begin();
    while(*it != l)
    {
    	if(i == k)
    	return 0;
    	i++;
    	y = *it;
    	cout<<s[vec[x][y][pos[x][y]++]]<<endl;
    	x = y;
    	it++;
    }
   
    it = flst.begin();
    while(it != flst.end())
    {
    	y = *it;
    	cout<<s[vec[x][y][pos[x][y]++]]<<endl;
    	x = y;
    	it++;
    }
    return 0;
}

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
#include <list>
using namespace std;


#define MP make_pair
#define pb push_back
#define rep(i,n) for(i=0;i<n;i++)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define PER(i, a, b) for(i = a; i >= b; i--)
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
#define out(n) printf("%d\n",n)
#define out2(n,m) printf("%d %d\n",n,m)
#define inc(n) scanf("%c",&n)

//cost
#define MOD 1000000007
#define MOD_INV 1000000006
#define MAX 100009
#define INF 999999999

/*
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
#include <assert.h>

list<int> lst; 
list<int> flst; 
list<int> slst; 
list<int>::iterator it;
list<int>::iterator it2;
vector< int > vec[26][26];
int pos[26][26];
int mat[26][26];
int fmat[26][26];
int pmat[26][26];
int ppmat[26][26];
int vis[26];
int ans[50], lev;
int nv[26][26];
int outdegree[26], indegree[26];
int poutdegree[26], pindegree[26];
int ppoutdegree[26], ppindegree[26];
int mark[26];
bool trying(int fr, int to, int l)
{
	//cout<<"try"<<fr<<" "<<to<<" "<<l<<endl;
	int i;
	vis[fr] = 1;
	if(mat[fr][to] >= 1)
	{
		lev = l;
		ans[l] = to;
		mat[fr][to]--;
		return true;
	}
	else
	{
		for(i = 0; i <26;i++)
		{
			if(mat[fr][i] && !vis[i])
			if(trying(i, to, l + 1))
			{
				ans[l] = i;
				mat[fr][i]--;
				return true;
			}
		}
	}
	return false;	
}

int attempt(int x, int y)
{
	int i, flag = 1;
	ans[0] = x;
	it = lst.begin();
	lst.insert(it, ans, ans + lev + 1);
	
	flag = 1;
	it = lst.begin();
	
	while(flag)
	{
		flag = 0;
		//it = lst.begin();
		while(it != lst.end())
		{
			clr(vis);
			lev = 0;			
			if(!nv[*it][*it]&&trying(*it, *it, 0))
			{
				//cout<<"here";
				it2 = it;
				it2++;
				lst.insert(it2, ans, ans + lev + 1);
				flag = 1;
				break;
			}
			else
				nv[*it][*it] = 1;
			it++;
		}
	}
	flag = 1;
	it = lst.begin();
	it2 = it;
	it2++;
	while(flag)
	{
		flag = 0;		
		while(it2 != lst.end())
		{
			clr(vis);
			lev = 0;			
			if(!nv[*it][*it2]&&trying(*it, *it2, 0))
			{
				//cout<<"here";
				lst.insert(it2, ans, ans + lev);
				flag = 1;
				it2 = it;
				it2++;
				break;
			}
			else
				nv[*it][*it2] = 1;
			
			it++;
			it2++;
		}
	}
	
}

stack<int> stk;
int trans[26][26];
int comp[26][26], cp = 0;
void DFS(int x)
{
	int i;
	mark[x] = 1;
	comp[cp][x] = 1;
	rep(i, 26)
	{
		if(trans[x][i] && !mark[i] &&( poutdegree[i]))
		DFS(i);
	}
}


void dfs(int x)
{
	int i;
	mark[x] = 1;
	rep(i, 26)
	if(pmat[x][i] && !mark[i] &&(poutdegree[i]))
	{
		dfs(i);		
	}
	stk.push(x);
}
//int G[26][26][2];
int scc()
{
	clr(mark);
	clr(comp);
	clr(trans);
	cp = 0;
	int i, j;
	rep(i, 26)
	if(!mark[i]&&( poutdegree[i]))
	dfs(i);
	rep(i, 26)
	rep(j, 26)
	trans[j][i] = pmat[i][j];
	clr(mark);
	while(!stk.empty())
	{
		int v = stk.top();
        stk.pop();
 		//clr(mark);
        // Print Strongly connected component of the popped vertex
        if (!mark[v] &&(poutdegree[v]))
        {
        	
            DFS(v);
            cp++;
        }
	}
	return cp;
}
void clean(int x)
{
	int i, j;
	rep(i, 26)
	{
		if(comp[x][i])
		rep(j, 26)
		{
			if(pmat[i][j])
			{
				poutdegree[i] -= pmat[i][j];
				pindegree[j] -= pmat[i][j];
				pmat[i][j] = 0;
			}
		}
	}
}
int depth[26], d, md, par[26], ppar[26];
void DDfs(int x)
{
	int d = depth[x], i;
	if(d > md)
	{
		memcpy(ppar, par, sizeof(par));
		md = d;
	}
	rep(i, 26)
	{
		if(mat[x][i] && depth[i] < d + 1)
		{
			par[x] = i;
			mat[x][i]--;
			depth[i] = d+1;
			DDfs(i);
			mat[x][i]++;
			depth[i] = -1;
			par[i] = -1;
		}
	}
}


int main()
{
	int n, t =10, i, x, y, j, k, l, p, q;
	//srand(time(NULL));
	inp(n);
	string s[n];    
    rep(i, n)
    {
        cin>>s[i];
        x = s[i][0] -'A';
        y = s[i][s[i].length() - 1] - 'A';
        vec[x][y].pb(i);
        mat[x][y]++;
        pmat[x][y]++;
        ppmat[x][y]++;
        poutdegree[x]++;
        ppoutdegree[x]++;
        outdegree[x]++;
        pindegree[y]++;
        ppindegree[y]++;
        indegree[y]++;
    }
    assert(scc() == 2);
 
    clean(0); //component to clean
    
    memcpy(mat, pmat, sizeof(mat));
    memcpy(outdegree, poutdegree, sizeof(outdegree));
    memcpy(indegree, pindegree, sizeof(indegree));
   //memcpy(ppmat, pmat, sizeof(mat));
//    memcpy(ppoutdegree, poutdegree, sizeof(outdegree));
  //  memcpy(ppindegree, pindegree, sizeof(indegree));
    
    //assert(scc() == 1);
    
   
   
    
    int fg = 1, ii, jj, mq;
    
    rep(k, 26)
    {
    	if(poutdegree[k] != pindegree[k])
    	{
    		if(poutdegree[k] > pindegree[k])
    		{
    			i = k;
    			int mm = poutdegree[k] - pindegree[k];
    			rep(j, 26)
    			{
    				if( mm <= 0 )
    				break;
    				if(pindegree[j] > poutdegree[j] && mat[i][j] > 0)
    				{
    					if(fg)
    					{
    						ii = i;
    						jj = j;
    						fg = 0;	
    					}
    					mq = pindegree[j] - poutdegree[j];
    					mq = min(mat[i][j], mq);
    					mq = min(mm, mq);
    					mm -= mq;
    					mat[i][j] -= mq;
    					poutdegree[i] -= mq;
    					pindegree[j] -= mq;
    				}
    			}
    		}
    		else
    		{
    			j = k;
    			int mm = pindegree[k] - poutdegree[k];
    			rep(i, 26)
    			{
    				if( mm <= 0)
    				break;
    				if(poutdegree[j] > pindegree[j] && mat[i][j] > 0)
    				{
    					mq = poutdegree[j] - pindegree[j];
    					mq = min(mat[i][j], mq);
    					mq = min(mm, mq);
    					mm -= mq;
    					mat[i][j] -= mq;
    					poutdegree[i] -= mq;
    					pindegree[j] -= mq;
    				}
    			}
    		}
    	}
    }
    
    
    
    
    
    
    rep(k, 26)
    {
    	if(poutdegree[k] != pindegree[k])
    	{
    		if(poutdegree[k] > pindegree[k])
    		{
    			i = k;
    			int mm = poutdegree[k] - pindegree[k];
    			rep(j, 26)
    			{
    				if( mm <= 0 )
    				break;
    				if(pindegree[j] > poutdegree[j] && mat[i][j] > 0)
    				{
    					mq = pindegree[j] - poutdegree[j];
    					mq = min(mat[i][j], mq);
    					mq = min(mm, mq);
    					mm -= mq;
    					mat[i][j] -= mq;
    					poutdegree[i] -= mq;
    					pindegree[j] -= mq;
    				}
    			}
    		}
    		
    	}
    }
    
    
     
    
    
    rep(k, 26)
    {
    	if(poutdegree[k] != pindegree[k])
    	{
    		if(poutdegree[k] > pindegree[k])
    		{
    			
    			i = k;
    			int mm = poutdegree[k] - pindegree[k];
    			rep(j, 26)
    			{
    				
    				if( mm <= 0)
    				break;
    				if(mat[i][j])
    				rep(l, 26)
    				{
    					if(i == j|| l == i || j == l )
    					continue;
    					if( mm <= 0 || mat[i][j] <= 0)
    				break;
    					if(mat[j][l] && pindegree[l] > poutdegree[l])
    					{
    					//	return 0;
    						mq = pindegree[l] - poutdegree[l];
    						mq = min(min(mq, mat[j][l]), min(mat[i][j], mm));
    					//	assert(mq > 0);
    						mm -= mq;
    						mat[j][l] -= mq;
    						mat[i][j] -= mq;
    						poutdegree[i] -= mq;
    						pindegree[j] -= mq;
    						poutdegree[j] -= mq;
    						pindegree[l] -= mq;   
    					//	assert(poutdegree[i] >= 0 &&poutdegree[j] >=0 && pindegree[j] >=0 && pindegree[l] >= 0 && mat[j][l] >= 0 && mat[i][j] >= 0);
    					}
    				}   				
    			}
    			
    		}
    		
    	
    		
    	
    	}
    }
    
    
    
    
     
    
    rep(k, 26)
    {
    	if(poutdegree[k] != pindegree[k])
    	{
    		if(poutdegree[k] > pindegree[k])
    		{
    			
    			i = k;
    			int mm = poutdegree[k] - pindegree[k];
    			rep(j, 26)
    			{
    				
    				if( mm <= 0)
    				break;
    				if(mat[i][j])
    				rep(l, 26)
    				{
    					if( mm <= 0)
    					break;
    					if(mat[i][j] && mat[j][l])
    					rep(q, 26)
    					{
    						if( mm <= 0)
    						break;
    						if(mat[i][j] && mat[j][l] && mat[l][q] && pindegree[q] > poutdegree[q])
    						{
    							mq = pindegree[q] - poutdegree[q];
    							mq = min(mat[l][q], min(min(mq, mat[j][l]), min(mat[i][j], mm)));
    							mm -= mq;
    							mat[l][q] -= mq;
    							mat[j][l] -= mq;
    							mat[i][j] -= mq;
    							poutdegree[i] -= mq;
    							pindegree[j] -= mq;
    							poutdegree[j] -= mq;
    							pindegree[l] -= mq;  
    							poutdegree[l] -= mq;
    							pindegree[q] -= mq;
    						}
    					}  					
    					
    				}   				
    			}
    			
    		}
    	
    	
    	}
    }
    
    
    
    
   
    
    rep(k, 26)
    {
    	if(poutdegree[k] != pindegree[k])
    	{
    		if(poutdegree[k] > pindegree[k])
    		{
    			
    			i = k;
    			int mm = poutdegree[k] - pindegree[k];
    			rep(j, 26)
    			{
    				
    				if( mm <= 0)
    				break;
    				if(mat[i][j])
    				rep(l, 26)
    				{
    					if( mm <= 0)
    					break;
    					if(mat[i][j] && mat[j][l])
    					rep(q, 26)
    					{
    						if( mm <= 0)
    							break;
    						if(mat[i][j] && mat[j][l] && mat[l][q])
    						rep(p, 26)
    						{
    							if( mm <= 0)
    							break;
    							if(mat[i][j] && mat[j][l] && mat[l][q] && mat[q][p] && pindegree[p] > poutdegree[p])
    							{
    								mq = pindegree[p] - poutdegree[p];
    								mq = min( min(mat[l][q], mat[q][p]), min(min(mq, mat[j][l]) , min(mat[i][j], mm)));
    								mm -= mq;
    								mat[l][q] -= mq;
    								mat[j][l] -= mq;
    								mat[i][j] -= mq;
    								mat[q][p] -= mq;
    								poutdegree[i] -= mq;
    								pindegree[j] -= mq;
    								poutdegree[j] -= mq;
    								pindegree[l] -= mq;  
    								poutdegree[l] -= mq;
    								pindegree[q] -= mq;
    								poutdegree[q] -= mq;
    								pindegree[p] -= mq;
    								
    							}    							
    							
    						}
    					}  					
    					
    				}   				
    			}
    			
    		}
    	
    	
    	}
    }
    
    
    int r;
    
    rep(k, 26)
    {
    	if(poutdegree[k] != pindegree[k])
    	{
    		if(poutdegree[k] > pindegree[k])
    		{
    			
    			i = k;
    			int mm = poutdegree[k] - pindegree[k];
    			rep(j, 26)
    			{
    				
    				if( mm <= 0)
    				break;
    				if(mat[i][j])
    				rep(l, 26)
    				{
    					if( mm <= 0)
    					break;
    					if(mat[i][j] && mat[j][l])
    					rep(q, 26)
    					{
    						if(mat[i][j] && mat[j][l] && mat[l][q])
    						rep(p, 26)
    						{
    							if( mm <= 0)
    							break;
    							if(mat[i][j] && mat[j][l] && mat[l][q] && mat[q][p])
    							rep(r, 26)
    							{
    								if(mat[i][j] && mat[j][l] && mat[l][q] && mat[q][p] && mat[p][r]&& pindegree[r] > poutdegree[r])
    							{
    								mq = pindegree[r] - poutdegree[r];
    								mq = min( min(mat[p][r], min(mat[l][q], mat[q][p])), min(min(mq, mat[j][l]) , min(mat[i][j], mm)));
    								mm -= mq;
    								mat[p][r] -= mq;
    								mat[q][p] -= mq;
    								mat[l][q] -= mq;
    								mat[j][l] -= mq;
    								mat[i][j] -= mq;
    								poutdegree[i] -= mq;
    								pindegree[j] -= mq;
    								poutdegree[j] -= mq;
    								pindegree[l] -= mq;  
    								poutdegree[l] -= mq;
    								pindegree[q] -= mq;
    								poutdegree[q] -= mq;
    								pindegree[p] -= mq;
    								poutdegree[p] -= mq;
    								pindegree[r] -= mq;
    								
    							}
    							}
    							
    						}
    					}  					
    					
    				}   				
    			}
    			
    		}
    		
    	
    	}
    }
    
    rep(i, 26)
    {
    	x = 0;
    	rep(j, 26)
    		x+= mat[i][j];
    	assert(x == poutdegree[i]);
    }
     
    memcpy(pmat, mat, sizeof(mat));
    memcpy(outdegree, poutdegree, sizeof(outdegree));
    memcpy(indegree, pindegree, sizeof(indegree));
    
    assert(scc() == 1);
    rep(i, 26)
    assert(indegree[i] == outdegree[i]);  
    
    stack<int> node;
    list<int> llst;
    i = 0;
    int st = 6;
    while(!outdegree[st]) st++;
    while(!node.empty() || outdegree[st])
    {
    	if(outdegree[st] == 0)
    	{
    		llst.push_front(st);
    		st = node.top();
    		node.pop();    		
    	}
    	else
    	{
    		node.push(st);
    		rep(i, 26)
    		if(mat[st][i])
    		{
    			mat[st][i]--;
    			outdegree[st]--;
    			indegree[i]--;
    			st = i;
    			break;
    		}
    	}
    }
    
    
    rep(i, 26)
    {
    	ppoutdegree[i] -= poutdegree[i];
    	ppindegree[i] -= pindegree[i];
    }
    rep(i,26)
    rep(j, 26)
    ppmat[i][j] -= pmat[i][j];
    
  
    
    
    rep(k, 26)
   	rep(l, 26)
   		pmat[i][j] = mat[k][l] = ppmat[k][l];
   	rep(i, 26)
    {
    	outdegree[i] = poutdegree[i] = ppoutdegree[i];
    	indegree[i] = pindegree[i] = ppindegree[i];
    }	
    
    
    
	
	
	
	
	
	int  mx = 0;
	
   rep(i, 1)
   if(comp[1][i])
   {
   		
   }
    
    
    l = flst.front();
    it = llst.begin();
    while(*it != l)
    {
    	it++;
    	
    }
    it++;
   // l = ii;assert(ii == flst.front());
    x = *it;
    it++;
    i = 0;
    k = 0;
    rep(i, 26)
   if(comp[0][i])
   k++;
   i = 0;
   k = -1;
   // k = cp;
    //l  = l/10;
    //l = cp;
    //l = flst.size();
    while(it != llst.end())
    {
    	if(i == k)
    	return 0;
    	i++;
    	y = *it;
    	cout<<s[vec[x][y][pos[x][y]++]]<<endl;
    	x = y;
    	it++;
    }
    it = llst.begin();
    while(*it != l)
    {
    	if(i == k)
    	return 0;
    	i++;
    	y = *it;
    	cout<<s[vec[x][y][pos[x][y]++]]<<endl;
    	x = y;
    	it++;
    }
   
    it = flst.begin();
    while(it != flst.end())
    {
    	y = *it;
    	cout<<s[vec[x][y][pos[x][y]++]]<<endl;
    	x = y;
    	it++;
    }
    return 0;
}
