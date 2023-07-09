#include <stdio.h>
#include <math.h>

#define square(x) (x * x)

double root_mean_square_error(double predicted[], double observed[], int N) {
    // RMSE = sqrt( (square(y1) + square(y2) + ... + square(yn)) / length)
    //  yn = predicted[n] - observed[n]
    double y = 0.0;
    
    // sum of , from 1 - N : square(y1) + square(y2) + ... + square(yn)
    for (int i = 0; i < N; i++) {
        double _y = predicted[i] - observed[i];
        y += square(_y);
    }
    
    double mse = y / N;
    
    return sqrt(mse);
}

int main() {
    double predicted[] = {4, 25,  0.75, 11};
    double observed[] = {3, 21, -1.25, 13};
    
    int length = sizeof(predicted)/sizeof(predicted[0]);

    double rmse = root_mean_square_error(predicted, observed, length);
    
    printf("Root-Mean-Square Error: %.3lf\n", rmse);
    
    return 0;
}
