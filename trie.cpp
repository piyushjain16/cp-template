#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////     trie      /////////////////////////////////////////////////////
class Trie {
    vector<Trie*> child;
    bool isEnd=false;
    public:
    // Initialize Trie. 
    Trie(){
        child = vector<Trie*>(26, nullptr);
    }

    // Adds a word into the Trie.->O(N) 
    void insert(string& word) {
        Trie *curr = this;
        for(char c: word){
            if(curr->child[c - 'a'] == nullptr)
                curr->child[c - 'a'] = new Trie();
            curr = curr->child[c - 'a'];
        }
        curr->isEnd = true;
    }
    
    // Returns if the word is in Trie.->O(N) 
    bool search(string& word) {
        Trie *curr = this;
        for(int i = 0; i < word.length(); ++i){
            char c = word[i];
            if(curr->child[c - 'a'] == nullptr) return false;
            curr = curr->child[c - 'a'];
        }
        return curr && curr->isEnd;
    }

    // check if a word start with given prefix -> O(N)
    bool startsWith(string& prefix) {
        Trie* curr = this;
        for (char c : prefix) {
            if (curr->child[c - 'a'] == nullptr)  return false;
            curr = curr->child[c - 'a'];
        }
        return true;
    }
};


////////////////////////////////////////////////////////////////////////end//////////////////////////////////////////////////////////////////////////////////////