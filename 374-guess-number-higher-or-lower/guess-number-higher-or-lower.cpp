/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long guessNum = n / 2;
        long long l = 0, r = n;
        
        while (guess(guessNum) != 0) {
            if (guess(guessNum) == -1) {
                r = guessNum - 1;
            }
            else if (guess(guessNum) == 1) {
                l = guessNum + 1;
            }
            guessNum = (l + r) / 2;
        }
        return (int)guessNum;
    }
};