#include <stdio.h>
#include <math.h>

//Function to integrate
double myfunc(double x)
{
  double r;
  r = 4./(1 + (x*x));
  return r;
}

double Trapezoidal(double (*f)(double x), double xl, double xh, int n)
{
  double low, high, N, I;
  int i;
  I = 0;
  // Divide interval into n subintervals
  N = ((xh - xl)/n);
  
  for (i = 0; i < n; i++)
  {
    if ((*f)(xl + N) > (*f)(xl))
    {
      high = (*f)(xl + N);
      low = (*f)(xl);
      I = ((low*N) + ((high - low)*N*0.5)) + I;
      xl = xl + N;
    }
    else
    {
      low = (*f)(xl + N);
      high = (*f)(xl);
      I = ((low*N) + ((high - low)*N*0.5)) + I;
      xl = xl + N;
    }
  }
  return I;
}

int main()
{
  double a, b, c;
  int i;
  printf("Enter x1 and xh for Trapezoid\n");
  scanf("%lf %lf", &a, &b);
  for (i = 0; i<100000; i++)
  {
    c = Trapezoidal(myfunc, a, b, 1000);
  }
  printf("%.15lf \n", c);
}