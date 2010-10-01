
#define MAX_WORD 50

/** 
* @brief Basic Trie structure.
* typical use has a root node with depth 0,
* and subsequently, depth is the length of the word.
* letter is current letter, end means a word has ended.
*/
typedef struct _trie_node{
	char letter;
	char depth; 
	char* full_word;
	struct _trie_node* list[26];
} trieNode;


trieNode* init_trie(char* dictionary);

int init_node(trieNode* trie);
int add_word(trieNode* trie, char* word);
int find_word(trieNode* trie, char* word);
