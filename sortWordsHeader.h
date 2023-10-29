/**
 * sortWordsHeader.h - Header code file for the header functions for sortWords.c
 *
 * @author:     Jeff Dinsmore (jdinsmor@pdx.edu)
 * @date:       26-Oct-2023
 * @version:    1.0
 *
 * The header definitions outline and define the parameters of the sortWords.c and
 * sortWordsHelper.c files
 *
 */

#ifndef _sortWordsHeader_h
#define _sortWordsHeader_h

#define WORD_LEN 20		//max length of a single word
#define MAX_WORDS 50 	//max words a user can input into the terminal

int getaline(char s[],int lim);
int compare_strings(const void *p, const void *q);

#endif