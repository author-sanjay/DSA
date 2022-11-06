class Trienode{
    public:
        char data;
        Trienode* children[26];
        bool isTerminal;
        
        Trienode(char c){
            data=c;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isTerminal=false;
        }
};
class Trie {
    
public:
    Trienode* root;
    
    Trie() {
        root=new Trienode('\0');    
    }
    void insertUtil(Trienode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        Trienode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            child=new Trienode(word[0]);
            root->children[index]=child;
        }
        
        insertUtil(child,word.substr(1));
    }
    void insert(string word) {
        insertUtil(root,word);
    }
    
     bool searchUtil(Trienode* root,string word){
        if(word.length()==0){
            return root->isTerminal;
            
        }
        int index=word[0]-'a';
        Trienode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            return false;
        }
        
        return searchUtil(child,word.substr(1));
        // return false;
    }
    bool search(string word) {
        return searchUtil(root,word);
    }
    
    
    bool startwithUtil(Trienode* root,string word){
        if(word.length()==0){
            return true;
            
        }
        int index=word[0]-'a';
        Trienode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            return false;
        }
        
        return startwithUtil(child,word.substr(1));
        // return false;
    }
    bool startsWith(string prefix) {
        return startwithUtil(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */