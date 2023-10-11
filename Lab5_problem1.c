#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printMonth(int num) {
    switch(num) {
        case 0:
            printf("Jan.\t");
            break;
        case 1:
            printf("Feb.\t");
            break;
        case 2:
            printf("Mar.\t");
            break;
        case 3:
            printf("Apr.\t");
            break;
        case 4:
            printf("May\t");
            break;
        case 5:
            printf("June\t");
            break;
        case 6:
            printf("July\t");
            break;
        case 7:
            printf("Aug.\t");
            break;
        case 8:
            printf("Sept.\t");
            break;
        case 9:
            printf("Oct.\t");
            break;
        case 10:
            printf("Nov.\t");
            break;
        case 11:
            printf("Dec.\t");
            break;
        default:
            printf("Error, wrong number given.");
    }
}

float findMin(float arr[], int size) {
    float min = arr[0];
    for(int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

float findMax(float arr[], int size) {
    float max = arr[0];
    for(int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

float findAvg(float arr[], int size) {
    float avg = 0;
    for(int i = 0; i < size; i++) {
        avg += arr[i];
    }
    return (avg / size);
}

float findMovingAvg(float arr[], int size, int startMonth, int endMonth) {
    float avg = 0;
    for(int i = startMonth; i < endMonth+1; i++) {
        avg += arr[i];
    }
    avg /= ((endMonth - startMonth)+1);
    return avg;
}

void sortDesc(float arr[], int size, int months[]) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                temp = months[i];
                months[i] = months[j];
                months[j] = temp;
            }
        }
    }
}

int main() {

    FILE *fptr;
    fptr = fopen("input.txt", "r");
    char fOutput[100];
    float salesNums[12];
    int index = 0;
    while(fgets(fOutput, 100, fptr)) {
        salesNums[index] = atof(fOutput);
        index++;
    }

    printf("Monthly sales report for 2022:\n");
    printf("Month\t\tSales\n");
    for(int i = 0; i < sizeof(salesNums)/sizeof(salesNums[0]); i++) {
        printMonth(i);
        printf("$%.2f\n", salesNums[i]);
    }

    printf("\nSales Summary:\n");
    printf("Minimum sales:\t$%.2f\n", findMin(salesNums, 12));
    printf("Maximum sales:\t$%.2f\n", findMax(salesNums, 12));
    printf("Average sales:\t$%.2f\n", findAvg(salesNums, 12));

    printf("\nSix-Month Moving Average Report:\n");
    for(int i = 0; i < 7; i++) {
        printMonth(i);
        printf("- ");
        printMonth(i+5);
        printf("$%.2f\n", findMovingAvg(salesNums, 12, i, i+5));
    }

    float dupeNums[12];
    int monthNums[12] = {0,1,2,3,4,5,6,7,8,9,10,11};
    for(int i = 0; i < 12; i++) {
        dupeNums[i] = salesNums[i];
    }
    sortDesc(dupeNums, 12, monthNums);
    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month\tSales\n");
    for(int i = 0; i < sizeof(salesNums)/sizeof(salesNums[0]); i++) {
        printMonth(monthNums[i]);
        printf("$%.2f\n", dupeNums[i]);
    }
    

    fclose(fptr);

    return 0;
}