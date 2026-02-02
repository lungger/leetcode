class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if (!s.empty()) {
            int temp = *s.begin();
            s.erase(temp);
            return temp;
        }
        else {
            return count++;
        }
    }
    
    void addBack(int num) {
        if (num < count) {
            s.insert(num);
        }
    }

private:
    set<int> s;
    int count = 1;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */