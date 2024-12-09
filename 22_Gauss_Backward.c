#include <stdio.h>

// Function to calculate factorial
int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

// Gauss Backward Interpolation
int main()
{
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n][n];
    printf("Enter the values of x: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }

    printf("Enter the values of y: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &y[i][0]);
    }

    // Backward Difference Table
    for (int j = 1; j < n; j++)
    {
        for (int i = n - 1; i >= j; i--)
        {
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }

    // Display Backward Difference Table
    printf("\nBackward Difference Table:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f", x[i]);
        for (int j = 0; j <= i; j++)
        {
            printf("\t%f", y[i][j]);
        }
        printf("\n");
    }

    // Interpolation
    float value, h, u, result;
    printf("\nEnter the value of x for interpolation: ");
    scanf("%f", &value);

    h = x[1] - x[0];
    u = (value - x[n - 1]) / h;

    result = y[n - 1][0];
    for (int i = 1; i < n; i++)
    {
        float term = y[n - 1][i];
        for (int j = 0; j < i; j++)
        {
            term *= (u + j);
        }
        term /= factorial(i);
        result += term;
    }

    printf("\nThe interpolated value at x = %f is %f\n", value, result);

    return 0;
}
