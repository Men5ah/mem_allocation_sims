#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int PAGE_SIZE = 100;
int PAGE_FRAME_NUMBER = 4;

// TODO : Accept job
// TODO: Divide the job into pages based on specified size
// TODO: Indicate internal fragmentation if any
// TODO: Load jobs into page frames randomly
// TODO: Perform address resolution

int main() {
  // initialize memory to zero
  char *memory[PAGE_FRAME_NUMBER]; // create an array of strings
  for (int i = 0; i < PAGE_FRAME_NUMBER; i++) {
    memory[i] = (char *)malloc(10);
    strcpy(memory[i], "");
  }

  srand(time(0)); // seed random number generator

  int job_size = 350;
  int job_pages = (job_size / PAGE_SIZE);

  // display error if job size exceeds page frame number
  if (job_pages > PAGE_FRAME_NUMBER) {
    printf("Job cannot be loaded into memory\n");
    printf("Job page number exceeds the page frame number\n");
    exit(0);
  }

  int last_page_size = job_size % PAGE_SIZE;
  int internal_fragmentation = PAGE_SIZE - last_page_size;
  if (last_page_size > 0) {
    job_pages++;
  }

  int tag = -1;
  for (int i = 0; i < job_pages; i++) {
    int idx = rand() % PAGE_FRAME_NUMBER;
    if (strlen(memory[idx]) == 0) {
      // sprintf(memory[idx], "%s_%d_%d", "job", 1, idx);
    }
    printf("%d\n", idx);
    // sprintf(memory[idx], "%s_%d_%d", "job", 1, idx);
  }

  for (int i = 0; i < PAGE_FRAME_NUMBER; i++) {
    printf("[%d] %s\n", i, memory[i]);
  }

  printf("job_size: %d\n", job_size);
  printf("job_pages: %d\n", job_pages);
  printf("internal_fragmentation: %d\n", internal_fragmentation);
}
