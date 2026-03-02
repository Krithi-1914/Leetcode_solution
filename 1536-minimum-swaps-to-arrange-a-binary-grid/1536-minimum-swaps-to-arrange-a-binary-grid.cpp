class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Count trailing zeros in each row
        vector<int> trailingZeros(n);
        
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = n - 1; j >= 0; j--){
                if(grid[i][j] == 0) count++;
                else break;
            }
            trailingZeros[i] = count;
        }
        
        int swaps = 0;
        
        // Greedy row placement
        for(int i = 0; i < n; i++){
            
            int requiredZeros = n - 1 - i;
            int j = i;
            
            // Find a row that satisfies requirement
            while(j < n && trailingZeros[j] < requiredZeros){
                j++;
            }
            
            if(j == n) return -1;  // Not possible
            
            // Bring row j to position i using adjacent swaps
            while(j > i){
                swap(trailingZeros[j], trailingZeros[j - 1]);
                swaps++;
                j--;
            }
        }
        
        return swaps;
    }
};