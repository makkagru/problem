#include <stdio.h>
#include <cmath>

void inputData(double&, double&, double&);
void findRoot(double&, double&, double&, double&, double&, int&, bool&);
void printData(double&, double&, int&, bool&);

int main() {
    double a, b, c, x, y;
    int roots = 0;
    bool isLinear = false;
    inputData(a, b, c);
    findRoot(a, b, c, x, y, roots, isLinear);
    printData(x, y, roots, isLinear);
}

void inputData(double &a, double &b, double &c) {
    printf("Please enter coefficients\n");
    scanf("%lf%lf%lf", &a, &b, &c);
}

void findRoot(double &a, double &b, double &c, double &x, double &y, int &roots, bool &isLinear) {
    if (a == 0) {
        x = -1 * (c / b);
        roots = 1;
        isLinear = true;
    } else {
        double discriminant = b * b - 4 * a * c;
        if (discriminant >= 0) {
            x = (-1 * b + sqrt(discriminant)) / 2 * a;
            y = (-1 * b - sqrt(discriminant))/ 2 * a;
            if (x == y) {
                roots = 1;
            } else {
                roots = 2;
            }
        }
    }
}

void printData(double &x, double &y, int &roots, bool &isLinear) {
    switch (roots) {
        case 0:
            printf("This equality has no roots\n");
            break;
        case 1:
            if (isLinear) {
                printf("It is liniar equality. ");    
            }
            printf("Root of equality is %g\n", x);
            break;
        case 2:
            printf("Roots of equality are %g and %g\n", x, y);
            break;
    }

}