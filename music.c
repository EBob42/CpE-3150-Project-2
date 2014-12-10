#include "project2.h"

/**********************************************************
	* Star Wars theme arrays
**********************************************************/
code unsigned int star_hz[42] = {F5, F5, F5, BF5, F6, EF6, D6, C6, BF6, F6, EF6, D6, C6, BF6, F6, EF6, D6, EF6, C6, F5, F5, F5, BF5, F6, EF6, D6, C6, BF6, F6, EF6, D6, C6, BF6, F6, C7, BF6, A6, BF6, BF5, BF5, BF5, BF5};
code unsigned char star_dur[42] = {E3, E3, E3, H, H, E3, E3, E3, H, Q, E3, E3, E3, H, Q, E3, E3, E3, H, E3, E3, E3, H, H, E3, E3, E3, H, Q, E3, E3, E3, H, Q, E3, E3, E3, Q, E3, E3, E3, Q};
code unsigned char star_name[9] = "Star Wars";

/**********************************************************
	* Sorceror's Apprentice theme arrays
**********************************************************/
code unsigned int sorc_hz[57] = {F5, C6, C5, D5, E5, F5, AF5, F5, AF5, G5, F5, E5, F5, AF5, F5, AF5, G5, F5, E5, F5, AF5, F5, AF5, G5, F5, G5, AF5, G5, BF5, AF5, G5, B5, F5, AF5, G5, BF5, AF5, G5, B5, F5, AF5, BF5, C6, C6, C6, C6, D6, E6, F6, E6, F6, G6, C6, D6, E6, F6, F5};
code unsigned char sorc_dur[57] = {DQ, DQ, E, E, E, Q, E, Q, E, E, E, E, Q, E, Q, E, E, E, E, Q, E, E, E, E, E, E, E, E, E, E, Q, E, Q, E, E, E, E, Q, E, E, E, E, E, E, E, E, E, E, E, E, E, DQ, E, E, E, DQ, DQ};
code unsigned char sorc_name[21] = "Sorceror's Apprentice";

/**********************************************************
	* Length of songs
**********************************************************/
code unsigned char notes[2] = {42, 57};

/**********************************************************
	* playSong
	*	@desc		Plays the selected song
	*
	*	@param1	The song to be played
**********************************************************/
bool playSong(Song s)
{
	bool x = true;
	switch (s)
	{
		case STAR:
			transmit(star_name, 9);
			x = play_song(star_hz, star_dur, notes[0]);
			break;
			
		case SORC:
			transmit(sorc_name, 21);
			x = play_song(sorc_hz, sorc_dur, notes[1]);
			break;
	}
	return x;
}

/**********************************************************
	* play_song
	*	@desc		Plays the song corresponding to the arrays given
	*
	*	@param1	Array of frequencies
	*	@param2	Array of note durations
	*	@param3 Number of notes in the song
**********************************************************/
bool play_song(unsigned int hz[], unsigned char dur[], unsigned char length)
{
	unsigned char i;
	bool x;
	
	IEN0 |= 0x88;
	TMOD = 0x10;
	TH1 = 0x00;
	TL1 = 0x00;
	TR1 = 1;
	
	for (i = 0; i < length; ++i)
	{
		play_small_delay();
		x = play_note(hz[i], dur[i]);
		if (x == false)
		{
			IEN0 &= ~0x08;
			TR1 = 0;
			clearLED();
			return false;
		}
	}
	
	TR1 = 0;
	IEN0 &= ~0x08;
	clearLED();
	return true;
}

/**********************************************************
	* play_note
	*	@desc		Plays a note at the given frequency
	*					with the given duration.
	*					Also has a pseudo-interrupt (with polling)
	*					for switching modes during the note
	*
	*	@param1	Frequency of the note
	*	@param2	Duration of the note in 18ths of
	*					a second
**********************************************************/
bool play_note(unsigned int hz, unsigned char dur)
{
	unsigned int i, time;
	unsigned char high, low;
	
	time = hz * dur / 18;
	i = 0xFFFF - 61425 / hz*30 + 1;
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
			if(SW9 == 0)
				return false;
		}
		TR0 = 0;
		TF0 = 0;
		SPK = ~SPK;
	}
	return true;
}

/**********************************************************
	* play_small_delay
	*	@desc		Very short delay function
	*					to distinguish between notes
	*					of the song, especially
	*					repeated notes of the same
	*					frequency
**********************************************************/
void play_small_delay()
{
	TMOD = TMOD & 0xf0;
	TMOD = TMOD | 0x01;
	TH0 = 0x00;
	TL0 = 0x00;
	TR0 = 1;
	while(TF0 == 0);
	TR0 = 0;
	TF0 = 0;
}