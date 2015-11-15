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

/*this data structure is used to point to all the important game characters and to point to elements of the GUI
* window is the pointer to game window
* grid1 is wher dealer cards are diplayed, grid2 is where player cards are displayed, grid4 holds buttons and result
* bamt is label of bet amt, mamt is label of money amount, result is the label where result is displayed
* the GtkButton pointers point to various buttons in GUI*/
typedef struct config {
	player *p;
	dealer *d;
	shoe *s;
	GtkWindow *window;
	GtkGrid *grid1, *grid2, *grid4;
	GtkLabel *bamt, *mamt, *result;
	GtkButton *deal, *hit, *stand , *doubledown, *split, *surrender, *tut, *next;
	GtkButton *b50, *b100, *b500;
}config;
/*this function configures all buttons that are to be used*/
void configure(GtkBuilder *builder, config *c, player *p, dealer *d, shoe *s);
