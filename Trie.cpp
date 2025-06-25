struct node{
    char ch;
    node*links[26];
    bool isTerminal;

    node(char ch){
        this->ch=ch;
        for(int i=0; i<26; i++){
            links[i]=NULL;
        }
        isTerminal=false;
    }

};

class Trie{

   

    public:
    node*root;

    Trie(){
        root= new node('\0');
    }

    bool insert(node *root ,string s){

        for(int i=0; i<s.size() ; i++){
            int idx = s[i]-'a';

            if(root->links[idx]==NULL){
                root->links[idx]= new node(s[i]);
            }
            root=root->links[idx];
        }
        root->isTerminal=true;
        return root->isTerminal;
    }

    bool search(node *root ,string s){

        for(int i=0; i< s.size() ; i++){
            int idx = s[i]-'a';
            cout<< s[i]<<" ";
            if(root->links[idx]){
                root=root->links[idx];
            }
            else return false;
        }
        return root->isTerminal;
    }

    void remove(node *root , string s){
        for(int i=0; i< s.size() ; i++){
            int idx = s[i]-'a';
            if(root->links[idx]){
                root=root->links[idx];
            }
            else return ;
        }
        root->isTerminal=false;   
    }

    bool hardRemove(node *root , string s){

        if(s.empty()){
            root->isTerminal=false;
            int cnt=0;
            for(int i=0;i<26; i++){
                if(root->links[i])cnt++;
            }

            return cnt>=1? false :true;
        }

        int idx = s[0]-'a';
        if(root->links[idx]){   
            
            if(hardRemove(root->links[idx], s.substr(1))){
                int ct=0;

                delete root->links[idx];
                root->links[idx]=NULL;
                for(int i=0;i<26; i++){
                    if(root->links[i])ct++;
                }

                cout<<ct<<endl;

                if(ct>=1 || root->isTerminal){
                    return false;
                }
                else{
                    cout<<s[0]<<" ";
                    cout<<"root->Delted"<<endl;
                    return true;
                }

            }
            else{
                return false;
            }
        }
        return false;
    }

    bool insertWord(string s){
        return insert(root, s);
    }
    bool searchWord(string s){
        return search(root, s);
    }
    void removeWord(string s){
        hardRemove(root,s);
    }
};
