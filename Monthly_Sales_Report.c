#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int monthly_sales_report(double sales_numbers[], char months[][10]) {
    printf("Monthly sales report for 2022: \n");
    printf("Month      Sales\n");
    for (int i = 0; i < 12; i++) {
        printf("%-10s $%.2lf\n", months[i], sales_numbers[i]);
    }
    printf("\n");
    return 1;
}

int sales_summary(double sales_numbers[], char months[][10]) {
    double sales_max = 0;
    double sales_min = 100000;
    double sales_avg = 0;
    double sales_total = 0;
    char min_month[10];
    char max_month[10];
     for (int i = 0; i < 12; i++) {
        if (sales_numbers[i] > sales_max) {
            sales_max = sales_numbers[i];
            strcpy(max_month, months[i]);
        }
        if (sales_numbers[i] < sales_min) {
            sales_min = sales_numbers[i];
            strcpy(min_month, months[i]);
        }
        sales_total += sales_numbers[i];
    }
    sales_avg = sales_total / 12;
    printf("Sales Summary: \n");
    printf("Minimum Sales: $%.2lf (%s)\n", sales_min, min_month);
    printf("Maximum Sales: $%.2lf (%s)\n", sales_max, max_month);
    printf("Average Sales: $%.2lf\n\n", sales_avg);

    return 1;
}

int moving_average_report(double sales_numbers[], char months[][10]) {
    printf("Six-Month Moving Average Report: \n");
    for (int i = 0; i < 7; i++) {
        double total = 0;
        for (int j = i; j < i + 6; j++) {
            total += sales_numbers[j % 12];
        }
        printf("%s - %s $%.2lf\n", months[i], months[i + 5], total / 6);
    }
    printf("\n");
    return 1;
}

int highest_to_lowest(double sales_numbers[], char months[][10]) {
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month     Sales\n");

    struct MonthlySales {
        char month[10];
        double sales;
    } sales_data[12];
    for (int i = 0; i < 12; i++) {
        strcpy(sales_data[i].month, months[i]);
        sales_data[i].sales = sales_numbers[i];
    }

    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (sales_data[i].sales < sales_data[j].sales) {
                struct MonthlySales temp = sales_data[i];
                sales_data[i] = sales_data[j];
                sales_data[j] = temp;
            }
        }
    }

    for (int i = 0; i < 12; i++) {
        printf("%-10s $%.2lf\n", sales_data[i].month, sales_data[i].sales);
    }
    return 1;
}


int main() {
    char months[12][10] = {"January", "February", "March", "April", "May", "June",
                "July", "August", "September", "October", "November", "December"};
    FILE *file;
    double numbers[100];
    int count = 0;
    file = fopen("sales.txt", "r");

    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    while (fscanf(file, "%lf", &numbers[count]) != EOF) {
        count++;
    }

    fclose(file);

    monthly_sales_report(numbers, months);
    sales_summary(numbers, months);
    moving_average_report(numbers, months);
    highest_to_lowest(numbers, months);
    return 0;
}

