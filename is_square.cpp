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

bool square (int x1 , int y1 , int x2 , int y2 , int x3 , int y3 , int x4 , int y4){
    int d2 = (int)pow(x1 - x2 , 2) + (int)pow(y1 - y2 , 2);
    int d3 = (int)pow(x1 - x3 , 2) + (int)pow(y1 - y3 , 2);
    int d4 = (int)pow(x1 - x4 , 2) + (int)pow(y1 - y4 , 2);
    if(d2 == d3 && 2 * d2 == d4){
        int d = (int)pow(x2 - x4 , 2) + (int)pow(y2 - y4 , 2);
        return (d == (int)pow(x3 - x4 , 2) + (int)pow(y3 - y4 , 2) && d == d2);
    }
    if(d3 == d4 && 2 * d3 == d2){
        int d = (int)pow(x2 - x3 , 2) + (int)pow(y2 - y3 , 2);
        return (d == (int)pow(x2 - x4 , 2) + (int)pow(y2 - y4 , 2) && d == d3);
    }
    if(d2 == d4 && 2 * d2 == d3){
        int d = (int)pow(x2 - x3 , 2) + (int)pow(y2 - y3 , 2);
        return (d == (int)pow(x3 - x4 , 2) + (int)pow(y3 - y4 , 2) && d == d2);
    }
    return false;
}
int32_t main() {
    B0Ma();
    

}