/**
 * STARTER CODE
 *
 * sort_words.c() - sorts a list of words
 *
 * @author     Jeff Dinsmore (jdinsmor@pdx)
 * @date       10/26/2023
 *
 *  Uses malloc() and free() to allocate space for the words.  Words are stored
 *  in an array of pointers to the character strings containing the words.  Does
 *  the sort using the C library qsort() function.  Compare function is provided
 *  in the starter code.
 *
 *  Original problem from C Programming: A Modern Approach:2e by K.N. King.  Modified
 *  by Roy Kravitz.
 *
 *  NOTE:  Some of the code listed is starter code written by Roy Kravitz. Specfically the while
 * 	loop, qsort(), and the if/else and printf of the buf/getcwd
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "sortWordsHeader.h"

/***** main() *****/
int main(void){
	char word[WORD_LEN];		// word[] array with a max length WORD_LEN
	char *words[MAX_WORDS];     // array of pointers to strings containing words
    int num_words = 0; 			// number of words in the words[]
	int len;					// length of the input word

    printf("Hello, I would like to help you sort names in alphabetcal order. jdinsmor@pdx.edu\n");
    errno = 0;
    char *buf = getcwd(NULL, 0);    // allocates a buffer large enough to hold the path
    if (buf == NULL) {				// if buffer is empty or null, an error message is displayed
        perror("getcwd");
        printf("Could not display the path\n");
    } else {						// prints current working directory
        printf("Current working directory: %s\n", buf);
        free(buf);					// frees the buffer when finished
    }
    printf("\nPlease enter a word: ");
	while ((len = getaline(word, WORD_LEN)) > 1){	//receives an input word by using getaline()
		if (strcmp (word, "\n") == 0){
			break;					//breaks the while loop when a user presses return or enter
		}
		if(strlen(word) > len){		// exit if an input word is longer than 
			printf("Oops, looks like your entered a word that is too long.\nPlease try again.");
			exit(0);
		}
		if(num_words >= MAX_WORDS){		//break if user inputs more words than MAX_WORDS
			printf("You have reached the maximum number of words.\n");
			break;
		}
		if(strlen(word) <= WORD_LEN){
			words[num_words] = (char*) malloc(strlen(word)+1);  //create memory space for new input word
			if(words[num_words] == NULL){
				printf("Oops, the memory allocation malloc failed.\n");
				exit(0);
			}
			printf("Enter another word:  ");
			strcpy(words[num_words], word);	//copy the input word into the pointer array words[]
		}
		num_words++;					//increment num_words to keep track of how many words are entered
	}
	printf("\nYour words: ");
	for(int j = 0; j < num_words; j++){		//loop to print out the input words in order of input
		printf("%s ", words[j]);
	}
	qsort(words, num_words, sizeof(char*), compare_strings);  //qsort will sort words by using compare_strings()
      
   
    printf("\nIn sorted order: ");  // display the sorted list
    for (int i = 0; i < num_words; i++) {	//loop to display new sorted list
        printf(" %s",  words[i]);
    }
	free(*words);
    printf("\n");
    printf("\nExiting word sorting application\n");
	for(int i = 0; i < num_words; i++){		//free up the space allocated by malloc
		free(words[i]);
	}
    return 0;
}
