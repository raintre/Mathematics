#include <stdio.h>
#include <math.h>
#include "turtle.h" 

void drawtree(float N)
{
  if(N == 0.0){
    /*nothing done*/
  } else {
    CON("localhost") ; 
    CLR() ;     
    RST() ;     

    PD() ;      
    LT(45.0);
    FD(N);
    drawtree(N - 1.0);
    BK(N);
    RT(45.0);

    RT(45.0);
    FD(N);
    drawtree(N - 1.0);
    BK(N);
    LT(45.0);
  }
}