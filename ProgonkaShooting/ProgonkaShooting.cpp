#include <iostream>

double p(double x) {
    return -7;
}

double q(double x) {
    return 12;
}

double f(double x) {
    return 5;
}

double u(double x) {
    return (1.0 / 4.0) * exp(4 * x) + (1.0 / 3.0) * exp(3 * x) + 5.0 / 12.0;
}

int main()
{
    const int n = 100;
    double a = 0, b = 1, A = 1, C = 2, h = (b-a)/n;
    double D0 = A + h, D1 = h;
    double y[2][n + 1];
    y[0][0] = A;
    y[0][1] = D0;
    y[1][0] = 0;
    y[1][1] = D1;
    for (int i = 2; i <= n; i++) {
        double x = a + i * h;
        y[0][i] = (h * h * f(x) - (1.0 - (h / 2) * p(x)) * y[0][i - 2] - (h * h * q(x) - 2) * y[0][i - 1]) / (1 + h / 2 * p(x));
        y[1][i] = (-(1 - h / 2 * p(x)) * y[1][i - 2] - (h * h * q(x) - 2) * y[1][i - 1]) / (1 + h / 2 * p(x));
    }
    double B = u(b);
    double c1 = (B - (double)y[0][n]) / y[1][n];
    double maxErr = 0;
    for (int i = 0; i <= n; i++) {
        double x = a + i * h;
        double Y = y[0][i] + c1 * y[1][i];
        if (abs(u(x) - Y) > maxErr) maxErr = abs(u(x) - Y);
        std::cout << x << ": " << Y << "\n";
    }
    std::cout << "maximum error: " << maxErr;
}