class BL{
    vector<vector<int>>bull;
    vector<int>depth;
    int n;
    int MX;
    int Limit;

    public:
    BL(int n, int Limit){
        this->MX =log2(n)+1;
        this->n=n;
        bull.resize(MX , vector<int>(n+1,Limit));
        depth.resize(n);
        this->Limit=Limit;
    }


    void build(vector<int>&par){

        for(int i=1; i<=n ;i++){
            bull[0][i]=par[i];
        }

        for(int i=1 ; i<MX ;i++){

            for(int j=1; j<=n ;j++){

                if(bull[i-1][j]==Limit){
                    continue;
                }
                bull[i][j]= bull[i-1][bull[i-1][j]];

            }

        }
    }

    int KthParent(int node, int K){

        for(int i=0; i<MX ; i++){

            if(K&(1<<i)){
                node = bull[i][node];
                if(node==Limit)break;
            }
        }
        return node;
    }

    void dfs(vector<vector<int>>&a, int u,int p, int dept){
        depth[u]=dept;  

        for(auto v: a[u]){
            if(v!=p){
                dfs(a, v, u , dept+1);
            }
        }
    }

    int LCA(int x, int y){
        if(x==y)return x;
        // x ko chota man liya

        if(depth[x] > depth[y])swap(x,y);


        int up = depth[y]-depth[x];

        y= KthParent(y , up);

        if(y==x)return x;


        for(int i=MX-1 ; i>=0 ; i--){


            if(bull[i][x]!=bull[i][y]){
                x=bull[i][x];
                y=bull[i][y];
            }
        }
        return bull[0][x];
    }
};