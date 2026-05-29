
#include "philo.h"

void	*malloc_controlled(size_t bytes)
{
	void	*res;

	res = malloc(bytes);
	if (res == NULL)
		error_exit("malloc failed");
	return (res);
}

static void	mutex_error(int status, t_code code)
{
	if (status == 0)
		return ;
	if (status == EINVAL && (code == LOCK || code == UNLOCK))
		error_exit("The value specifiedd by mutex is invalid.");
	else if (status == EINVAL && code == INIT)
		error_exit("The value specified by attr is invalid.");
	else if (status == EDEADLK)
		error_exit("A deadlock would occur if the thread blocked waiting for mutex.");
	else if (status == EPERM)
		error_exit("The current thread does not hold a lock on mutex.");
	else if (status == ENOMEM)
		error_exit("The process cannot allocate enough memory to create another mutex.");
	else if (status == EBUSY)
		error_exit("Mutex is locked.");
}

void	mutex_controlled(t_mutex *mutex, t_code code)
{
	if (LOCK == code)
		mutex_error(pthread_mutex_lock(mutex), code);
	else if (UNLOCK == code)
		mutex_error(pthread_mutex_unlock(mutex), code);
	else if (INIT == code)
		mutex_error(pthread_mutex_init(mutex, NULL), code);
	else if (DESTROY == code)
		mutex_error(pthread_mutex_destroy(mutex), code);
	else
		error_exit("Wrong code");
}

static void	thread_error(int status, t_code code)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		error_exit("insufficient resources to create another thread.");
	else if (status == EPERM)
		error_exit("No permission to set the scheduling policy and parameters.");
	else if (status == EINVAL && code == CREATE)
		error_exit("Invalid settings in attr.");
	else if (status == EINVAL && (code == JOIN || code == DETACH))
		error_exit("Thread is not joinable.");
	else if (status == ESRCH)
		error_exit("No thread found with given ID.");
	else if (status == EDEADLK)
		error_exit("Deadlock detected or thread is joining itself.");
}

void	thread_controlled(pthread_t *thread, void *(*f)(void *), void *data, t_code code)
{
	if (code == CREATE)
		thread_error(pthread_create(thread, NULL, f, data), code);
	else if (code == JOIN)
		thread_error(pthread_join(*thread, NULL), code);
	else if (code == DETACH)
		thread_error(pthread_detach(*thread), code);
	else
		error_exit("Wrong code");
}

