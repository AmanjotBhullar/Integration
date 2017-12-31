#include <stdio.h>
#include <math.h>

//Function to integrate
double myfunc(double x)
{
  double r;
  r = 4./(1 + (x*x));
  return r;
}

double Romberg(double (*f)(double x), double xl, double xh, int n)
{
  int i, j, k, l, m;
  double R[n], C[n], h, sum;
  
  sum = 0;
  R[0] = (((*f)(xl) + (*f)(xh))/2);
  
  // R(0, 0) to R(n, 0)
  for (j = 1; j <= n; j++)
  {
    h = (xh - xl)/(pow(2, j));
    sum = 0;
    for (k = 1; k<= pow(2, (j - 1)); k++)
    {
      sum = sum + (*f)(xl + ((2*k) - 1)*h);
    }
    R[j] = ((R[j-1]*0.5) + h*sum);
  }
  
  // upto R(n, n)
  for (l = 1; l <= n; l++)
  {
    // Calculate higher levels of R(x, y)
    for (i = l; i <= n; i++)
    {
      C[i] = (((pow(4, l)*R[i]) - R[i-1])/(pow(4, l) - 1));
    }
    // Replace R values with C values
    for (m = l; m <= n; m++)
    {
      R[m] = C[m];
    }
  }
  return R[n];
}

int main()
{
  double d, e, f;
  int i;
  printf("Enter x1 and xh for Romberg \n");
  scanf("%lf %lf", &d, &e);
  for (i=0; i<100000; i++)
  {
    f = Romberg(myfunc, d, e, 8);
  }
  printf("%.15lf \n", f);
}