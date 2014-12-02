#ifndef MUSIC_H
#define MUSIC_H

// Durations
#define H 24
#define DQ 18
#define Q 12
#define E 6
#define S 3
#define E3 4
#define S3 2

// Frequencies
#define C5 523
#define D5 587
#define E5 659
#define F5 698
#define G5 784
#define AF5 880
#define BF5 932
#define B5 988
#define C6 1047
#define D6 1175
#define E6 1318
#define EF6 1245
#define F6 1397
#define G6 1568
#define A6 1760
#define BF6 1865
#define C7 2093


typedef enum {STAR, SORC, POKE} Song;

typedef enum {false, true} bool;

bool playSong(Song s);

bool play_song(unsigned int hz[], unsigned char dur[], unsigned char notes);

bool play_note(unsigned int hz, unsigned char dur);

void play_small_delay();

#endif
