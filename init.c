
#include "philo.h"

static void	forks_assign(t_philo *philo, t_fork *forks, int index)
{
	
}

static void	init_philo(t_info *info)
{
	int	i;
	t_philo	*philo;

	i = -1;
	while(++i < info->number_of_philosophers)
	{
		philo = info->philos + i;
		philo->num = i + 1;
		philo->full = false;
		philo->times_eaten = 0;
		philo->info = info;
		forks_assign(philo, info->forks, i);
	}
}

void	data_init(t_info *info)
{
	int	i;

	i = -1;
	info->end_sim = false;
	info->philos = malloc_controlled(sizeof(t_philo) * info->number_of_philosophers);
	info->forks = malloc_controlled(sizeof(t_fork)* info->number_of_philosophers);
	while (++i < info->number_of_philosophers)
	{
		mutex_controlled(&info->forks[i].fork, INIT);
		info->forks[i].fork_num = i;
	}
	init_philo(info);



}