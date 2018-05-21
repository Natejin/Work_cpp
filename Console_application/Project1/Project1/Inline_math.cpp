__inline int Il_cubic(int a)
{
	return  a * a*a;
}

__inline int Il_square(int a)
{
	return  a * a*a;
}

__inline int Il_max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

__inline int Il_min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}
