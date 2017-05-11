#include<iostream>
#include<gsl/gsl_statistics_double.h>
using namespace std;
int main()
{
  double a[5] = {1,2,3,4,5};
  double b[5] = {-1, 1, -1, 1, 3};
  double res;
  res = gsl_stats_correlation(a, 1, b, 1, 5);
  cout << res << endl;
}
