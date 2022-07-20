#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define  max_stride  20
#define  seed  86456

int main () {

  
  int N = 100000;
  double *a ;
  
  a= malloc(N * max_stride*sizeof(double)); 
  double mean, msec, rate;



  for (int i = 0; i < N * max_stride; i++)
    {
      a[i] = rand()%100 + 1.0;
    }

  for (int  i_stride = 1; i_stride < max_stride; i_stride++) {

      mean = 0.0;
      
      // getting starting time
      clock_t begin = clock ();

      for (int i = 0; i < N * i_stride; i += i_stride) {
          mean = mean + a[i];
           }

      //getting end time;
      clock_t end = clock ();
      mean=mean/N;
      // Cpu_Time
      msec = (end - begin) * 10000;
      // Bande_passante
      rate = sizeof(double) * N * (1000.0 / msec) / (1024 * 1024);
      printf ("-----------------------------------------\n\n");
      printf ("i_stride = %d \nmean = %f\nCPU_Time = %f\nrate = %f\n",
        i_stride, mean, msec, rate);

    }

  return 0;

}