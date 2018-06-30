  /*--------------------------------------------------------------------------------------------------

    A program that analyzes the difference in tone color 
    by Fourier transforming the waveform of the sound of an instrument.

    [Specification of sound source file]
    (1) Record waveform data as a 16-bit integer. Numerical range is -32768 to 32767 (0: silent state)
    (2) Sample rate is 44.1 kHz (= time interval 1/44100 sec.The same standard as music CD)
    (3) One point of sample data per line. A total of 22050 lines (0.5 seconds)

  -----------------------------------------------------------------------------------------------------*/
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>

  /* Definition of symbol constant */
  #define SAMPLE_RATE 44100	/* Sample rate of sound waveform data (Hz) */
  #define NUM_DATA 22050		/* Number of sample points of sound waveform data N */
  #define NUM_FREQ 11025		/* The number of k (frequency division number）(= N/2) */

  /* prototype declaration */
  void readWave( char filename[], int N, double xt[] );
  void writeSpectrum( char filename[], int Nk,
                      double f[], double sp[], double Re_F[], double Im_F[] );
  void windowing( int N, double xt[] );
  void fourierTrans( int N, double xt[], double Re_F[], double Im_F[] );

  int main(void) {
      /* Variable declaration */
      double x_n[NUM_DATA], f_k[NUM_FREQ], I_k[NUM_FREQ], a_k[NUM_FREQ], b_k[NUM_FREQ];
      char readfile[20], writefile[20];

      /* Read sound source data */
      printf("Please enter the sound source file name:");
      /* Output for the buffer */
      fflush(0);  
      scanf("%20s",&readfile);
      readWave(readfile, NUM_DATA, x_n);

      /* Multiply waveform data by window function */
      windowing(NUM_DATA, x_n);

      /* Fourier transform */
      fourierTrans(NUM_DATA, x_n, a_k, b_k);

      /* Compute spectral density:I and frequency:f */
      for(int k=0; k<NUM_FREQ; k++){
          I_k[k] = sqrt(a_k[k]*a_k[k] + b_k[k]*b_k[k]);
          f_k[k] = (k / (double)NUM_DATA) * (double)SAMPLE_RATE;
      }

      /* Output spectra */
      printf("Please enter output file name:");
      /* Output for the buffer */
      fflush(0);  
      scanf("%20s", writefile);
      writeSpectrum(writefile, NUM_FREQ, f_k, I_k, a_k, b_k);
      printf("Calculation is complete.\n");

      return 0;
  }

  /*----------------------------------------------------------------------------
    Function to read waveform data from sound source file

    (in)  filename: sound source file name
                 N: Number of elements of waveform data xt []

    (out)   xt [i]: waveform data
  ----------------------------------------------------------------------------*/
    void readWave(char filename[], int N, double xt[]) 
    {
    /* Declaration of file pointer. fi:For input */
    FILE *fi;	

    /* Open input file */
    if ( (fi = fopen(filename, "r") ) == NULL) {
    printf("The input file %s can not be opened.\n", filename);
      /* forced termination */
    exit(1);		
    }

    /* Read waveform data from file */
    for (int i=0; i<N ;i++){
    fscanf(fi, "%lf", &xt[i]);
    }

    /* Close input file */
    fclose(fi);	

    return;
    }

  /*----------------------------------------------------------------------------
    A function that outputs the calculation result of sound spectrum to a file

    (in)filename: output file name
              Nk: Number of elements of spectral data
           f [k]: frequency (unit: Hz)
          sp [k]: spectrum
      Re - F [k]: real part of spectrum
      Im - F [k]: imaginary part of spectrum
  ----------------------------------------------------------------------------*/
  void writeSpectrum( char filename[], int Nk,
    double f[], double sp[], double Re_F[], double Im_F[] ) {

    FILE *fo;	/* Declaration of file pointer. fo:for output */

    /* Open input file */
    if ( (fo = fopen(filename, "w") ) == NULL) {
      printf("Unable to open output file:%s.\n", filename);
    /* forced termination */
      exit(1);		
    }

    fprintf(fo, "#-------------------------------------------------------------\n");
    fprintf(fo, "# freq(Hz)   Spectrum      Re_F(k)            Im_F(k)\n");
    fprintf(fo, "#-------------------------------------------------------------\n");
    for (int i = 0; i < Nk; i++){
      fprintf(fo, "%9.3f   %11.5e   %11.5e   %11.5e\n", f[i], sp[i], Re_F[i], Im_F[i]); 
    }
    fprintf(fo, "#-------------------------------------------------------------\n");

    /* Close the output file */
    fclose(fo);

    return;
  }

  /*----------------------------------------------------------------------------
    A function that multiplies waveform data by "window function"

    (in)       N: Number of elements of waveform data xt []
          xt [i]: waveform data

    (out) xt [i]: waveform data (multiplied by a window function)
  ----------------------------------------------------------------------------*/
  void windowing( int N, double xt[] ) {

    for (int i = 0; i < N; i++){
      xt[i] = xt[i]*(1.0/2.0)*(1.0 - cos((2.0*M_PI*i)/N));
    }	
    return;
  }

  /*--------------------------------------------------------------------------------------------------
  Function to perform discrete Fourier transform (DFT)

    (in)         N: Number of elements of the original waveform data xt [] (number of sampling points)
            xt [i]: original waveform data

    (out) Re_F [k]: real part (a_k) of the function X_k after the Fourier transform
          Im_F [k]: the imaginary part (b_k) of the function X_k after the Fourier transform
  ----------------------------------------------------------------------------------------------------*/
  void fourierTrans( int N, double xt[], double Re_F[], double Im_F[] ) {
    /*Compute a_k and b_k*/
    for (int k = 0; k < N/2; k++){
      for (int i = 0; i < N; i++){
        Re_F[k] += xt[i]*cos((2.0*M_PI*k*i)/N);
        Im_F[k] += xt[i]*sin((2.0*M_PI*k*i)/N);		
      }		
    }
    return;
  }