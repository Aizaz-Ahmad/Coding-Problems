//https://leetcode.com/problems/number-of-1-bits/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        // run until the number is not zero i.e. no 1 left
        while(n){
            //take XOR of the number, if the right-most bit of the number is 1
            //then XOR will make that 0 and the number = number - 1, and thus
            // difference number - (number ^ 1) == 1, so the bit is one, count it
            if(n - (n ^ 1) == 1) count++;
            //right shift the number by 1, to make right + 1 bit = right
            n = n >> 1;
        }
        return count;
    }
};

//https://leetcode.com/problems/number-of-1-bits/discuss/55255/C%2B%2B-Solution%3A-n-and-(n-1)
int hammingWeight(uint32_t n) {
    int count = 0;
    
    while (n) {
        n &= (n - 1);
        count++;
    }
    
    return count;
}
