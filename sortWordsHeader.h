/**
 * sortWordsHeader.h - Header code file for the header functions for scrabble.c
 *
 * @author:     Jeff Dinsmore (jdinsmor@pdx.edu)
 * @date:       26-Oct-2023
 * @version:    1.0
 *
 * The header definitions outline and define the parameters of the scrabble.c and
 * scrabbleHelper.c files
 *
 */

#ifndef _sortWordsHeader_h
#define _sortWordsHeader_h

#define WORD_LEN 20
#define MAX_WORDS 50 //word size set at 45 because that is the longest word in the world

int getaline(char s[],int lim);

#endif