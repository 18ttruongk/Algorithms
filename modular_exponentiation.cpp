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

/* Important mod properties:
 *  - Addition: (a+b) mod m = ((a mod m) + (b mod m)) mod m
 *	- Subtraction: (a-b) mod m = ((a mod m) - (b mod m)) mod m
 *	- Multiplication: (a*b) mod m = ((a mod m) * (b mod m)) mod m
 */

/* Modular Exponentiation: Find (a^b) % m
 * This algorithm uses the multiplication mod property
 * (a^b) % m = ((a mod m) * (a mod m) ... ) mod m ( b times )
 * => Time complexity: O(b)
 */
long long modular_exponentiation(int a, int b, int m){
	long long res = 1;

	for(int i = 1; i <= b; ++i){
		res *= a;
		res %= m;
	}

	return res;
}

/* Modular Exponentiation: Find (a^b) % m
 * This algorithm uses the formula:: (a^b) mod m = ( (a mod m)^b ) mod m
 * It then applies the exponentiation_by_squaring algorithm to compute
 * (a mod m) ^ b
 *
 * Formula for exponentiation_by_squaring: 
 *	 a^b = a * ((a^2)^((b-1)/2) if b is odd
 * OR a^b = (a^2)^(b/2) if b is even
 * This algorithm terminates when b gets to 0
 * => Time complexity: O(log b)
 */
long long faster_modular_exponentiation(int a, int b, int m){
	int result = 1;
	a %= m;
	while(b > 0){
		// if b is odd, multiply a with result
		if( b % 2 == 1 ){
			result = (result * a) % m;
		}
		b /= 2;
		a = (a * a) % m;
	}

	return res;
}

int main() {
	
	
	return 0;
}