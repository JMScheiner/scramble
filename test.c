#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
	
	if(argc < 2){
		printf("Usage: test <dictionary>\n");
		exit(0);
	}
	
	trieNode* trie = init_trie(argv[1]);
	char word[MAX_WORD];
	while(1){
		scanf("%s",word);	
		if(find_word(trie,word)) printf("Word found!\n");
		else printf("Word not found.\n");
	}
}

