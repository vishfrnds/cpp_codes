/*
*question https://www.hackerrank.com/contests/expansion-challenge/challenges/decoding-json
*/
#include<cstdio>
#include <map>
#include <iostream>
using namespace std;
string l[90000];
map<string, string> m;
string ans = "";
int lev = -1, f = 0;
void mp()
{
    string key = "";
    for(int i = 0; i <= lev; i++)
            {
                if(i && key.size() && key[key.size() - 1] != '.')
                    key =key+".";
                key = key + l[i];
            }
//    cout<<endl<<"mp "<<key<<" = "<<ans<<endl;
    m[key] = ans;

}
int main()
{
    int n, mm;
    char c, arr[900000];
    
    scanf("%d%d", &n, &mm);
    getchar();
    
    
    int ctr = 0, i = 0, pos;
    while(ctr < n &&(c = getchar())!= EOF )
    {
        if(c =='\n')
        {
            ctr++;
        }
        else
            arr[i++] = c;
        if(i > 800000)
            i = i /0;
    }
    
    for(int pos = 0; pos < i ; pos++)
    {
        if(lev > 80000)
            lev = lev/0;
        c = arr[pos];
        //cout<<c;
        if(f == 5)
        {
            if((c >= '0' && c <= '9') || c == '-')
            {
                ans = ans + c;
                continue;
            }
            else
            {
                mp();
                pos--;
                f = 0;
                continue;
            }
            continue;
        }
        if(f == 7)
        {
            if((c >= 'a' && c <= 'z'))
            {
                ans = ans + c;
                continue;
            }
            else
            {
                mp();
                pos--;
                f = 0;
                continue;
            }
            continue;
        }
        if(f == 9)
        {
            if(c == '\"')
            {
                 ans = ans + c;
                mp();
                f = 0;
                continue;
            }
            //if((c >= '0' && c <= '9') ||(c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '.' || c == '-' || c == ':' || c == '/' || c == '#' ||  c==  ' '  )
            else
            {
                ans = ans + c;
                continue;
            }
            continue;
        }
        if(c == '\"' && f == 0)
        {
            f = 1;            
            l[lev] = "";
            continue;
        }
        if(f == 1)
        {
            if(c == '\"')
            {
                f = 2;
                continue;
            }
            else
                l[lev] = l[lev] + (char)c;
            //cout<<endl<<l[lev]<<endl;
            continue;
        }
        
        if(f == 2 && c == ':')
        {
            f = 3;
            ans = "";
            continue;
            
        }
       // cout<<"char "<<c<<" "<<j<<endl;
        if(c == '{')
        {
            f = 0;
            lev++;
            continue;
        }
        if(c == '}')
        {
            f = 0;
            lev--;
            continue;
        }
        if(f == 3)
        {
            if(c == '-' || (c >= '0' && c <= '9'))
            {
                f = 5;
                pos--;
                continue;
            }
            if(c == 't' || c == 'f' || c == 'n')
            {
                f = 7;
                pos--;
                continue;
            }
            if(c == '\"')
            {
                ans = ans + '\"';
                f = 9;
                pos;
                continue;
            }
            continue;
        }
        
        
    }/*
    map<string, string>::iterator it;
    it = m.begin();
    while(it != m.end())
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
        it++;
    }
    */
    string s;
    for(int i = 0; i < mm; i++)
    {
        cin>>s;
        //cout<<s<<endl;
        if(m.find(s) != m.end())
        cout<<m[s]<<endl;
        else
            cout<<"null"<<endl;
    }
    return 0;
}
