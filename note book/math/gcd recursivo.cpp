int gcd(int a, int b){ // complexity O(log(min(a,b)))
    if(b==0) return a;
    return gcd(b, a%b);
}