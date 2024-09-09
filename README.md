# BitArray-Hackerrank
Problema "Bit Array", Hackerrank, C++

## Información del problema

Recibidos 4 enteros: N, S, P, Q. Debes utilizarlos para crear la siguiente secuencia con el pseudocódigo que se muestra a continuación.

a[0] = S (modulo 2^31)
for i = 1 to N-1
    a[i] = a[i-1]*P+Q (modulo 2^31) 

La tarea consiste en calcular el número de diferentes enteros en la secuencia.
Your task is to calculate the number of distinct integers in the sequence

### **Formato de entrada**

Cuatro enteros separados por espacio en una línea, N, S, P y Q respectivamente.
Four space separated integers on a single line,

### **Formato de salida**

Un único entero que indica el número de diferentes enteros en la secuencia.

## Primera aproximación
```c++
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

```
## Segunda aproximación

```c++

#include <set>
#include <iostream>

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

``` 
## Solución

```c++

#include <iostream>

using namespace std;

int main() {
    int n, s, p, q;
    cin >> n >> s >> p >> q;

    const int MOD = 2147483648;  // 2^31

    // Initial values for tortoise and hare
    int tortoise = s % MOD;
    int hare = s % MOD;

    // Step 1: Tortoise moves one step and hare moves two steps
    for (int i = 1; i < n; ++i) {
        tortoise = (tortoise * 1LL * p + q) % MOD;
        hare = (hare * 1LL * p + q) % MOD;
        hare = (hare * 1LL * p + q) % MOD;

        if (tortoise == hare) {
            // If they meet, we have found a cycle
            break;
        }
    }

    // Step 2: Count the distinct elements
    int count = 1;  // The initial element is always counted
    int current = s % MOD;
    for (int i = 1; i < n; ++i) {
        current = (current * 1LL * p + q) % MOD;
        if (current == tortoise) {
            break;
        }
        count++;
    }

    cout << count << endl;

    return 0;
}

```
