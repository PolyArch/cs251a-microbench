#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int sieve(int n)  { 
    //source: https://www.geeksforgeeks.org/sieve-of-eratosthenes/
    bool *notprime = (bool*)malloc(sizeof(bool) * n+1); 
  
    for (int p=2; p*p<=n; p++) { 
        // If prime[p] is not changed, then it is a prime 
        if (notprime[p] == false) { 
            // Update all multiples of p 
            for (int i=p*2; i<=n; i += p) {
                notprime[i] = true; 
            }
        }
    }

    int total=0;
    for(int p = 2; p < n; ++p) {
      total+=!notprime[p];
    }
    return total;
}

int main(int argc, char**argv) {
  int total = sieve(1000000);

  if(argc=2) {
    printf("sieve:%d\n", total);
  }

  return 0;
}
