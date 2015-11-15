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
void bet(int amt, player *p, GtkLabel *bamt, GtkLabel *mamt);/*takes amt as bet amount and changes player's money and bet, it also displays the bet amount and money*/
void cb_b50(GtkWidget *widget, gpointer data);/*all these fuctions are callbacks and call bet function by passing different values to bet function*/
void cb_b100(GtkWidget *widget, gpointer data);
void cb_b500(GtkWidget *widget, gpointer data);
