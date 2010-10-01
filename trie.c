#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** 
* @brief Adding fake documentation to keep playing with github.
* 
* @param trie 
* @param word 
* 
* @return 
*/
int add_word(trieNode* trie, char* word){
	int i, j, length = strlen(word);
	if(trie->letter){
		 printf("add_word should only be passed the root of a trie\n");
		 return 0;
	}
	
	for(i=0;i<length;i++){
		if(trie->list[word[i] - 'a']) 
			trie = trie->list[word[i] - 'a'];
		
		else{
			trie = trie->list[word[i] - 'a'] = malloc(sizeof(trieNode));
			init_node(trie);	
			trie->letter = word[i];
			trie->depth = i+1;
		}
	}
	trie->full_word = malloc(strlen(word));
	strcpy(trie->full_word,word);
	return 1;
}

int init_node(trieNode* trie){
	int i;	
	for(i = 0; i<26;i++) trie->list[i] = NULL;
	trie->letter = 0;
	trie->full_word = NULL;
	return 1;
}

trieNode* init_trie(char* dictionary){
	FILE* dict; 
	
	if(!(dict = fopen(dictionary, "r")))	{
		printf("Error opening dictionary\n");
		exit(0);
	}
	
	char word[MAX_WORD];
	trieNode* trie = malloc(sizeof(trieNode));
	init_node(trie);
	
	while(fscanf(dict, "%s\n",word) != EOF)
		add_word(trie,word);			
	
	return trie;
}

int find_word(trieNode* trie, char* word){
		 printf("find_word should only be passed the root of a trie\n");
		 return 0;
	}
	
	for(i=0;i<length;i++){
		if(trie->list[word[i] - 'a']) 
			trie = trie->list[word[i] - 'a'];
		else return 0;
	}
	
	if(trie->full_word) return 1;
	return 0;
}

