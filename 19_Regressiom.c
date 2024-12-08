// Regression Lines
#include <math.h>
#include <stdio.h>

int main()
{
    int n, i;
    float x, y, m1, c1, m2, c2, d1, d2;
    float sumx = 0, sumxsq = 0, sumy = 0, sumysq = 0, sumxy = 0;

    printf("Enter the number of data points (n): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the values of x and y for data point %d: ", i + 1);
        scanf("%f%f", &x, &y);
        sumx += x;
        sumxsq += x * x;
        sumy += y;
        sumysq += y * y;
        sumxy += x * y;
    }

    // Calculate determinants
    d1 = n * sumxsq - sumx * sumx; // Denominator for y on x
    d2 = n * sumysq - sumy * sumy; // Denominator for x on y

    // Regression line: y on x
    m1 = (n * sumxy - sumx * sumy) / d1;
    c1 = (sumy * sumxsq - sumx * sumxy) / d1;

    // Regression line: x on y
    m2 = (n * sumxy - sumx * sumy) / d2;
    c2 = (sumx * sumysq - sumy * sumxy) / d2;

    printf("The regression line (y on x) is: y = %.2fx + %.2f\n", m1, c1);
    printf("The regression line (x on y) is: x = %.2fy + %.2f\n", m2, c2);

    return 0;
}
