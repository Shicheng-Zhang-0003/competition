#include <stdio.h>
#include <stdlib.h>
int absolute (long long x);
int absolute (long long x) {
    if (x < 0) {return -x;}
    else {return x;}
} void main_algorithm () {
    long long hop_k;
    long long start, end, one_two;
    scanf ("%lld", &start);
    scanf ("%lld", &end);
    scanf ("%lld", &hop_k);
    scanf ("%lld", &one_two);
    long long initial = start;
    long long counter_steps = 1;
    if (start >= end) {printf ("0\n"); exit (0);}
    long long rst1 = 0, rst2 = 0;
    while (1) {

        start += hop_k;
        if ((start == end) && (counter_steps != 1)) {break;}
        else {
            if (absolute (end - start) < hop_k) {
                long long buffer_start = start + hop_k;
                if ((absolute (end - start)) <= (absolute (end - buffer_start))) {
                    long long added1 = (start - initial) / hop_k;
                    long long added2 = (buffer_start - initial) / hop_k;
                    rst1 = added1 + absolute (end - added1 * hop_k);
                    rst2 = added2 + absolute (end - added2 * hop_k);
                    counter_steps = -1;
                    break;
                } else {
                    long long added1 = (start - initial) / hop_k;
                    long long added2 = (buffer_start - initial) / hop_k;
                    rst1 = added2 + absolute (end - added2 * hop_k);
                    rst2 = added1 + absolute (end - added1 * hop_k);
                    counter_steps = -1;
                    break;
                }
            } else {continue;}
        } counter_steps += 1;
    } if (counter_steps == -1) {
        if (one_two == 1) {printf ("%lld\n", rst1);}
        else if (one_two == 2) {printf ("%lld\n", rst2);}
    } else {printf ("%lld\n", counter_steps);}
} int main () {
    main_algorithm ();
    return 0;
}
