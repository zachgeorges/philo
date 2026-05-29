

#include "philo.h"

int	main(int ac, char **av)
{
	t_info input;

	if (ac == 5 || ac == 6)
	{
		parse_input(&input, av); //handles error checking, filing data
		data_init(&input); //initialize
		start_sim(&input);
		cleanup(&input);
	}
	else
	{
		error_exit("Wrong input:\n");
	}
}