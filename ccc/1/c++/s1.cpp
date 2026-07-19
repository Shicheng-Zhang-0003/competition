#include <iostream>
using namespace std;
long long absolute (long long x);
long long absolute (long long x) {
    if (x < 0) {return -x;}
    else {return x;}
} void main_algorithm () {
    long long hop_k;
    long long start, end, one_two;
    cin >> start;
    cin >> end;
    cin >> hop_k;
    cin >> one_two;
    long long initial = start;
    long long counter_steps = 1;
    long long two_trigger = 0;
    if (start >= end) {cout << "0\n"; exit (0);}
    long long gap = absolute (end - start);
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
        if (one_two == 1) {cout << rst1 << "\n";}
        else if (one_two == 2) {cout << rst2 << "\n";}
    } else {cout << counter_steps << "\n";}
} int main () {
    main_algorithm ();
    return 0;
}
