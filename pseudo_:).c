
int	sort_and_print_operations(p)
{
	//going for radix sort
	chamber = (int *)malloc(sizeof(int) * arrsize);
	use chamber in every divs. -> get idx for every elements.;
	getting u_val for every ints;
		1. pushing absolute val of negative min for every ints.
		2. sort, push positive fisrt and sort, push for negative nums.
		-> gonna compare both methods and will pick the better one.
	push, swap in accordance with idx comparision between chamber;
}

int	main(int argc, char **argv)
{
	if (no parameter are specified)
		 give the prompt back;
	else if (some args arent int ||
			some args are bigger than int ||
			there are duplicates)
		display "Error\n" on stderr;

	push_args_to_a(argv);
	if (already sorted)
		return (0);
	[./push_swap 6, 2, 9, 4 -> (top)6, 2, 9, (bottom)4];
	sort_and_print_operations(p); -> real deal
	[6, 2, 9, 4 -> (top)2, 4, 6, (bottom)9];
	return (1);
}
