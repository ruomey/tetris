#include <stdio.h>
#include <stdlib.h>

struct cels {
  int coordX;
  int coordY;
  int key; // it isnt cel actually srry
};

void changeCoord(int *coordY, int *coordX, int *key);
void graphField(int coordY, int coordX);
void sleep(int time);
void key_press(int *key);

int main(){
  struct cels cels;
  cels.coordX = 16;
  cels.coordY = 25;
  cels.key = 0;
  graphField(cels.coordY, cels.coordX);
  while (1) {
    changeCoord(&cels.coordY, &cels.coordX, &cels.key);
    graphField(cels.coordY, cels.coordX);
    sleep(1);

  }
  return 0;
}

void graphField(int coordY, int coordX){
  for(int i = 0; i < 45 ; i++){
    if (i >= 15 && i < 40) {
      printf("_");
    } else {
      printf(" ");
    }
  }
  printf("\n");
  for (int i = 0 ; i < 40; i++){
    for (int j = 0; j < 45; j++){
      if (j == 15 || j == 39) {
        printf("|");
      } else if (j == 44) {
        printf(" \n");
      } else if(j == coordX && i == coordY ){
        printf("o");
      } else {
        printf(" ");
      }
    }
  }
  for(int i = 0; i < 45 ; i++){
    if (i >= 15 && i < 40) {
      printf("_");
    } else {
      printf(" ");
    }
  }
  printf("\n");

}
void changeCoord(int *coordY, int *coordX, int *key) {
    ++*coordY; // always falling down like dollar
    key_press(*key);
    if (*key > 0) { // checking key pressed & conditions satisfied
        if (*key == 1) { // equals going left
            --*coordX;
        }
        else if (*key == 2) { // and going right 
            ++*coordX;
        }
        else {
            printf("it cannot..");
        }
    }
}

void key_press(int *key) {
    if (key != NULL) {
        char k[1];
        int kcode;
        // *key: 0 - nothing, 1 - left(a), 2 - right(d)
        scanf_s("%c", &k);
        kcode = k[0] - '0'; // calculating value of symbol

        if (kcode == 49) {
            *key = 1;
        }
        else if (kcode == 52) {
            *key = 2;
        }
        else {
            *key = 0;
        }
    }
}

void sleep(int time) {
  for (long long i = 0; i < (long long)(9 - time) * 100000000; ++i) {
    time = (time + time) / 2;
  }
}
