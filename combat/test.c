#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include "crit_extras.h"
#define KILL_COLOR     "\x1b[31m"
#define CRIT_COLOR     "\x1b[33m"
#define COLOR_RESET   "\x1b[0m"

int nmn;
char crit[2]; // Increase size to accommodate 'y' or 'n'
int dmg;
int starthp;
int hp;
int critnum;

int frngHit() {
    int high = 12;
    int low = 0;
    nmn = low + rand() % (high - low + 1);
    return nmn;
}

int sRngCall() {
    int high = 19;
    int low = 0;
    critnum = low + rand() % (high - low + 1);
    return critnum;
}



int main() {
    srand(time(0));
    
    printf("Enter HP: ");
    scanf("%d", &starthp);
    getchar(); // Consume newline character left in input buffer
    hp = starthp;
    while (hp > 0) {
        printf("Was Enemy crit? (y or n): ");
        scanf("%1[^\n]%*c", crit); // Read only one character
            
        if (crit[0] == 'y') {
          sRngCall();
        }


        printf("How much damage? ");
        scanf("%d%*c", &dmg); // Consume newline character left in input buffer
        
        frngHit();
        printf("\n");  

        if (nmn == 0) {
            printf("Head");
        } 
            else if (nmn == 1) {
            printf("R. Arm");
        } 
            else if (nmn == 2) {
            printf("L. Arm");
        } 
            else if (nmn >= 3 && nmn <= 6) {
            printf("Chest");
        } 
            else if (nmn == 7) {
            printf("R. Leg");
        } 
            else if (nmn == 8) {
            printf("L. Leg");
        } 
          else if (nmn == 9) {
            printf("L. Hand");
        }
         else if (nmn == 10) {
            printf("R. Hand");
        }
        else if (nmn == 11) {
            printf("L. Shoulder");
        }
        else if (nmn == 12) {
            printf("R. Shoulder");
        }
         else {
            printf("Groin");
        }

        
        
        if (crit[0] == 'y') {
            printf(CRIT_COLOR " Crit!" COLOR_RESET);
            if(critnum == 19){
            printf(CRIT_COLOR " Effect!" COLOR_RESET);
            }
        printf("\n");
        } 
        else {
            printf(".\n");
      }

        hp = hp - dmg;
        
        if (hp < 0){
        hp = 0;
        }  

        printf("%d/%d HP.\n",hp,starthp);
        
  }
    
    printf(KILL_COLOR "Enemy was killed.\n"); 
    return 0;
}

