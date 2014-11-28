#ifndef MUSIC_H
#define MUSIC_H

#include <reg932.h>
#include "project2.h"

#define Q 12
#define E 6
#define S 3
#define E3 4
#define S3 2

typedef enum {STAR, SORC, POKE} Song;

//TODO: Actually make these songs
code unsigned int star_hz[1] = {1000};
code unsigned char star_dur[1] = {Q};
	
code unsigned int sorc_hz[1] = {1000};
code unsigned char sorc_dur[1] = {Q};

code unsigned int poke_hz[1] = {1000};
code unsigned char poke_dur[1] = {Q};
	
code unsigned char notes[3] = {1, 1, 1};

void playSong(Song s);

void play_song(unsigned int hz[], unsigned char dur[], unsigned char notes);

void play_note(unsigned int hz, unsigned char dur);

#endif
