#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 4

int winner = 0;

void *Start(void *playerId)
{
  int i = 0;
  while (winner == 0 && i < 1000)
    i++;

  if (winner == 0)
  {
    winner = *((int *)(playerId));
  }

  pthread_exit(NULL);
}

int main(void)
{
  pthread_t Player[MAX_THREADS];

  for (int i = 0; i < MAX_THREADS; i++)
  {
    pthread_create(&Player[i], NULL, Start, &i);
  }

  for (int i = 0; i < MAX_THREADS; i++)
  {
    pthread_join(Player[i], NULL);
  }

  printf("\n\nPlayer %d won!!!\n\n", winner);

  return EXIT_SUCCESS;
}