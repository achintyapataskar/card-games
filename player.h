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

/*this sturcture has a hand array for playing the game all new cards are added to this array
* hno stores number of cards in the hand array, money is the current money with the player and
*bet is the amount of bet to be played in asingle hand*/
typedef struct player {
	card *hand;
	card *aux;
	int hno, ano;
	double money, bet;
}player;
/*all these functions perform various tasks when called by different callback functions in playercb.c*/
void deal(player *p, dealer *d, shoe *s, GtkGrid *grid1, GtkGrid *grid2);
void display(player *p, GtkGrid *grid);
void initplayer(player *p);
void hit(shoe *s, player *p);
void stand(shoe *s, dealer *d, GtkGrid *grid);
void doubledown(shoe *s, player *p, GtkLabel *bamt, GtkLabel *mamt, GtkGrid *grid);
void surrender(player *p, GtkLabel *bamt, GtkLabel *mamt);
void split(player *p, GtkGrid *grid2);
int playersum(player *p);
double money(int state);
void dealdispplayer(player *p, GtkGrid *grid);
void result(player *p, dealer *d, GtkLabel *result, GtkLabel *bamt, GtkLabel *mamt);
int split_sum(player *p);
