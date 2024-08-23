class Solution {
public:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    string fractionAddition(string s) {
        int n = s.size();
        int lcmm = 1;  
        int numerator = 0; 

        for (int i = 0; i < n; i++) {
            if (s[i] == '/') {
                lcmm = lcm(lcmm, atoi(&s[i + 1]));
            }
        }

        for (int i = 0; i < n; ) {
            int sign = (s[i] == '-') ? -1 : 1;
            if (s[i] == '-' || s[i] == '+') i++;
            int num = atoi(&s[i]);
            while (s[i] != '/') i++;
            int denom = atoi(&s[i + 1]);
            numerator += sign * (num * (lcmm / denom));
            while (i < n && s[i] != '+' && s[i] != '-') i++;
        }

        int gcd_val = gcd(abs(numerator), lcmm);
        numerator /= gcd_val;
        lcmm /= gcd_val;

        string result = (numerator < 0 ? "-" : "") + to_string(abs(numerator)) + "/" + to_string(lcmm);
        return result;
    }
};
