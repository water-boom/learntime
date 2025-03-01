#include "snake.h"

int main() {
	srand((unsigned)time(0));
	int end = 1, result;
	Openhistory();
	while (end) {
		result = Menu();
		switch (result) {
		case 1:
			InitMap();
			while (MoveSnake());
			break;
		case 2:
			Help();
			break;
		case 3:
			About();
			break;
		case 4:
				Rink();
			break;
		default:
			end = 0;
			Savehistory();
			break;
		}
	}
	return 0;
}
