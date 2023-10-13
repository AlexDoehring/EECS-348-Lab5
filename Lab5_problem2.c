
#include <stdio.h>
#include <string.h>

void printScores(int score) {
    int td, td1, td2, fg, sfty;
    for(td2 = 0; td2 <= score / 8; td2++) {
        for(td1 = 0; td1 <= score / 7; td1++) {
            for(td = 0; td <= score / 6; td++) {
                for(fg = 0; fg <= score / 3;fg++) {
                    for(sfty = 0; sfty <= score / 2; sfty++) {
                        if(td2*8 + td1*7 + td*6 + fg*3 + sfty*2 == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %dpt FG, %d Safety", td2, td1, td, fg, sfty);
                            printf("\n");
                        }
                    }
                }
            }
        }
    }

}

int main() {

    int num;
    do {
    printf("Enter an integer: ");
    scanf("%d", &num);
    printScores(num);
    } while(num >= 1);



    return 0;
}