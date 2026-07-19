/*
  Leetcode 18: 4Sum
    
  This is a solution to Leetcode quesiton 18, 4Sum, which asks for the addition
  of 4 values in a array (or not) which is equal to a target value. This is done
  in this program by dividing the array and using non-repeating for loops to 
  incrementally add each value until it registers quadruplets which add to the target.

  Copyright 2025. 25/10/25. Shicheng Z.
*/
#include <stdio.h>
#include <stdbool.h>
int check_contiguous (int size_arr, int array [size_arr]);
int check_contiguous (int size_arr, int array [size_arr]) {
    //String size is size_arr, input will always be 4
    int current = array [0];
    for (int x = 1; x < 4; x++) {
        if (array [x] >= current) {current = array [x];}
        else {return false;}
    } return true;
} void main_algorithm () {
    int size_arr = 0;
    printf ("Enter the size of the seed array:");
    scanf ("%d", &size_arr);
    int array [size_arr];
    for (int y = 0; y < size_arr; y++) {
        printf ("Enter the attribute %d:", y);
        scanf ("%d", &array [y]);
    } int target = 0;
    printf ("Enter the target value:");
    scanf ("%d", &target); 
    for (int z = 0; z < size_arr; z++) {
        for (int a = 0; a < size_arr; a++) {
            int temp = 0;
            if (array [a] > array [z]) {
                temp = array [z];
                array [z] = array [a];
                array [a] = temp;
            }
        }
    } int total_rst = 0; 
    for (int b = 0; b < size_arr - 4; b++) {
        int output [4] = {0};
        output [0] = array [b];
        for (int c = 0; c < size_arr; c++) {
            if (c == b) continue;
            else {
                output [1] = array [c];
                for (int d = 0; d < size_arr; d++) {
                    if (d == c) continue;
                    else {
                        output [2] = array [d];
                        for (int e = 0; e < size_arr; e++) {
                            if (e == d) continue;
                            else {
                                output [3] = array [e];
                                total_rst = output [0] + output [1] + output [2] + output [3];
                                if (total_rst == target) {
                                    if (check_contiguous (4, array) == true) {printf ("{%d, %d, %d, %d}\n", output [0], output [1], output [2], output [3]);}
                                } else continue;        
                            }
                        }
                    }
                }
            }
        }
    } 
} int main () {
    main_algorithm ();
    return 0;
}
