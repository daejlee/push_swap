
typedef struct s_decue
{
	struct s_decue	*next;
	struct s_decue	*previous;
	int				val;
	unsigned int	u_val;
	unsigned int	idx;
}	t_decue;

typedef struct s_decue_addr
{
	t_decue			*a_top;
	t_decue			*a_bottom;
	t_decue			*b_top;
	t_decue			*b_bottom;
	int				*idx_chamber;
	unsigned int	size;
	unsigned int	max;
	int				min;
}	t_decue_addr;

void			sa(t_decue_addr *p);
void			sb(t_decue_addr *p);
void			ss(t_decue_addr *p);
void			pa(t_decue_addr *p);
void			pb(t_decue_addr *p);
void			ra(t_decue_addr *p);
void			rb(t_decue_addr *p);
void			rr(t_decue_addr *p);
void			rra(t_decue_addr *p);
void			rrb(t_decue_addr *p);
void			rrr(t_decue_addr *p);
void			print_stack(t_decue_addr *p);
unsigned int	get_dig(unsigned int val, unsigned int div);
unsigned int	get_count(t_decue *target, unsigned int div, unsigned int pushing_int);
int				is_int(char **argv);
int				is_there_dup(char **argv);
int				check_already_sorted(t_decue *head);
t_decue_addr	*init_p(void);
unsigned int	push_args_to_a(char **argv, t_decue_addr *p);
int				print_err(void);
int				purge_lst(t_decue_addr *p);
void			push_and_rev_b(t_decue_addr *p, unsigned int count, unsigned int pushing_int, unsigned int div);
void			sort_loop_to_b(t_decue_addr *p, unsigned int div);
void			push_and_rev_a(t_decue_addr *p, unsigned int count, unsigned int pushing_int, unsigned int div);
void			sort_loop_to_a(t_decue_addr *p, unsigned int div);
void			manual_sort(int argc, t_decue_addr *p);
