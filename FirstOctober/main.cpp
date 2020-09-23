#include <stdio.h>
#include <math.h>

#define eps 10^-7

double fx(double x) { return x*x-17;} // ����������� �������
double dfx(double x) { return 2*x;} // ����������� �������
typedef double(*function)(double x); // ������� ���� function

double solve(function fx, function dfx, double x0) {
  double x1  = x0 - fx(x0)/dfx(x0); // ������ ����������
  while (fabs(x1-x0)>eps) { // ���� �� ���������� �������� 0.000001
    x0 = x1;
    x1 = x1 - fx(x1)/dfx(x1); // ����������� �����������
  }
  return x1;
}

int main () {
  printf("%f\n",solve(fx,dfx,4)); // ����� �� �����
  return 0;
}
