class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x;
            n = abs(n);
        }
        return realPow(x, n);
    }

    double realPow(double x, int n) {
        if (n == 0) return 1;

        double sub = realPow(x, n / 2);
        
        return n % 2 == 0 ? sub * sub : sub * sub * x;
    }
};