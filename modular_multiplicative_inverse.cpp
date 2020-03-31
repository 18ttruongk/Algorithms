#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

/* Definition: x is called modular multiplicative inverse
 * of b if: bx mod m = 1 OR bx = 1 mod m
 */

/**
 * Find x such that x is the modular multiplicative inverse of b
 */
int modular_inverse(int b, int m){
	b = b % m;
	for(int x = 1; x < m; ++x){
		int r = (b * x) % m;
		if(r == 1) return x;
	}

	return -1; // mod inverse doesn't exist
}

/* Compute modular exponentiation */
int modular_exponentiation(int a, int b, int m){
	int res = 1;
	a = a % m;

	while(b > 0){
		if(b % 2 == 1){
			res = (res * a) % m;
		}
		b = b / 2;
		a = (a * a) % m;
	}

	return res;
}

/* We can have a faster algorithm using 
 * Fermat's little theorem: If m is a prime number and b doesn't
 * divide m, then (b^(m-1) - 1) divides m
 * In other words, (b^(m-1)) = 1 (mod m)
 * => (b * b^(m-2)) = 1 (mod m)
 * => x = (b^(m-2)) (mod m)
 *
 * ***Note: we need to use fast modular_exponentiation algorithm to
 * compute b^(m-2)
 * => Time complexity: O(log(m))
 */
int modular_inverse(int b, int m){
	int res = modular_exponentiation(b, m - 2, m);
	if( (res*b) % m == 1) return res;

	return -1; // modular inverse doesn't exist
}

/* Extended Euclidean algorithm: find the greatest common
 * divisor of two numbers a and b, gcd(a,b)
 */
int gcd(int a, int b){
	int remainder;
	while(b != 0){
		remainder = a % b;
		a = b;
		b = remainder;
	}

	return a;
}

int main() {
	
	
	return 0;
}