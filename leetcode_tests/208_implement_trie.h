#ifndef _62_TRIE
#define _62_TRIE


#include <map>

using namespace std;

namespace leetcode {

	class TrieNode {
	public:
		// Initialize your data structure here.
    
		//tries stores string, one letter per node
		// normally just below root level is the 1st letter 
		TrieNode() {
		 endWord = false;
		}
    
		map<char,TrieNode*> letterToNode;
		bool endWord;

		
	};

	class Trie {
	public:
		Trie() {
			root = new TrieNode();
		}

		// Inserts a word into the trie.
		void insert(string word) {
        
			TrieNode* current = root;
			for(int i=0; i < word.length(); ++i)
			{
				char letter = word[i];
				//TrieNode* nextNode = NULL;
				if(current->letterToNode.find(letter)==current->letterToNode.end())
				{
					//new letter
					current->letterToNode[letter] = new TrieNode;
                
				}
				current = current->letterToNode[letter];
			}
			current->endWord = true;
		}

		// Returns if the word is in the trie.
		bool search(string word) {
			bool found = true;
        
			TrieNode* current = root;
			for(int i=0; i < word.length(); ++i)
			{
				char letter = word[i];
				//TrieNode* nextNode = NULL;
				if(current->letterToNode.find(letter)==current->letterToNode.end())
				{
					//new letter
					found = false;
					break;
				}
				current = current->letterToNode[letter];
			}
			if(current->endWord==false)
			{
				found = false;
			}

			return found;
		}

		// Returns if there is any word in the trie
		// that starts with the given prefix.
		bool startsWith(string prefix) {
			bool found = true;
			TrieNode* current = root;
			for(int i=0; i < prefix.length(); ++i)
			{
				char letter = prefix[i];
				//TrieNode* nextNode = NULL;
				if(current->letterToNode.find(letter)==current->letterToNode.end())
				{
					//new letter
					found = false;
					break;
				}
				current = current->letterToNode[letter];
			}
			return found;
		}

	private:
		TrieNode* root;
	};


};

#endif