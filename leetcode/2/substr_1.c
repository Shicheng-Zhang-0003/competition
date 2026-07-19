#include <stdio.h>
int main () {
    int size_arr = 0;
    printf ("Enter the size of the array:");
    scanf ("%d", &size_arr);
    int array [size_arr];
    for (int x = 0; x < size_arr; x++) {
        printf ("Enter attribute %d:", x + 1);
        scanf ("%d", &array [x]);
    } int total_amt = 0;
    for (int count = 1; count < size_arr + 1; count++) {
        for (int iteration = 0; iteration <= (size_arr - count); iteration++) {
            int temp [count], secret_counter = 0;
            for (int step = 0; step < count; step++) {temp [step] = array [step + iteration];}
            int temp_total = 0;
            for (int counter = 0; counter < count; counter++) {temp_total += temp [counter];}
            if (temp_total == count) {total_amt += 1;}
        }
    } printf ("%d\n", total_amt); return 0;
}
