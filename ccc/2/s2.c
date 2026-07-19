#include <stdio.h>
void main_algorithm () {
    int tot_park_spots = 0;
    scanf ("%d", &tot_park_spots);
    int light_count = 0;
    scanf ("%d", &light_count);
    int num_spots_questioned = 0;
    scanf ("%d", &num_spots_questioned);
    int spots_questioned [num_spots_questioned];
    int light_spread [light_count][2];
    for (int step = 0; step < light_count; step++) {
        scanf ("%d %d", &light_spread [step][0], &light_spread [step][1]);
        light_spread [step][0] -= 1;
    } for (int step2 = 0; step2 < num_spots_questioned - 1; step2++) {
        scanf ("%d ", &spots_questioned [step2]);
        spots_questioned [step2] -= 1;
    } int infected [tot_park_spots];
    for (int set_normal = 0; set_normal < tot_park_spots; set_normal++) {infected [set_normal] = 0;}
    for (int counter = 0; counter < light_count; counter++) {
        if (light_spread [counter][1] == 0) {
            if (infected [light_spread [counter][0]] == 0) {infected [light_spread [counter][0]] = 1;}
        } else {
            for (int surround = -light_spread [counter][1]; surround <= light_spread [counter][1]; surround++) {
                if (((light_spread [counter][0] + surround) > -1) && ((light_spread [counter][0] + surround) < tot_park_spots)) {
                    if (infected [light_spread [counter][0] + surround] == 0) {infected [light_spread [counter][0] + surround] = 1;}
                }
            }
        }
    } for (int step3 = 0; step3 < num_spots_questioned - 1; step3++) {
        if (infected [spots_questioned [step3]] == 1) {printf ("Y\n");}
        else {printf ("N\n");}
    }
} int main () {
    main_algorithm ();
    return 0;
}

