#include <stdio.h>
#include <stdlib.h> 

#define ASIZE  65536
#define ITERS  1000000

/* LFSR: Linear Feedback Shift Register
 * This workload generates essentially random accesses to a somewhat large array
 * of size ASIZE*32 Bytes.  It doesn't do anything useful. : )
 */


typedef struct silly_struct {
  int p1,p2,p3,p4,p5,p6,p7,p8;
} silly_struct;

silly_struct arr[ASIZE];

__attribute__ ((noinline))
int lfsr_loop(int val) {
  int result = val, count=val;

  unsigned lfsr = 0xACE1u;
  do {
      count++;
      /* taps: 16 14 13 11; feedback polynomial: x^16 + x^14 + x^13 + x^11 + 1 */
      lfsr = (lfsr >> 1) ^ (-(lfsr & 1u) & 0xB400u);    
      result+=arr[lfsr].p1;
  } while(++count < ITERS);

  return result;
}

int main(int argc, char* argv[]) {
   int result=lfsr_loop(argc^(int)argv[0][0]); 

   if(argc>=2 && result!=0) {
     printf("result: %d\n", result);
   }
}
