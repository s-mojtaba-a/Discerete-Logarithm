from math import sqrt, gcd


class DL:
    ''' a^x = b (mod m)
        a and m may be coprime or not
    '''

    def __init__(self):
        self.Q = {}

    def power(self, x, y, n):
        x %= n
        ans = 1
        while y > 0:
            if y & 1 == 1:
                ans = ans*x % n
            x = x*x % n
            y >>= 1
        return(ans)

    def find_q(self, a, b, m, n):
        ans = b
        for i in range(0, n+1):
            self.Q[ans] = i
            ans = ans*a % m

    def find_add_and_k(self, a, b, m):
        ''' it may return the solution or it may say that there is no solution '''
        k = 1
        add = 0
        while (gcd(a, m) > 1):
            g = gcd(a, m)
            if b == k:
                return (b, m, -1, add)
            if b % g:
                return (b, m, -1, -1)
            b //= g
            m //= g
            k = (k*a//g) % m
            add += 1
        return (b, m, k, add)

    def solve(self, a, b, m):
        ''' it returns the smallest x  '''
        a %= m
        b %= m
        if (a == 0):
            if b == 0:
                return 1
            else:
                return -1
        b, m, k, add = self.find_add_and_k(a, b, m)
        if k == -1:
            return add
        n = int(sqrt(m))+1
        self.find_q(a, b, m, n)
        an = self.power(a, n, m)
        temp = k*an
        for p in range(1, n+1):
            if self.Q.get(temp, None) != None:
                return p*n-self.Q[temp]+add
            temp = temp*an % m
        return -1


