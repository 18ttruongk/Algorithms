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
/* Get bit of number x at position k */
int get_bit(int x, int k){
	return (X >> k) & 1;
}

/* Set the value at kth bit to 0 for number x */
void set_bit_zero(int x, int k){
	x = x & (~(1 << k));
}

/* Set the value at kth bit to 1 for number x */
void set_bit_one(int x, int k){
	x = x | (1 << k);
}

/* Swap the value at kth bit for number x */
void flip_bit(int x, int k){
	x = x ^ (1 << k);
}

// ***Important xor property:  x ^ x = 0

int main() {
	
	
	return 0;
}