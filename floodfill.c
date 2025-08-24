#include <stdlib.h>
#include "so_long.h"
#include "libft/libft.h"
#include "mlx/mlx.h"

static char **copy_map(char **map, int height)
{
    int  i;
    char **map_copy;

    map_copy = malloc(sizeof(char *) * (height + 1));
    if (!map_copy)
        return (NULL);
    i = 0;
    while (i < height)
    {
        map_copy[i] = ft_strdup(map[i]);
        if (!map_copy[i])
        {
            while (i >= 0)
            {
                free(map_copy[i]);
                i--;
            }
            free(map_copy);
            return (NULL);
        }
        i++;
    }
    map_copy[i] = NULL;
    return map_copy;
}

static void filling(char **map, int x, int y, int width, int height)
{
    if (x < 0 || y < 0 || y >= height || x >= width)
        return;
    if (!map[y] || (int)ft_strlen(map[y]) <= x)
        return;
    if (map[y][x] == '1' || map[y][x] == 'x')
        return;
    map[y][x] = 'x';
    filling(map, x + 1, y, width, height);
    filling(map, x - 1, y, width, height);
    filling(map, x, y + 1, width, height);
    filling(map, x, y - 1, width, height);
}

static int check_access(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C' || map[i][j] == 'E')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int floodfill(t_data *data, char **map, int width, int height)
{
    char **map_copy;

    map_copy = copy_map(map, height);
    if (!map_copy)
            return (0);
    filling(map_copy, data->player_x,
        data->player_y, width, height);
    if (0 == check_access(map_copy))
    {
        free_map(map_copy);
        return(0);
    }
    free_map(map_copy);
    return (1);
}
