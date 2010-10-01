#include "trie.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void traverse_board(int i, int j, trieNode* trie);

char board[5][5];
char used[5][5];

int length;

int main(int argc, char** argv){
	
	if(argc < 3){
		printf("Usage: scramble <dictionary> <board - left right top bottom>\n");
		exit(0);
	}
	
	trieNode* trie = init_trie(argv[1]);
	int i,j;
	
		
	if(strlen(argv[2])!=25){
		printf("A board should be 25 characters in length\n");
	}
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			board[i][j] = argv[2][j + 5*i];
			used[i][j] = 0;
		}
	}

	/*Traverse board - searching trie from each board position.*/
	for(length=20;length>3;length--){	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			traverse_board(i,j,trie);
		}
	}
	}
	return 1;
}

void print_use_table(){
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf(" %d ", used[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void traverse_board(int i, int j, trieNode* trie){
	trieNode* next;	
	/*If the next character is in the trie, */
	if( (next = trie->list[board[i][j] - 'a']) ){
		
		used[i][j] = 1;
		//print_use_table();
		//usleep(50);
	
		/*If we found a word, print it*/
		if(next->full_word && strlen(next->full_word)==length)
			printf("%s\n",next->full_word);
		
		/*Traverse adjacent positions that aren't already used or out of bounds (clockwise).*/
		if(i-1 >= 0 && !used[i-1][j]) 					traverse_board(i-1,j,next);
		if(i-1 >= 0 && j+1 <  5 && !used[i-1][j+1]) 	traverse_board(i-1,j+1,next);
		if(j+1 <  5 && !used[i][j+1]) 					traverse_board(i,j+1,next);
		if(i+1 <  5 && j+1 <  5 && !used[i+1][j+1]) 	traverse_board(i+1,j+1,next);
		if(i+1 <  5 && !used[i+1][j]) 					traverse_board(i+1,j,next);
		if(i+1 <  5 && j-1 >= 0 && !used[i+1][j-1]) 	traverse_board(i+1,j-1,next);
		if(j-1 >= 0 && !used[i][j-1]) 					traverse_board(i,j-1,next);
		if(i-1 >= 0 && j-1 >= 0 && !used[i-1][j-1]) 	traverse_board(i-1,j-1,next);
		
	}
	else return;
	used[i][j] = 0;	
}
