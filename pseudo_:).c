int	main(int argc, char **argv)
{
	if (no parameter are specified)
		 give the prompt back;
	else if (some args arent int ||
			some args are bigger than int ||
			there are duplicates)
		display "Error\n" on stderr;

	push_arg_to_A(argv);
	[./push_swap 6, 2, 9, 4 -> (top)6, 2, 9, (bottom)4];
	sort_and_print_operations(); -> real deal
	[6, 2, 9, 4 -> (top)2, 4, 6, (bottom)9];
	return (1);
}