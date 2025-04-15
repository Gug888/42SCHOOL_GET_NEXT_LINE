#include "get_next_line.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    int i = 0;
    if (fd < 0)
    {
        printf("file open error\n");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        i++;
        printf("get: %s", line);
        free(line);
    }
    printf("\n");
    close(fd);
    return (0);
}