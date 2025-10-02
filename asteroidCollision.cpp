class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        list<int> st; // using list as a stack
        for(int i = 0; i < n; i++) {
            if(asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            } else {
                while(!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) {
                    st.pop_back(); // smaller positive asteroid explodes
                }
                if(!st.empty() && st.back() == abs(asteroids[i])) {
                    st.pop_back(); // both asteroids explode
                } else if(st.empty() || st.back() < 0) {
                    st.push_back(asteroids[i]); // no collision
                }
            }
        }
        
        // Convert list to vector
        return vector<int>(st.begin(), st.end());
    }
};
