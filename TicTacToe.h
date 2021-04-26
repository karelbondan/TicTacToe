struct Node
{
	char x;
	/*
	I changed the node names to ease myself when writing, as I did not need to remember what the 
	abbreviations represent. I also added 'tengah' node or the center node because there was no 
	center node in the starter header file. 
	*/
	Node *ataskiri, *atas, *ataskanan, *tengahkiri, *tengah, *tengahkanan, *bawahkiri, *bawah, *bawahkanan;
};
/*
I made another struct called LinkedList because linking all of the nodes inside the Node struct is impossible,
it is like linking itself inside itself which does not make sense. It will also throw SIGSEGV error if I try 
linking all of the nodes inside the Node struct using the Node *next. This is why I made another struct 
called LinkedList, which as its name suggest, links all of the nodes inside the Node struct. Node *itemdata 
inside LinkedList struct will store the nodes inside the Node struct, and LinkedList *next will store the 
next addresses of the list items. 
*/
struct LinkedList
{
	char value;
    Node *itemdata;
    LinkedList *next;
};

class TicTacToe
{
	private:
		/*
		ataskiri until bawahkanan will be used later in the display(LinkedList *curCursor) 
		method, curPlayer is the current player. 
		*/
		char curPlayer, ataskiri, atas, ataskanan, tengahkiri, tengah, tengahkanan, bawahkiri, bawah, bawahkanan;
		/*
		int filled will be used as the checker when the board has been fully filled. When it 
		becomes true, it will tell the program that no one wins and the game is tie.
		*/
		int filled = false;
		/*
		Node *game below will store each values of all the boards from upper left to lower right,
		then all of the values will be linked together using the LinkedList struct. 
		*/
		Node *game = new Node;
		/*
		as the name suggest, cursor will be used as the pointer to where the player is currently
		at on the board. 
		*/
		LinkedList *cursor = new LinkedList;
		/*
		head will store the first address of the list items, list will store the items, start
		will be used as the iterator for the linked list. 
		*/
		LinkedList *head, *list, *start;
		
	public:
		TicTacToe();
		/*
		this method below is the same as getHead() but I don't know why it will throw a SIGSEGV
		(segmentation fault) error if I access the linked list from another method. So instead 
		I made this method a three-in-one method: make a linked list of the board nodes, setting 
		the cursor, and getting the cursor which will then later be used by the 
		display(LinkedList *curCursor) method. 
		*/
		LinkedList *linkAll_setGetCursor();
		/*
		I changed the method type from Node to LinkedList on display(LinkedList *curCursor)
		method to match the cursor type (LinkedList *cursor), as it will then later be used
		as a passing parameter to this method. 
		*/
		void display(LinkedList *curCursor);
		void move(char direction);
		/*
		I changed the method type from bool to void as it does not need to return anything.
		*/
		void setNode(char player);
		/*
		I removed getWinner() and instead replaced it with getPlayer() and 
		setPlayer(int turn). This is because I used remainders to set the 
		current player. When there is remainder, it will tell the game 
		that it is player P's turn, when there is  no remainder, the game 
		will know that it is player O's turn. The game will use getPlayer() 
		method when one of the players manages to win the game. Therefore 
		getPlayer() and getWinner() will be basically the same as both will
		return the current player.
		*/
		char getPlayer();
		void setPlayer(int turn);
		/*
		as the name suggest, winnerExist() will be used as a checker method when a player
		has win the game. allFilled() will also be used as a checker whether the board
		has all been filled or not. If yes then it will tell the program that the game
		is tie.
		*/
		bool winnerExist();
		bool allFilled();
};
/*
Summary of changes from started header file:
- Added (bool) allFilled() method.
- Added (bool) winnerExist() method. 
- Added (char) ataskiri, atas, ataskanan, tengahkiri, tengah, tengahkanan, bawahkiri, bawah, bawahkanan variables.
- Added (char) getPlayer() and (void) setPlayer() methods.
- Added (int) filled variable.
- Added (LinkedList) linkAll_setGetCursor() method.
- Added (LinkedList) list, start instance variables.
- Added (Node) game variable. 
- Added 'tengah' (center) member to Node struct. 
- Added LinkedList struct.
- Changed 'cursor' variable type from Node to LinkedList. 
- Changed 'head' variable type from Node to LinkedList.
- Changed display() parameter name from curHead to curCursor.
- Changed display() parameter type from Node to LinkedList.
- Changed member names in Node struct from abbrevations to their respective Indonesian names.
- Changed setNode() method type from bool to void.
- Initialized (LinkedList) cursor variable.
- Initialized (Node) game variable.
- Removed (char) getWinner() method.
- Removed (char) winner variable.
- Removed (Node) getHead() method.
- Removed 'next' member from Node struct. */
