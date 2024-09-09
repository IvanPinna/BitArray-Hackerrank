//#include <cmath>
//#include <cstdio>
//#include <vector>
#include <set>
#include <iostream>
//#include <algorithm>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned long  n, s, p, q;
    const long MOD = 2147483648;
    set<int> unique_values;
    
    cin >> n >> s >> p >> q;
    
    int a = s%MOD;
    unique_values.insert(a);
    for(int i = 1; i < n; ++i){
        a = (a*1LL*p + q)%MOD; //Here we use old 'a'
        unique_values.insert(a);
    }
    
    cout << unique_values.size() << endl;
    return 0;
}