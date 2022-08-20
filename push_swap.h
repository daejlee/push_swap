typedef struct s_decue
{
	struct s_decue	*next;
	struct s_decue	*previous;
	int				val;
}	t_decue;

typedef struct s_decue_addr
{
	t_decue	*a_top;
	t_decue	*a_bottom;
	t_decue	*b_top;
	t_decue	*b_bottom;
}	t_decue_addr;
