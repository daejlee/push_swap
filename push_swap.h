
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

void	sa(t_decue **a_top_adr);
void	sb(t_decue **b_top_adr);
void	ss(t_decue **a_top_adr, t_decue **b_top_adr);
void	pa(t_decue **a_top_adr, t_decue **b_top_adr);
void	pb(t_decue **a_top_adr, t_decue **b_top_adr);
void	ra(t_decue **a_top_adr, t_decue **a_bottom_adr);
void	rb(t_decue **b_top_adr, t_decue **b_bottom_adr);
void	rr(t_decue_addr **p_adr);
void	rra(t_decue **a_top_adr, t_decue **a_bottom_adr);
void	rrb(t_decue **b_top_adr, t_decue **b_bottom_adr);
void	rrr(t_decue_addr **p_adr);
