#include <stdio.h>
#include <cmath>

using namespace std;

double a, b, c, x, y;
bool isLiniar = false;
int roots = 0;

void inputData();
void findRoot(double a, double b, double c);
void printData();

int main() {
    inputData();
    findRoot(a, b, c);
    printData();
}

void inputData() {
    printf("Please enter coefficients\n");
    scanf("%lf%lf%lf", &a, &b, &c);
}

void findRoot(double a, double b, double c) {
    if (a == 0) {
        x = -1 * (c / b);
        roots = 1;
        isLiniar = true;
    } else {
        double discriminant = sqrt(b * b - 4 * a * c);
        if (discriminant >= 0) {
            x = (-1 * b + sqrt(b * b - 4 * a * c)) / 2 * a;
            y = (-1 * b - sqrt(b * b - 4 * a * c)) / 2 * a;
            if (x == y) {
                roots = 1;
            } else {
                roots = 2;
            }
        }
    }
}

void printData() {
    switch (roots) {
        case 0:
            printf("This equality has no roots\n");
            break;
        case 1:
            if (isLiniar) {
                printf("It is liniar equality. ");    
            }
            printf("Root of equality is %g\n", x);
            break;
        case 2:
            printf("Roots of equality are %g and %g\n", x, y);
            break;
    }

}