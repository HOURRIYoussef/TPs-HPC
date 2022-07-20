#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


int main(){

    int N = 1000;
    double *x, *y,*z;
    double start, finish, rate ;
    //initialisation des matrices 
    x = malloc(sizeof(double) * N);
    y = malloc(sizeof(double) * N);
    z = malloc(sizeof(double) * N);
   
    int Stride[] = {1,2,5,10,20};
    int t;
    int S = Stride[t];
    int best_stride, min_t=6; // min_t> taille de Stride
    double min_msec=1000000000000.00;
    for(int i = 0; i < N ; i++){
        for(int j=0; j < N; j++){
            x[i,j] = rand() + 1.0;
            y[i,j] = rand() + 1.0;
            z[i,j] = 0.0;
        }
    }

    //multiplication par block

    for(t=0; t < sizeof(Stride)/sizeof(int); t++){


        
        //  start time

        clock_t start = clock ();

        for (int m = 0; m < N; m+=S) {
            for (int n = 0; n < N; n+=S) {
                for (int r = 0; r < N; r+=S) {

                    for (int i = m; i < m+S; i++) {
                        for (int j = n; j < n+S; j++) {
                            for (int k = r; k < r+S; k++) {
                                z[i,j] = z[i,j] + (x[i,k]*y[k,j]); 
                            }
                        }
                    }

                }
            }
        }

        // finish time

        clock_t finish = clock ();
        double msec = (finish -  start) * 1000.0 ;


        rate = (sizeof(double)*  pow((N/S),3) * pow(S,3)  * 4 /(1024*1024) ) / (msec/1000.0) ;
        if(msec<min_msec){
            min_msec=msec;
            min_t=t;
        }
        
        printf("---------------------------------------------------------\n");
        printf("Stride : %d \n",t+1);
        printf("MSEC : %f\n",msec);
        printf("Rate : %f \n",rate);
        

    
    }
    printf("---------------------------------------------------------\n");
    printf("Best Stride : %d \n",min_t);
}