    #include<stdio.h>
    #include<stdlib.h>

    double pi_compute(double n);

    double pi_compute(double n)
    {
        if(n == 0.0) {
            return 2.0;
        }
        else {
            return(n/(2.0*n + 1.0)*pi_compute(n - 1.0));
        }
    }

    int main(void)
    {
        double sum = 0.0, n;
        printf("Enter the number of terms!\n");
        scanf("%lf", &n);
        for(double i = 0.0; i < n; i += 1.0){
            sum += pi_compute(i);
        }

        printf("%f\n", sum);
        return EXIT_SUCCESS;
    }
