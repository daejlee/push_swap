
typedef struct s_decue
{
	struct s_decue	*next;
	struct s_decue	*previous;
	int				val;
}	t_decue;

typedef struct s_decue_addr
{
	t_decue			*a_top;
	t_decue			*a_bottom;
	t_decue			*b_top;
	t_decue			*b_bottom;
	unsigned int	size;
	int				max;
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
int				is_int(char **argv);
int				is_there_dup(char **argv);
int				check_already_sorted(t_decue *head);
t_decue_addr	*init_p(void);
unsigned int	push_args_to_a(char **argv, t_decue_addr *p);
int				print_err(void);
int				purge_lst(t_decue_addr *p);
