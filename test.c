int func(int n){
	if(n == 1)
		return 1;
	else
		return n * func(n - 1);
}

int main()
{
	int n, result;

	n = read();
	result = func(n);
	write(result);
	
	return 0;
}