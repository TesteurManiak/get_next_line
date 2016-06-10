/*
** get_next_line.c for get_next_line in /home/roux_l/GitHub/get_next_line
** 
** Made by Guillaume Roux
** Login   <roux_l@epitech.net>
** 
** Started on Fri Jun 10 12:01:18 2016 Guillaume Roux
** Last update  Fri Jun 10 12:01:18 2016 Guillaume Roux
*/

#include <unistd.h>
#include <stdlib.h>

char  *get_next_line(const int fd)
{
  char  *res;
  char  buffer;
  int a;

  a = read(fd, &buffer, 1);
  if (a == 0 || a == -1)
    return (NULL);
  a = 0;
  res = malloc(sizeof(char) * 10000);
  res[a] = buffer;
  a++;
  while (buffer != '\n' && a < 10000)
    {
      read(fd, &buffer, 1);
      res[a] = buffer;
      a++;
    }
  if (a >= 10000)
    {
      // my_puterr = my_putstr sur la sortie d'erreur.
      my_puterr("Error in line\n");
      return (NULL);
    }
  res[a - 1] = '\0';
  return (res);
}