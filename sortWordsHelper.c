/**
 * sortWordshelper.c - Source code file for the helper functions for sortWords.c
 *
 * @author:     Jeff Dinsmore (jdinsmor@pdx.edu)
 * @date:       26-Oct-2023
 * @version:    1.0
 *
 * The getaline() is based on longestLine.c (as implemented by profroyk),
 * written by Roy Kravitz and from K & R Chapter 1
 *
 * compare_strings() - compares to strings also written by Roy Kravitz.  Used by qsort()
 *
 *
 */
 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortWordsHeader.h"
 
 int getaline(char s[],int lim){ 
    int c, i;
    
    // read the input line and store in s until we get a new line or
    // exceed the maximum number of characters to read
	for (i = 0; i < lim && (c = getchar())!=EOF && c!='\n'; ++i){
        s[i] = c; 
    
    // append '\0' to terminate the string.  Include '\n' in the string
		if (c == '\n') { 
			s[i] = c; 
			++i; 
		} 
	}
    s[i] = '\0';
    return i; 
 }

int compare_strings(const void *p, const void *q){
	return strcmp(*(char **)p, *(char **)q);
}