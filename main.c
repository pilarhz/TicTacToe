#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

//     y  x
char t[3][3] = { ' ',' ',' ',
				 ' ',' ',' ',
				 ' ',' ',' ' };

// random numer and game loop
int r, l;
// move 
char m;

void show_table() {
	int z = 1;
	for (int y = 0; y < 4;) {
		printf("\n");
		if (z == 2) {
			for (int x = 0; x < 3; x++) {
				printf("| %c |", t[y][x]);
			}
			y++;
			z = 1;
		}
		else if (z == 1) {
			printf("#");
			for (int i = 1; i < 14; i++) {
				printf("-");
			}
			printf("#");
			if (y == 3) { break; };
			z = 2;
		}
	}
};

void move() {
	if (r == 1) { m = 'x'; r = 2; }
	else if (r == 2) { m = 'y'; r = 1; }
	int x = 0, y = 0, f = 0;
	printf("\nChoose place between 1 and 9 to put %c - ", m);
	while (1) {
		scanf_s("%d", &f);
		switch (f) {
		case 1: x = 0; y = 0; break;
		case 2: x = 1; y = 0; break;
		case 3: x = 2; y = 0; break;
		case 4: x = 0; y = 1; break;
		case 5: x = 1; y = 1; break;
		case 6: x = 2; y = 1; break;
		case 7: x = 0; y = 2; break;
		case 8: x = 1; y = 2; break;
		case 9: x = 2; y = 2; break;
		default: break;
		};
		if (t[y][x] == ' ') {
			t[y][x] = m;
			break;
		}
		else {
			printf("Wrong field choose again - ");
		}
	}
};

void check_win() {
	if (t[0][0] == m && t[0][1] == m && t[0][2] == m) { l = 0; }
	else if (t[1][0] == m && t[1][1] == m && t[1][2] == m) { l = 0; }
	else if (t[2][0] == m && t[2][1] == m && t[2][2] == m) { l = 0; }

	else if (t[0][0] == m && t[1][0] == m && t[2][0] == m) { l = 0; }
	else if (t[0][1] == m && t[1][1] == m && t[2][1] == m) { l = 0; }
	else if (t[0][2] == m && t[1][2] == m && t[2][2] == m) { l = 0; }

	else if (t[0][0] == m && t[1][1] == m && t[2][2] == m) { l = 0; }
	else if (t[0][2] == m && t[1][1] == m && t[2][0] == m) { l = 0; }

	else { printf("error"); };
};

int main() { 
	srand(time(NULL));
	r = rand() % 2 + 1;

	l = 1;

	while (l) {
		system("cls");
		show_table();
		move();
		check_win();
	}

	system("cls");
	show_table();
	printf("\n\nKoniec gry!!!\nWygrywa gracz %c\n", m);
	system("pause");
}