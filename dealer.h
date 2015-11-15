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


/*a dealer has a hand and hno is used to index cards in his hand*/
typedef struct dealer {
	card *hand;
	int hno;
}dealer;
/*initialises the dealer's hand and hno*/
void initdealer(dealer *d);
/*a dealer hits till he reaches a total of 17*/
void dhit(dealer *d, shoe *s, GtkGrid *grid);
/*displays the hole card and dealer's other card right after the deal*/
void dealdisplay(dealer *d, GtkGrid *grid);
/*calculates and returns the dealer's sum*/
int dsum(dealer *d);
