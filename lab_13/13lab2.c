#include <stdio.h>
#include <ctype.h>
#include <inttypes.h>
#include <assert.h>

const uint64_t CONSONANTS = (
        1u << ('b' - 'a') | 1u << ('c' - 'a') | 1u << ('d' - 'a') | 1u << ('f' - 'a') | 1u << ('g' - 'a') |
        1u << ('h' - 'a') | 1u << ('j' - 'a') | 1u << ('k' - 'a') | 1u << ('l' - 'a') | 1u << ('m' - 'a') |
        1u << ('n' - 'a') | 1u << ('p' - 'a') | 1u << ('q' - 'a') | 1u << ('r' - 'a') | 1u << ('s' - 'a') |
        1u << ('t' - 'a') | 1u << ('v' - 'a') | 1u << ('w' - 'a') | 1u << ('x' - 'a') | 1u << ('z' - 'a')
);

int main() {

    uint64_t cons = CONSONANTS; 
    char c;

    while ((c = tolower(getchar())) != '*') {
        	if ( (1u << ( c - 'a') & ~cons)  == 0) {
        		cons = cons & ~(1u << ( c - 'a'));
        	} 
    }
    if (cons == 0 ) {
    	printf("All consonants met in line\n");
    } else printf("There are consonants that are not found in the line\n");
    return 0;
}
