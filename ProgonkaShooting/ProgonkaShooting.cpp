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
    int f = 3, d1 = 3, d2 = -1, d = 4, e1 = 1, e2 = -2, e = 1, a = 0, b = 1;
    const int n = 10;
    double h = (b - a) / n;
    double r1 = d2 / (d2 - d1 * h), r2 = e2 / (e1 * h + e2), s1 = d * h / (d1 * h - d2), s2 = e * h / (e1 * h + e2);
    if (r1 > 1 && r2 > 1) return 0;
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (abs(B(x, h)) < abs(A(x, h)) + abs(C(x, h))) {
            return 0;
        }
    }
    double answer[n];
    double alpha = r1, beta = s1;
    answer[0] = (s2 + beta * r2) / (1 - alpha * r2);
    for (int i = 1; i < n; i++) {
        double x = a + (i - 1) * h;
        beta = (beta * A(x, h) - f) / (B(x, h) - alpha * A(x, h));
        alpha = C(x, h) / (B(x, h) - alpha * A(x, h));
        answer[i] = (s2 + beta * r2) / (1 - alpha * r2);
        std::cout << i << ": " << answer[i] << "\n";
    }
}