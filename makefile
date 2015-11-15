project: bet.c cards.c config.c dealer.c player.c playercb.c shoe.c test.c tut.c
	gcc `pkg-config --cflags gtk+-3.0` -o project bet.c cards.c config.c dealer.c player.c playercb.c shoe.c test.c tut.c `pkg-config --libs gtk+-3.0`

