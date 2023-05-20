#include <bits/stdc++.h>
using namespace std;
#define int long long

/* B0Ma
                    " وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَى ﴿39﴾ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى ﴿40﴾ ثُمَّ يُجْزَاهُ الْجَزَاء الْأَوْفَى "
*/

void B0Ma() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

}

int power(int x, int y, int p)
{

    int res = 1;
    while (y > 0) {

        if (y % 2 == 1)
            res = (res % p * x % p);
        y = y >> 1;

        x = (x % p * x % p);
    }
    return res % p;
}

int32_t main() {
    B0Ma();
    // fast power with mod
    //power( Basis , exponent , modulo );
    // ( 2 ^ 1e5 ) % ( 1e9 + 7)
    cout << power(2 , 1e5 , 1e9 + 7);

}
