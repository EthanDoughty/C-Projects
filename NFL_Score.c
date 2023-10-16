#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void score_combination_report(int score) {
    int td1, td2, td3, fg, safety;
    for (td1 = 0; td1*8 <= score; td1++) {
        for (td2 = 0; td2*7 <= score; td2++) {
            for (td3 = 0; td3*6 <= score; td3++) {
                for (fg = 0; fg*3 <= score; fg++) {
                    for (safety = 0; safety*2 <= score; safety++) {
                         if (2 * td1 + 3 * td2 + 3 * fg + 3 * td3 + 2 * safety == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td1, td2, fg, td3, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    int possible_score[] = {8,7,6,3,2};
    
    int score_pos_left = sizeof(possible_score) / sizeof(possible_score[0]);
    int current_combination[10000];


    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);


        if (score == 0 || score == 1) {
            break;
        } 
        else {
            score_combination_report(possible_score, score_pos_left, score, current_combination, 0);
        }
    }
    return 0;
}