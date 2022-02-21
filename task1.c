#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 24
void check_op(int n){
   switch (n) {
      case 0: printf("+ "); break;
      case 1: printf("- "); break;
      case 2: printf("* "); break;
      case 3: printf("/ "); break;
   }
}
int main()           
{
   unsigned int intrare;
   scanf("%u", &intrare);
   int N = (intrare >> 29) +1;
   printf("%d ", N);
   for(int i = 0; i<N;i++){
      int op = (intrare >> (27 - i*2)) & 3;
      check_op(op);
   }
   int dim = ((intrare >> (32-3-N*2-4)) & 15) +1;
   printf("%d\n", dim);

   return 0;
}