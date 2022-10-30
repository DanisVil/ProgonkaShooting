#include <iostream>


double p(double x) {
    return -3 * (x + 1) * (x + 1);
}


double q(double x) {
    return -2 / (x + 1) / (x + 1);
}


double u(double x) {
    return 1 / (x + 1);
}


double A(double x, double h) {
    return 1 / (h * h) - p(x) / (2 * h);
}


double B(double x, double h) {
    return 2 / (h * h) - q(x);
}


double C(double x, double h) {
    return 1 / (h * h) + p(x) / (2 * h);
}


int main()
{
    double f = 3, d1 = 3, d2 = -1, d = 4, e1 = 1, e2 = -2, e = 1, a = 0, b = 1;
    const int n = 1000;
    double h = (b - a) / n;
    double r1 = d2 / (d2 - d1 * h), r2 = e2 / (e1 * h + e2), s1 = d * h / (d1 * h - d2), s2 = e * h / (e1 * h + e2);
    if (r1 > 1 && r2 > 1) return 0;
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (abs(B(x, h)) < abs(A(x, h)) + abs(C(x, h))) {
            return 0;
        }
    }
    double alphas[n], betas[n], y[n + 1];
    alphas[0] = r1;
    betas[0] = s1;
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        alphas[i] = C(x, h) / (B(x, h) - alphas[i - 1] * A(x, h));
        betas[i] = (betas[i - 1] * A(x, h) - f) / (B(x, h) - alphas[i - 1] * A(x, h));
    }

    y[n] = (betas[n - 1] * r2 + s2) / (1 - alphas[n - 1] * r2);
    double maxErr = abs(y[n] - u(b));
    for (int i = n - 1; i >= 0; i--) {
        y[i] = alphas[i] * y[i + 1] + betas[i];
        if (abs(y[i] - u(a + i * h) > maxErr)) maxErr = abs(y[i] - u(a + i * h));
    }
    for (int i = 0; i <= n; i++) {
        std::cout << a + i * h << ": " << y[i] << "\n";
    }
    std::cout << "Maximum error: " << maxErr;
}