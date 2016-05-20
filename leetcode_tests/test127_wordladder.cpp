#include "stdafx.h"
#include "test127_wordladder.h"

#include <iostream>
//#include <map>
#include <queue>



	
int test127_wordladder::ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    queue<node> q;
    q.push(node(beginWord, 1));
    wordList.erase(beginWord);
    while (!q.empty()) {
        node tmp = q.front();
        q.pop();
        if (endWord == tmp.val) {
            return tmp.depth;
        }
        string tmpString;
        for (char c = 'a'; c <= 'z'; ++c) {
            for (int i = 0; i < tmp.val.length(); ++i) {
                tmpString = tmp.val;
                tmpString[i] = c;
                if (tmpString != tmp.val && wordList.find(tmpString) != wordList.end()) {
                    q.push(node(tmpString, tmp.depth + 1));
                    wordList.erase(tmpString);
                }
            }
        }
    }
    return 0;
}



