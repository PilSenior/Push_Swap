#include "philo.h"

int error_exit(char *msg)
{
    printf("Error: %s\n", msg);
    return (1);
}

int main(int argc, char **argv)
{
    t_data data;

    if (argc != 5 && argc != 6)
        return (error_exit("Invalid number of arguments"));

    if (init_data(&data, argc, argv))
        return (error_exit("Initialization failed"));

    // Tek filozof özel durumu
    if (data.nb_philo == 1) {
        printf("0 1 has taken a fork\n");
        ft_usleep(data.time_die);
        printf("%d 1 died\n", data.time_die);
        destroy_all(&data);
        return (0);
    }
    if (start_threads(&data)) {
        destroy_all(&data);
        return (error_exit("Thread start failed"));
    }

    destroy_all(&data);
    return (0);
}
