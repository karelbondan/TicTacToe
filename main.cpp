#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include "TicTacToe.h"
using namespace std;

int main(){
	int turn = 1;
	TicTacToe tictactoe;
	
	while (true){
		char key_press;
		LinkedList *cursor;
		cursor = tictactoe.linkAll_setGetCursor();
		
		do {
			system("cls");
			tictactoe.display(cursor);
			key_press = getch();
			if (key_press == tictactoe.getPlayer())
			{
				tictactoe.setNode(key_press);
				tictactoe.linkAll_setGetCursor();
				turn++;
				break;
			}
			else 
			{
				tictactoe.move(key_press);
				
			}
		} while (key_press != tictactoe.getPlayer());
		
		system("cls");
		tictactoe.display(cursor);
		
		if (tictactoe.winnerExist()){
			cout << "\n\t\t   FINISHED!\n\t       The winner is = " << tictactoe.getPlayer() << endl;
			return 0;
		}
		if (tictactoe.allFilled()){
			cout << "\n\t\t   FINISHED!\n\t\t     TIE!" << endl;
			return 0;
		}
		tictactoe.setPlayer(turn);
	}
}

