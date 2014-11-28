#include "music.h"

void playSong(Song s)
{
	switch (s)
	{
		case STAR:
			play_song(star_hz, star_dur, notes[1]);
			break;
			
		case SORC:
			play_song(sorc_hz, sorc_dur, notes[1]);
			break;
			
		case POKE:
			play_song(poke_hz, poke_dur, notes[2]);
			break;
	}
}

void play_song(unsigned int hz[], unsigned char dur[], unsigned char length)
{
	unsigned char i;
	
	for (i = 0; i < length; ++i)
	{
		play_note(hz[i], dur[i]);
	}
}

void play_note(unsigned int hz, unsigned char dur)
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
		while (TF0 == 0);
		TR0 = 0;
		TF0 = 0;
		SPK = ~SPK;
	}
}
