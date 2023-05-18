#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;
const int NUM_MONTHS = 12;

void consoleMenu() {
    cout << "Annual Results Program" << endl;
}

void addRevenueAndCosts(double (&revenue)[NUM_MONTHS], double (&costs)[NUM_MONTHS], int size) {
    for (int i = 0; i < size; i++) {
        double input;
        cout << "Add revenue for month " << i + 1 << ": ";
        while (!(cin >> input) || input < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number: ";
        }
        revenue[i] = input;

        cout << "Add costs for month " << i + 1 << ": ";
        while (!(cin >> input) || input < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number: ";
        }
        costs[i] = input;
    }
}

double sum(double table[], int size) {
    double sumElements = 0;
    for (int i = 0; i < size; ++i)
        sumElements += table[i];
    return sumElements;
}

double avarageTable(double table[], int size) {

    return sum(table, size) / size;
}

double maxTable(double table[], int size) {
    double max = table[0];
    for (int i = 1; i < size; ++i)
        if (table[i] > max)
            max = table[i];
    return max;
}

double minTable(double table[], int size) {
    double min = table[0];
    for (int i = 1; i < size; ++i)
        if (table[i] < min)
            min = table[i];
    return min;
}

int indexMax(double table[], int size) {
    double max = table[0];
    int indexMax = 0;
    for (int i = 1; i < size; ++i)
        if (table[i] > max) {
            indexMax = i;
        }
    return indexMax + 1;
}

int indexMin(double table[], int size) {
    double min = table[0];
    int indexMin = 0;
    for (int i = 1; i < size; ++i)
        if (table[i] < min) {
            indexMin = i;
        }
    return indexMin + 1;
}

void calcProfit(double revenue[NUM_MONTHS], double costs[NUM_MONTHS], double (&profit)[NUM_MONTHS], int size) {
    for (int i = 0; i < size; i++)
        profit[i] = revenue[i] - costs[i];
}

void printTable(double column1[], double column2[], double column3[], int size) {
    cout << endl << "Revenue\tCosts\tProfit\tSummary" << endl;
    for (int i = 0; i < size; i++) {
        cout << fixed << setprecision(2) << column1[i] << "\t"
             << fixed << setprecision(2) << column2[i] << "\t"
             << fixed << setprecision(2) << column3[i] << "\t";

        if (column3[i] < 0) {
            cout << "loss" << endl;
        } else if (column3[i] > 0) {
            cout << "profit" << endl;
        } else {
            cout << "zero" << endl;
        }
    }
}

int main() {
    double revenue[NUM_MONTHS];
    double costs[NUM_MONTHS];
    double profit[NUM_MONTHS];

    consoleMenu();
    addRevenueAndCosts(revenue, costs, NUM_MONTHS);
    calcProfit(revenue, costs, profit, NUM_MONTHS);

    cout << endl << "Sum of annual revenues: " << sum(revenue, NUM_MONTHS);
    cout << endl << "Sum of annual costs: " << sum(costs, NUM_MONTHS);
    cout << endl << "Sum of annual profit: " << sum(profit, NUM_MONTHS);

    cout << endl << "Min revenue: " << minTable(revenue, NUM_MONTHS) << " in the month: "
         << indexMin(revenue, NUM_MONTHS);
    cout << endl << "Min cost: " << minTable(costs, NUM_MONTHS) << " in the month: " << indexMin(costs, NUM_MONTHS);
    cout << endl << "Min profit: " << minTable(profit, NUM_MONTHS) << " in the month: " << indexMin(profit, NUM_MONTHS);

    cout << endl << "Max revenue: " << maxTable(revenue, NUM_MONTHS) << " in the month: "
         << indexMax(revenue, NUM_MONTHS);
    cout << endl << "Max cost: " << maxTable(costs, NUM_MONTHS) << " in the month: " << indexMax(costs, NUM_MONTHS);
    cout << endl << "Max profit: " << maxTable(profit, NUM_MONTHS) << " in the month: " << indexMax(profit, NUM_MONTHS);

    cout << endl << "Avarage revenue: " << avarageTable(revenue, NUM_MONTHS);
    cout << endl << "Avarage cost: " << avarageTable(costs, NUM_MONTHS);
    cout << endl << "Avarage profit: " << avarageTable(profit, NUM_MONTHS);
    cout << endl;

    printTable(revenue, costs, profit, NUM_MONTHS);
    return 0;
}

