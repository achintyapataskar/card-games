/*the game of Blackjack.This is my miniproject for 2015
*    Copyright (C) 2015  Achintya Pataskar
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.*/
typedef struct card {
	int rank;/*stores rank as 1 for ace upto 13 for king*/
	char suite;/*stores suite as c for club, d for diamond etc...*/
	GtkWidget *image;/*accesses the file and stores an image representing the card*/
}card;
typedef struct deck {
	/*a deck is an array of cards and index tells which cards is being drawn*/
	card arr[52];
	int index;
}deck;
/*these are general purpose card functions that can be used in any cards game*/
void initdeck(deck *d);/*initialises a deck and gets images for cards from file*/
void shuffle(deck *d);/*uses library functions to shuffle the deck*/
card drawcard(deck *d);/*draws cards sequentially*/
void dispcard(GtkWidget *window, GtkGrid *grid, int x, int y, card c);/*can display a card's image on any GtkWindow if it's parameters are known*/
