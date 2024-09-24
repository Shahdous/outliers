#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double calculateMean(double numbers[], int size){
    double total = 0.0;

    for(int i = 0; i < size; i++){
        total += numbers[i];
    }

    double mean = total / size;
    return mean;
}

double standardDeviation(double numbers[], int size){

    double mean = calculateMean(numbers, size);
    double variance = 0.0;

    for (int i = 0; i < size; i++) {
        variance += pow(numbers[i] - mean, 2);
    }

    variance = variance / size;

    double sd = sqrt(variance);
    return sd;
}

void outliers(double numbers[], int size, double* lowerBound, double* upperBound){
    
    double mean = calculateMean(numbers, size);

    double sd = standardDeviation(numbers, size);

    *upperBound = mean + 2 * (sd / sqrt(size));
    *lowerBound = mean - 2 * (sd / sqrt(size));
}

int main(int argc, char ** argv){

    int x;

    scanf("%d", &x);

    if (x <= 0) {
        printf("Invalid input\n");
        return EXIT_FAILURE;
    }

    double data[x];

    printf("Enter the elements: \n");
    for (int i = 0; i < x; i++) {

        scanf(" %lf", &data[i]);
    }

    double lowerBound, upperBound;
    outliers(data, x, &lowerBound, &upperBound);

    printf("Lower Bound: %f\n", lowerBound);
    printf("Upper Bound: %f\n", upperBound);
    printf("The Values that are within the range of upper and lower bound are: \n");
    
    for(int i = 0; i < x; i++){
        if(data[i] >= lowerBound && data[i] <= upperBound){
            printf("%f\n", data[i]);
        }
    }

    
}