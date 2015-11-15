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
#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "cards.h"
#include "shoe.h"
void initshoe(shoe *s, int dno) {
	s->arr = (deck *)malloc(sizeof(deck) * dno);
	int i = 0;
	while(i < dno) {
		initdeck(&(s->arr[i]));
		i++;
	}
	s->dno = dno;
	s->deckno = 0;	
}
void shoeshuffle(shoe *s) {
	int i, x, y;
	i = 0;
	while(i < s->dno) {
		shuffle(&(s->arr[i]));
		i++;
	}
}
card drawscard(shoe *s) {
	card x;
	if(s->arr[s->deckno].index == 52)
		s->deckno++;
	x = drawcard(&(s->arr[s->deckno]));
	return x;
}
