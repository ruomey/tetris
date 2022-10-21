#include <stdio.h>
#include <stdlib.h>

struct cels {
  int coordX;
  int coordY;
};

void changeCoord(int *coordY, int *coordX);
void graphField(int coordY, int coordX);
void sleep(int time);
int key_press();

int main(){
  struct cels cels;
  cels.coordX = 16;
  cels.coordY = 25;
  graphField(cels.coordY, cels.coordX);
	while (1) {
    changeCoord(&cels.coordY, &cels.coordX);
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
void changeCoord(int *coordY, int *coordX) {
    ++*coordY; // always falling down like dollar
    int keyCode = key_press();
    if (keyCode == -1) {
			--*coordX;
		} else if (keyCode == 1) {
			++*coordX;
		}
}

int key_press() {
	char key = ' ';
	int result = 0;
	key =	getchar();
	if (key == 'a'){
		result = -1;
	} else if (key == 'd') {
		result = 1;
	}
	return result;
}
void sleep(int time) {
  for (long long i = 0; i < (long long)(9 - time) * 100000000; ++i) {
    time = (time + time) / 2;
  }

}
