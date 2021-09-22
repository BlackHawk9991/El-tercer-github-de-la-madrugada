#include <conio.h>
#include "Controlador.h"

int main() {
	srand(time(NULL));
	Console::BackgroundColor = ConsoleColor::Black;
	Console::SetWindowSize(160, 35);
	Console::CursorVisible = false;
	char tecla;

	Controlador* c = new Controlador();
	Console::SetCursorPosition(153, 5); cout << c->getZ();
	Console::SetCursorPosition(153, 7); cout << c->getL();
	while (true) {
		c->borrarTodo();

		c->Colision_Alien_Enemigo();
		if (_kbhit()) {
			tecla = _getch();
			tecla = toupper(tecla);
			c->getAlien()->mover(tecla);
		}
		c->moverTodo();
		c->dibujarTodo();

		_sleep(100);
	}

	_getch();
	return 0;
}
