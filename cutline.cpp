template<typename T> 
class DS {
    multiset<T> low, up;
    int M;
public:
    DS(int k) {
        M = k;
    }
    
    void add(T val) {
        if (low.empty() || val <= *low.rbegin()) {
            low.insert(val);
        } else {
            up.insert(val);
        }
        
        if (low.size() > (M + 1) / 2) {
            up.insert(*low.rbegin());
            low.erase(--low.end());
        }
        if (up.size() > M / 2) {
            low.insert(*up.begin());
            up.erase(up.begin());
        }
    }

    void remove(T val) {
        if (up.find(val) !=up.end()) {
             up.erase(up.find(val));
        }
        else  low.erase(low.find(val));
        
        if (low.size() < (M + 1) / 2 && !up.empty()) {
            low.insert(*up.begin());
            up.erase(up.begin());
        }
        
    }

    double getAns() {
        if (M % 2 == 1) {
            return *low.rbegin();
        }
        return (*low.rbegin() + *up.begin()) / 2.0;
    }
};
