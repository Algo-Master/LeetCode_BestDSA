#define ll long long int

class Solution {
public:
    const int mod = 1e9 + 7;

    int mod_exp(ll base, ll pow) {

        ll ans = 1;

        while(pow > 0) {
            if(pow&1) ans = (ans * base) % mod;

            pow = pow>>1;
            base = (base * base) % mod;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        
        ll ev = (n&1)? (n>>1) + 1 : (n>>1) + 0, pr = (n>>1);

        ev = mod_exp(5LL, ev);
        pr = mod_exp(4LL, pr);

        return (1LL * ev * pr) % mod;
    }
};