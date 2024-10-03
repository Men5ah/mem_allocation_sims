#include <stdio.h>

int PAGE_SIZE = 50;
int PAGE_FRAME_NUMBER = 20;

int main() {
  int job_size = 100;
  int job_pages = (job_size / PAGE_SIZE);
  int internal_fragmentation = job_size % PAGE_SIZE;
  if (internal_fragmentation > 0) {
    job_pages++;
  }

  printf("job size: %d\n", job_size);
  printf("job pages: %d\n", job_pages);
  printf("internal fragmentation: %d\n", internal_fragmentation);
}
