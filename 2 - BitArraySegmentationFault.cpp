#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned long  n, s, p, q, different = 1;
    cin >> n >> s >> p >> q;
    int a[n]; //If n is big enough, a[n] could excess memory limit -> SegmentationFault. 
    
    a[0] = s%(int)pow(2,31);
    for(int i = 1; i < n; ++i){
        a[i] = a[i-1]*p + q%(int)pow(2,31); //Problem, repetitive.
    }
    
    //Check different items in vector.
    std::sort(a, a + n); //If n is big enough it will cause and "infinite" loop.
    for(int i = 0; i < n-1; ++i){
        if(a[i]!=a[i+1])
            different += 1;
    }
    
    cout << different << endl;
    
    return 0;
}
