#include<iostream>
#include<gsl/gsl_matrix.h>
#include<gsl/gsl_vector.h>
#include<gsl/gsl_blas.h>
using namespace std;

int main()
{
  double a_data[] = { 0.18,
0.41,
0.14,
0.51,
0.60,
0.24,
0.30,
0.13,
0.57,
0.99,
0.97,
0.19,
0.96,
0.58,
0.66,
0.85 };
  double b_data[] = { 1.0, 2.0, 3.0, 4.0 };
  gsl_matrix_view m = gsl_matrix_view_array (a_data, 4, 4);
  gsl_vector_view b = gsl_vector_view_array (b_data, 4);
  // A = gsl_matrix_calloc(4, 4);
  //  b = gsl_vector_calloc(4);
  /*
  for (size_t i = 0; i < 4; i++)
    {
      for (size_t j = 0; j < 4; j++)
	{
	  gsl_matrix_set(A, i, j, i+j);
	}
      gsl_vector_set(b, i, i+1);
    }
  */
  for (size_t i = 0; i < 4; i++)
    {
      for (size_t j = 0; j < 4; j++)
	{
	  cout << gsl_matrix_get(&m.matrix, i, j) << " ";
	}
      cout << endl;
    }
  // toy example of getting one row of a matrix add @20181013
  gsl_vector_view vv = gsl_matrix_row(&m.matrix, 2);
  cout << "test" << endl;
  for (size_t i = 0; i < 4; i++)
    {
      cout << gsl_vector_get(&vv.vector, i) << endl;
    }
  // end of toy example
  /*  for (size_t i = 0; i < 4; i++)
    cout << gsl_vector_get(&b.vector, i) << " ";
  //  gsl_vector_free(b);
  //gsl_matrix_free(A);
  gsl_blas_dtrsv(CblasLower, CblasNoTrans, CblasUnit, &m.matrix, &b.vector);
  for (size_t i = 0; i < 4; i++)
    cout << gsl_vector_get(&b.vector, i) << " ";
  */
  return 0;
}
