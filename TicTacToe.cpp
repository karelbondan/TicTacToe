#include <iostream>
#include <cstdlib>
#include "TicTacToe.h"
using namespace std;

TicTacToe::TicTacToe(){
	game->atas = new Node;
	game->ataskanan = new Node;
	game->ataskiri = new Node;
	game->tengahkiri = new Node;
	game->tengah = new Node;
	game->tengahkanan = new Node;
	game->bawahkiri = new Node;
	game->bawah = new Node;
	game->bawahkanan = new Node;
	
	game->ataskiri->x = '-';
	game->atas->x = '-';
	game->ataskanan->x = '-';
	game->tengahkiri->x = '-';
	game->tengah->x = '-';
	game->tengahkanan->x = '-';
	game->bawahkiri->x = '-';
	game->bawah->x = '-';
	game->bawahkanan->x = '-';
	
	curPlayer = 'o';
}

void TicTacToe::display(LinkedList *curCursor){
	if (curCursor->itemdata != game->ataskiri || allFilled() || winnerExist()){ataskiri = game->ataskiri->x;}
	else {ataskiri = ' ';}
	if (curCursor->itemdata != game->atas || allFilled() || winnerExist()){atas = game->atas->x;}
	else {atas = ' ';}
	if (curCursor->itemdata != game->ataskanan || allFilled() || winnerExist()){ataskanan = game->ataskanan->x;}
	else {ataskanan = ' ';}
	if (curCursor->itemdata != game->tengahkiri || allFilled() || winnerExist()){tengahkiri = game->tengahkiri->x;}
	else {tengahkiri = ' ';}
	if (curCursor->itemdata != game->tengah || allFilled() || winnerExist()){tengah = game->tengah->x;}
	else {tengah = ' ';}
	if (curCursor->itemdata != game->tengahkanan || allFilled() || winnerExist()){tengahkanan = game->tengahkanan->x;}
	else {tengahkanan = ' ';}
	if (curCursor->itemdata != game->bawahkiri || allFilled() || winnerExist()){bawahkiri = game->bawahkiri->x;}
	else {bawahkiri = ' ';}
	if (curCursor->itemdata != game->bawah || allFilled() || winnerExist()){bawah = game->bawah->x;}
	else {bawah = ' ';}
	if (curCursor->itemdata != game->bawahkanan || allFilled() || winnerExist()){bawahkanan = game->bawahkanan->x;}
	else {bawahkanan = ' ';}
	cout << "\n\n\tWelcome to the TicTacToe game!\n\t  The current player is = " << getPlayer() << endl;
	cout << "\n\t\t" << ataskiri << "     " << atas << "     " << ataskanan << endl;
	cout << "\n\t\t" << tengahkiri << "     " << tengah << "     " << tengahkanan << endl;
	cout << "\n\t\t" << bawahkiri << "     " << bawah << "     " << bawahkanan << endl;
}

LinkedList *TicTacToe::linkAll_setGetCursor(){
	head = new LinkedList;
	list = head;
	start = head;
	
	for (int i = 1; i <= 9; i++){
		if (i == 1){
			list->next = new LinkedList;
			list->itemdata = game->ataskiri;
			list->value = game->ataskiri->x;
			list = list->next;
		}
		if (i == 2){
			list->next = new LinkedList;
			list->itemdata = game->atas;
			list->value = game->atas->x;
			list = list->next;
		}
		if (i == 3){
			list->next = new LinkedList;
			list->itemdata = game->ataskanan;
			list->value = game->ataskanan->x;
			list = list->next;
		}
		if (i == 4){
			list->next = new LinkedList;
			list->itemdata = game->tengahkiri;
			list->value = game->tengahkiri->x;
			list = list->next;
		}
		if (i == 5){
			list->next = new LinkedList;
			list->itemdata = game->tengah;
			list->value = game->tengah->x;
			list = list->next;
		}
		if (i == 6){
			list->next = new LinkedList;
			list->itemdata = game->tengahkanan;
			list->value = game->tengahkanan->x;
			list = list->next;
		}
		if (i == 7){
			list->next = new LinkedList;
			list->itemdata = game->bawahkiri;
			list->value = game->bawahkiri->x;
			list = list->next;
		}
		if (i == 8){
			list->next = new LinkedList;
			list->itemdata = game->bawah;
			list->value = game->bawah->x;
			list = list->next;
		}
		if (i == 9){
			list->next = NULL;
			list->itemdata = game->bawahkanan;
			list->value = game->bawahkanan->x;
			list = list->next;
		}
	}
	
	for (int i = 1; i <= 9; i++){
		// cout << start->itemdata << endl; 	// for debugging purposes
		// cout << start->value << endl; 	// for debugging purposes
		if (start->value == '-'){
			cursor->itemdata = start->itemdata;
			break;
		}
		start = start->next;
		if (i == 9){
			filled = true;
			break;
		}
	}
	return cursor;
}

void TicTacToe::move(char direction){
	if (direction == 'Q' || direction == 'q'){
		if (game->ataskiri->x == '-')
			cursor->itemdata = game->ataskiri;
	}
	else if (direction == 'W' || direction == 'w'){
		if (game->atas->x == '-')
			cursor->itemdata = game->atas;
	}
	else if (direction == 'E' || direction == 'e'){
		if (game->ataskanan->x == '-')
			cursor->itemdata = game->ataskanan;
	}
	else if (direction == 'A' || direction == 'a'){
		if (game->tengahkiri->x == '-')
			cursor->itemdata = game->tengahkiri;
	}
	else if (direction == 'S' || direction == 's'){
		if (game->tengah->x == '-')
			cursor->itemdata = game->tengah;
	}
	else if (direction == 'D' || direction == 'd'){
		if (game->tengahkanan->x == '-')
			cursor->itemdata = game->tengahkanan;
	}
	else if (direction == 'Z' || direction == 'z'){
		if (game->bawahkiri->x == '-')
			cursor->itemdata = game->bawahkiri;
	}
	else if (direction == 'X' || direction == 'x'){
		if (game->bawah->x == '-')
			cursor->itemdata = game->bawah;
	}
	else if (direction == 'C' || direction == 'c'){
		if (game->bawahkanan->x == '-')
			cursor->itemdata = game->bawahkanan;
	}
}

void TicTacToe::setNode(char player){
    if (cursor->itemdata == game->ataskiri)
    	if (game->ataskiri->x == '-')
        	game->ataskiri->x = player;
    if (cursor->itemdata == game->atas)
    	if (game->atas->x == '-')
        	game->atas->x = player;
    if (cursor->itemdata == game->ataskanan)
    	if (game->ataskanan->x == '-')
        	game->ataskanan->x = player;
    if (cursor->itemdata == game->tengahkiri)
    	if (game->tengahkiri->x == '-')
        	game->tengahkiri->x = player;
    if (cursor->itemdata == game->tengah)
    	if (game->tengah->x == '-')
       		game->tengah->x = player;
    if (cursor->itemdata == game->tengahkanan)
    	if (game->tengahkanan->x == '-')
        	game->tengahkanan->x = player;
    if (cursor->itemdata == game->bawahkiri)
    	if (game->bawahkiri->x == '-')
        	game->bawahkiri->x = player;
    if (cursor->itemdata == game->bawah)
    	if (game->bawah->x == '-')
        	game->bawah->x = player;
    if (cursor->itemdata == game->bawahkanan)
    	if (game->bawahkanan->x == '-')
        	game->bawahkanan->x = player;
}

bool TicTacToe::winnerExist(){
	if (game->ataskanan->x == game->atas->x && game->atas->x == game->ataskiri->x && game->atas->x != '-')
		return true;
	else if (game->tengahkiri->x == game->tengah->x && game->tengah->x == game->tengahkanan->x && game->tengah->x != '-')
		return true;
	else if (game->bawahkiri->x == game->bawah->x && game->bawah->x == game->bawahkanan->x && game->bawah->x != '-')
		return true;
	else if (game->ataskiri->x == game->tengahkiri->x && game->tengahkiri->x == game->bawahkiri->x && game->tengahkiri->x != '-')
		return true;
	else if (game->atas->x == game->tengah->x && game->tengah->x == game->bawah->x && game->tengah->x != '-')
		return true;
	else if (game->ataskanan->x == game->tengahkanan->x && game->tengahkanan->x == game->bawahkanan->x && game->tengahkanan->x != '-')
		return true;
	else if (game->ataskanan->x == game->tengah->x && game->tengah->x == game->bawahkiri->x && game->tengah->x != '-')
		return true;
	else if (game->ataskiri->x == game->tengah->x && game->tengah->x == game->bawahkanan->x && game->tengah->x != '-')
		return true;
	return false;
}

bool TicTacToe::allFilled(){
	if (filled == true)
		return true;
	return false;
}

char TicTacToe::getPlayer(){
	return curPlayer;
}

void TicTacToe::setPlayer(int turn){
	if (turn%2 != 0){curPlayer = 'o';}
	else {curPlayer = 'p';}
}

