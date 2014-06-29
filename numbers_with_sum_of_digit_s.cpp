/**
*Find number of numbers between A and B with sum of digit as s.
**/

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
ll A, B;
ll pow10[16];
ll memo[16][136];
ll min_solution = -1;
ll rec( ll prefix, int digits, int sum ) {
   if( sum < 0 ) return 0;
   ll mini = prefix;
   ll maxi = prefix + pow10[digits]-1;
   if( mini > B || maxi < A ) return 0;
   if( digits == 0 ) {
      if( sum > 0 ) return 0;      
      if( min_solution == -1 ) min_solution = prefix;
      return 1;
   }
   bool memoize = (mini >= A && maxi <= B);
   if( memoize && memo[digits][sum] != -1 ) return memo[digits][sum];
   ll ret = 0;
   for( int dig = 0; dig < 10; ++dig ) 
      ret += rec( prefix + dig*pow10[digits-1], digits-1, sum-dig );   
   if( memoize ) memo[digits][sum] = ret;
   return ret;
}
int main( void ) {
s = 5;
   pow10[0] = 1;
    ll ans;
   for( int i = 1; i <= 15; ++i ) pow10[i] = pow10[i-1] * 10;    memset( memo, -1, sizeof memo );
        ans = 0;
        scanf( "%lld%lld", &A, &B );
                
            ans +=  rec( 0, 15, s) ;
        printf("%lld\n",ans);
    }
   return 0;
}