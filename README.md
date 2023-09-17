# Philosophers

This project is part of the curriculum at 42 School and focuses on multithreading and synchronization using mutexes. It involves simulating philosophers at a dining table and requires the implementation of proper synchronization mechanisms to prevent data race, deadlocks, and philosophers' starvation.

## Table of Contents

- [Description](#description)
- [Usage](#usage)

## Description

The main objective of this project is to develop a multi-threaded solution that emulates the classic **Dining Philosophers problem**, employing mutexes for synchronization. In this scenario, a group of philosophers sits at a table, where each philosopher has one fork initially and needs to acquire a second fork from their neighboring philosophers to eat. They alternate between thinking and eating for a certain amount of time. To prevent issues such as deadlocks, data races, and philosophers' starvation, it is necessary to implement proper synchronization mechanisms.

## Usage

To use this program, follow these steps:

1. Clone the repository to your local machine:

   ```
	git clone <repo url> philosophers
   ```

2. Navigate to the project directory:

   ```
   cd philosophers/philo
   ```

3. Build the project:

   ```
   make
   ```

4. Run the program with the simulation parameters:

   ```
   ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
   ```

- `number_of_philosophers`: The number of philosophers, which is also equivalent to the number of forks.
- `time_to_die` (in milliseconds): If a philosopher doesn't start eating within time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they will die.
- `time_to_eat` (in milliseconds): The duration required for a philosopher to finish a meal while using two forks.
- `time_to_sleep` (in milliseconds): The time a philosopher will spend sleeping.
- `number_of_times_each_philosopher_must_eat` (optional argument): Specifies the minimum number of times each philosopher must eat before the simulation stops. If not specified, the simulation stops when a philosopher dies.

**_Please note that the performance of this simulation may vary depending on the hardware used. I observed that the simulation runs significantly more efficiently on Dell hardware compared to Mac._**
