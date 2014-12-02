#include "project2.h"

//TODO: Actually make these songs
code unsigned int star_hz[42] = {F5, F5, F5, BF5, F6, EF6, D6, C6, BF6, F6, EF6, D6, C6, BF6, F6, EF6, D6, EF6, C6, F5, F5, F5, BF5, F6, EF6, D6, C6, BF6, F6, EF6, D6, C6, BF6, F6, C7, BF6, A6, BF6, BF5, BF5, BF5, BF5};
code unsigned char star_dur[42] = {E3, E3, E3, H, H, E3, E3, E3, H, Q, E3, E3, E3, H, Q, E3, E3, E3, H, E3, E3, E3, H, H, E3, E3, E3, H, Q, E3, E3, E3, H, Q, E3, E3, E3, Q, E3, E3, E3, Q};
code char star_name[9] = "Star Wars";

code unsigned int sorc_hz[57] = {F5, C6, C5, D5, E5, F5, AF5, F5, AF5, G5, F5, E5, F5, AF5, F5, AF5, G5, F5, E5, F5, AF5, F5, AF5, G5, F5, G5, AF5, G5, BF5, AF5, G5, B5, F5, AF5, G5, BF5, AF5, G5, B5, F5, AF5, BF5, C6, C6, C6, C6, D6, E6, F6, E6, F6, G6, C6, D6, E6, F6, F5};
code unsigned char sorc_dur[57] = {DQ, DQ, E, E, E, Q, E, Q, E, E, E, E, Q, E, Q, E, E, E, E, Q, E, E, E, E, E, E, E, E, E, E, Q, E, Q, E, E, E, E, Q, E, E, E, E, E, E, E, E, E, E, E, E, E, DQ, E, E, E, DQ, DQ};
code char sorc_name[21] = "Sorceror's Apprentice";
	
code unsigned int poke_hz[1] = {1000};
code unsigned char poke_dur[1] = {Q};
code char poke_name[7] = "Pokemon";
	
code unsigned char notes[3] = {42, 57, 1};

bool playSong(Song s)
{
	bool x = true;
	switch (s)
	{
		case STAR:
			transmit(star_name, 9);
			x = play_song(star_hz, star_dur, notes[1]);
			break;
			
		case SORC:
			transmit(sorc_name, 21);
			x = play_song(sorc_hz, sorc_dur, notes[1]);
			break;
			
		case POKE:
			transmit(poke_name, 7);
			x = play_song(poke_hz, poke_dur, notes[2]);
			break;
	}
	return x;
}

bool play_song(unsigned int hz[], unsigned char dur[], unsigned char length)
{
	unsigned char i;
	bool x;
	for (i = 0; i < length; ++i)
	{
		x = play_note(hz[i], dur[i]);
		if (x == false)
			return false;
	}
	return true;
}

bool play_note(unsigned int hz, unsigned char dur)
{
	unsigned int i, time;
	unsigned char high, low;
	
	time = hz * dur / 18;
	i = 307125 / hz;
	high = i / 256;
	low = i % 256;
	
	TMOD = TMOD & 0xf0;
	TMOD = TMOD | 0x01;
	
	for (i = 0; i < time; ++i)
	{
		TH0 = high;
		TL0 = low;
		TR0 = 1;
		while (TF0 == 0)
		{
			//TODO: Verify if this button choice works
			if(SW9 == 0)
				return false;
		}
		TR0 = 0;
		TF0 = 0;
		SPK = ~SPK;
	}
	return true;
}
