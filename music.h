#ifndef MUSIC_H
#define MUSIC_H

#include <reg932.h>
#include "project2.h"

// Durations
#define H 24
#define DQ 18
#define Q 12
#define E 6
#define S 3
#define E3 4
#define S3 2

// Frequencies
#define F5 698
#define BF5 932
#define F6 1397
#define EF6 1245
#define D6 1175
#define C6 1047
#define BF6 1865
#define C7 2093
#define A6 1760

#define C5 523
#define D5 587
#define E5 659
#define AF5 880
#define G5 784
#define B5 988
#define E6 1318
#define G6 1568



typedef enum {STAR, SORC, POKE} Song;

//TODO: Actually make these songs
code unsigned int star_hz[42] = {F5, F5, F5, BF5, F6, EF6, D6, C6, BF6, F6, EF6, D6, C6, BF6, F6, EF6, D6, EF6, C6, F5, F5, F5, BF5, F6, EF6, D6, C6, BF6, F6, EF6, D6, C6, BF6, F6, C7, BF6, A6, BF6, BF5, BF5, BF5, BF5};
code unsigned char star_dur[42] = {E3, E3, E3, H, H, E3, E3, E3, H, Q, E3, E3, E3, H, Q, E3, E3, E3, H, E3, E3, E3, H, H, E3, E3, E3, H, Q, E3, E3, E3, H, Q, E3, E3, E3, Q, E3, E3, E3, Q};
	
code unsigned int sorc_hz[57] = {F5, C6, C5, D5, E5, F5, AF5, F5, AF5, G5, F5, E5, F5, AF5, F5, AF5, G5, F5, E5, F5, AF5, F5, AF5, G5, F5, G5, AF5, G5, BF5, AF5, G5, B5, F5, AF5, G5, BF5, AF5, G5, B5, F5, AF5, BF5, C6, C6, C6, C6, D6, E6, F6, E6, F6, G6, C6, D6, E6, F6, F5};
code unsigned char sorc_dur[57] = {DQ, DQ, E, E, E, Q, E, Q, E, E, E, E, Q, E, Q, E, E, E, E, Q, E, E, E, E, E, E, E, E, E, E, Q, E, Q, E, E, E, E, Q, E, E, E, E, E, E, E, E, E, E, E, E, E, DQ, E, E, E, DQ, DQ};

code unsigned int poke_hz[1] = {1000};
code unsigned char poke_dur[1] = {Q};
	
code unsigned char notes[3] = {42, 57, 1};

void playSong(Song s);

void play_song(unsigned int hz[], unsigned char dur[], unsigned char notes);

void play_note(unsigned int hz, unsigned char dur);

#endif
