#pragma once
class Fibonacci
{
private:
	long long* results = new long long[300];
public:
	long long calcular(long long x) {
		if (results[x] >= 0) {
			return results[x];
		}

		if (x < 2) {
			results[x] = x;

			return x;
		}

		results[x] = calcular(x - 1) + calcular(x - 2);

		return results[x];
	}
};

