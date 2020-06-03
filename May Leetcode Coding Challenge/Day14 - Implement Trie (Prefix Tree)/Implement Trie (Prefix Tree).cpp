/*

Problem Statement:
Implement a trie with insert, search, and startsWith methods.

Example:
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true

*/
// Solution:
class Node{
	char c;
	HashMap<Character, Node> children = new HashMap<>();
	boolean eow;
	
	public Node(){
		
	}
	public Node(char c){
		this.c = c;
	}
}

class Trie {

    Node root;
    
    /** Initialize your data structure here. */
    public Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        HashMap<Character, Node> children = root.children;
        for(int i=0; i<word.length(); i++){
            char c = word.charAt(i);
            Node n;
            if(children.containsKey(c)){
                n = children.get(c);
            }else{
                n = new Node(c);
                children.put(c, n);
            }
            children = n.children;
            if(i == word.length()-1){
                n.eow = true;
            }
        }
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        HashMap<Character, Node> children = root.children;
        for(int i=0; i<word.length(); i++){
        	char c = word.charAt(i);
        	Node n;
            if(children.containsKey(c)){
                n = children.get(c);
            }else{
                return false;
            }
            children = n.children;
            if(i == word.length()-1){
	            return n.eow;
            }
        }
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        HashMap<Character, Node> children = root.children;
        for(int i=0; i<prefix.length(); i++){
            char c = prefix.charAt(i);
            Node n;
            if(children.containsKey(c)){
                children = children.get(c).children;
            }else{
                return false;
            }
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */