#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 24
void check_op(int op){
   switch (op) {
      case 0: printf("+ "); break;
      case 1: printf("- "); break;
      case 2: printf("* "); break;
      case 3: printf("/ "); break;
   }
}

void calculate_op(int op, int val, int* S){
   switch (op) {
      case 0: *S +=val;  break;
      case 1: *S -=val; break;
      case 2: *S *=val; break;
      case 3: *S /=val; break;
   }
}

int operand(unsigned int n, int pos, int dim){
   int mask = 0;
   for(int i = 0; i<dim;i++){
      mask = mask << 1;
      mask = mask | 1;
   }
   return (n>>(16-pos*dim))&mask;
}

int main()           
{
   unsigned int intrare;
   scanf("%u", &intrare);
   int N = (intrare >> 29) +1;
   //printf("%d ", N);


   int dim = ((intrare >> (32-3-N*2-4)) & 15) +1;
   //printf("%d ", dim);

   unsigned int operanzi[9] = {0};

   int operanzi_counter = 0;

   double numere = ((1.0*N+1)*dim)/16;

   for(int i = 0; i<numere; i++){
         unsigned short val = 0;
         scanf("%hu", &val);
         for(int j = 0; j<16/dim; j++){
            if(operanzi_counter < N+1){
               operanzi[operanzi_counter] = operand(val, j+1, dim);
               operanzi_counter++;
            }
         }

   }
   /*
   for(int i = 0; i< N+1; i++){
      printf("%d ", operanzi[i]);
   }*/
   int rezultat = 0;
   rezultat = operanzi[0];
   for(int i = 0; i<N;i++){
      int op = (intrare >> (27 - i*2)) & 3;
      calculate_op(op, operanzi[i+1], &rezultat);
   }
   printf("%d\n", rezultat);



   return 0;
}