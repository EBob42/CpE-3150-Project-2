/*****************************************************
	*	music.h
	*
	*	Header with preprocessor variable declarations
	* and function declarations for the music
	* functionality for project 2
	*
	*	Eric Hopkins, Dillion Klobe, Brandon Becker
	***************************************************/

#ifndef MUSIC_H
#define MUSIC_H

/**********************************************************
	* Duration Declarations (Note durations, assuming
	*	quarter note is 90 beats per minute, in terms
	*	of 18ths of a second
**********************************************************/
#define H 24
#define DQ 18
#define Q 12
#define E 6
#define S 3
#define E3 4
#define S3 2

/**********************************************************
	* Note Frequency declarations
**********************************************************/
#define C5 523
#define D5 587
#define E5 659
#define F5 698
#define G5 784
#define AF5 830
#define BF5 932
#define B5 988
#define C6 1047
#define D6 1175
#define EF6 1245
#define E6 1318
#define F6 1397
#define G6 1568
#define A6 1760
#define BF6 1865
#define B6 1979
#define C7 2093
#define E7 2637

/**********************************************************
	*	Allow for switch cases for which song to play
**********************************************************/
typedef enum {STAR, SORC} Song;

/**********************************************************
	*	Define the bool type for ease of use
**********************************************************/
typedef enum {false, true} bool;

/**********************************************************
	* playSong
	*	@desc		Plays the selected song
	*
	*	@param1	The song to be played
**********************************************************/
bool playSong(Song s);

/**********************************************************
	* play_song
	*	@desc		Plays the song corresponding to the arrays given
	*
	*	@param1	Array of frequencies
	*	@param2	Array of note durations
	*	@param3 Number of notes in the song
**********************************************************/
bool play_song(unsigned int hz[], unsigned char dur[], unsigned char notes);

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
bool play_note(unsigned int hz, unsigned char dur);

/**********************************************************
	* play_small_delay
	*	@desc		Very short delay function
	*					to distinguish between notes
	*					of the song, especially
	*					repeated notes of the same
	*					frequency
**********************************************************/
void play_small_delay();

#endif
