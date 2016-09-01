// Fast Exponential
//Calculating fast exponential of real base and integer exp.
long double ipow(long double base, unsigned int exp)
{
	long double result = 1.000;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

// Newton-Raphson
//Finding nth root of number using newton raphson formula with given precision
long double findRoot(unsigned int n, long double number, long double precision){

	long double guess = n/2.0;
	long double new_guess;
	long double diff = 1.0;

	while(diff > precision){
		new_guess = ((n-1)*guess + (number/ipow(guess,n-1)))/(ld)n;
		diff = fabs(guess - new_guess);
		guess = new_guess;
	}
	return new_guess;
}


//Finding gcd of two numbers
//a and b both can not be zero
long long gcd(long long a, long long b){

	if(b == 0){
		return 0;
	}
	return gcd(b,a%b);
}

//Finding lcm of two numbers
long long lcm(long long a, long long b){
	return (b*a)/gcd(a,b);
}

//Reducing rational number P/Q to simplest form of fraction
long long reduceFraction(long long *P, long long *Q){
	long long g = gcd(*P,*Q);
	*P =  *P/g;
	*Q =  *Q/g;
}