
#include <stdio.h>
#include <math.h>

/* Function prototype declaration */
double func(double x);
double bisection(double x_min, double x_max, double epsilon);

int main(void) {
    double a, b, ans;
    double epsilon = 1.0e-6;

    /* Read the initial values of x_min and x_max from the keyboard */
    printf("We solve the equation using dichotomy.\n");
    printf("Please enter the value of the lower limit a of the solution: "); scanf("%lf", &a);
    printf("Please enter the value of the upper limit b of the solution: "); scanf("%lf", &b);
    if( !(a < b) ){
        printf("Please enter the number that a < b.\n");
        return 1;       /* Abnormal termination (return value is 1)*/
    }

    /* It is checked whether signs of f (a) and f (b) are different */
    if( func(a)*func(b)>0  ){
        printf("Please enter the values of a and b where f (a) and f (b) are different signs.\n");
        return 1;       /* Abnormal termination (return value is 1)*/
    }

    /* Call a dichotomic function to find a solution */
    ans = bisection(a, b, epsilon);

    /* Output solution of equation */
    printf("Solving the equation: %13.10f\n", ans);
    return 0;           /* Normal end (return value is 0) */
}

/*----------------------------------------------------------------------------
  A function that solves an equation by a dichotomy.

(argument)
x_min: lower limit of solution
x_max: upper limit of solution
epsilon: convergence error

(Return value)
Solving the equation

(Local variables)
x_mid: midpoint between x_min and x_max
 ----------------------------------------------------------------------------*/
double bisection(double x_min, double x_max, double epsilon){
    double x_mid;

    /* The inside of the while loop is incomplete. Please complete. */
    while ( x_max - x_min > epsilon ){
        /* Find the midpoint x_mid */
        x_mid = (x_max + x_min) / 2.0;

        /*If the sign of func (x_min) and func (x_mid) are the same,
Let midpoint x_mid be new x_min.*/
        if(func(x_min)*func(x_mid)>0){
            x_min = x_mid;
        }

        /* If the signs of func (x_min) and func (x_mid) are different
Let midpoint x_mid be new x_max.*/
        if(func(x_min)*func(x_mid)<0){
            x_max = x_mid;
        }
    }

    return x_mid;       /* Return the double type numeric value x_mid to the caller */
}

/*----------------------------------------------------------------------------
  Calculate the value of function f (x)
 ----------------------------------------------------------------------------*/
double func(double x){
    double f;           /* x, f are valid local variables only in this function */

    /* Write the calculation formula of the function f here */
    f = x*x*x + x - 1;

    return f;           /* Returns double of type number f to the caller */
}
