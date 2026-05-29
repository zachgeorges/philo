*This project has been created as part of the 42 curriculum by zgeorges*

# philo
Following the classic dining philosophers problem, the goal of this project is to explore the use of threads and mutexes to design an algorithm where no philosopher starves.


## Thoughts

- Each Philosopher is a tread
	- Then they don't share local vars and function calls
- Mutex limits access to each fork such that only one philo can access it at a given time
- STOPPED AT https://www.youtube.com/watch?v=zOpzGHwJ3MU 49:38.
- Need to add headers. Finish init, and test what was done thus far.