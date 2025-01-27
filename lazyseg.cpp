class segTree{
	vector<int>se;
	vector<int>lazy;
	int n;

	public:

	segTree(int n){
		this->n=n;
		se.resize(4*n , 1e18);
		lazy.resize(4*n ,1e18);
	}

	int comb(int u , int v)
	{
		return min(u ,v);
	}

	void push(int idx , int l ,int r){

		if(lazy[idx]!= 1e18){
			se[idx] = min(se[idx] , lazy[idx]);

			if(l!=r){
				lazy[2*idx+1] = min(lazy[2*idx+1] , lazy[idx]);
				lazy[2*idx+2] = min(lazy[2*idx+2] , lazy[idx]);
				return;
			}
			lazy[idx]=1e18;
		}

	}

	int query(int idx, int s , int e, int l , int r){
		push(idx , s, e);
		if( r<s || e<l){
			return 1e18;
		}
		if(l<=s && e<=r){
			return se[idx];
		}

		int mid = (s+e)/2;
		int left = query(2*idx+1 , s, mid,l ,r);
		int right= query(2*idx+2 , mid+1 ,e , l , r);
		return min(left, right);
	}	


	void update(int idx , int s, int e , int l , int r , int val){
		push(idx , s, e);
		if( r<s || e<l){
			return ;
		}
		
		if(l<=s && e<=r){
			lazy[idx]=min(lazy[idx] , val);
			push(idx, s, e);
			return;
		}

		int mid = (s+e)/2;

		update(2*idx+1 , s , mid , l , r, val);
		update(2*idx+2 , mid+1 , e, l , r , val);
		se[idx]= comb(se[2*idx+1] , se[2*idx+2]);
	}

	void upd(int l , int r , int val){
		return update(0 , 0 , n-1 , l , r, val);
	}

	int quer(int l, int r){
		return query(0 ,0 , n-1 , l ,r);
	}
};

