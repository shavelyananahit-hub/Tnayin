#include "qe.h"
#include <cmath>

void qef(double a, double b, double c, double &x1, double &x2)
{
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                x1 = x2 = 1;
            } else {
                x1 = x2 = -1;
            }
        } else {
            x1 = x2 = -c / b;
        }
    } else {
        double D = b * b - 4 * a * c;

        if (D < 0) {
            x1 = x2 = -1;
        } else {
            x1 = (-b + sqrt(D)) / (2 * a);
            x2 = (-b - sqrt(D)) / (2 * a);
        }
    }
}
