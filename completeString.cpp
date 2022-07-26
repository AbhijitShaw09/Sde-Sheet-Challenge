struct Node
{
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};

class Trie
{
    Node* root;
    public:
    Trie() {
        root = new Node();
    }
    
    void insert(string& word) {
        Node* node = root;
        for(int i = 0; i < word.length(); i++) {
            if(!node -> containsKey(word[i]))
                node -> put(word[i], new Node());
            node = node -> get(word[i]);
        }
        node -> setEnd(); 
    }
    
    bool checkAllPrefix(string& word) {
        Node* node = root;
        for(int i = 0; i < word.length(); i++) {
            if(!node -> containsKey(word[i]))
                return false;
            else {                
                node = node -> get(word[i]);
                if(!node -> isEnd())
                    return false;
            }
        }
        return node -> isEnd();
    }  
};
string completeString(int n, vector<string> &arr){
    // Write your code here.
    Trie trie;
    for(string& word: arr)
        trie.insert(word);

    string longest = "";
    for(string& word: arr) {
        if(trie.checkAllPrefix(word)) {
            if(word.length() > longest.length())
                longest = word;
            else if(word.length() == longest.length() && word < longest)
                longest = word;
        }
    }
    if(longest == "")
        return "None";
    return longest; 
}
