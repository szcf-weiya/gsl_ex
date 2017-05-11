#include <iostream>
#include <gsl/gsl_fit.h>

using namespace std;

int main()
{
  int i, n = 4;
  double x[4] = {1970, 1980, 1990, 2000};
  double y[4] = {12, 11, 14, 13};
  double w[4] = {0.1, 0.2, 0.3, 0.4};

  double c0, c1, cov00, cov01, cov11, chisq;

  gsl_fit_wlinear(x, 1, w, 1, y, 1, n,
		  &c0, &c1, &cov00, &cov01, &cov11,
		  &chisq);
  cout << "# best fit: Y =" << c0 << " + "<< c1 << "X\n" <<endl;
  return 0;
}
