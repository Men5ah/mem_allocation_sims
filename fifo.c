#include <stdio.h>

void simulate_FIFO(int reference_string[], int n, int memory_frames) {
  int memory[memory_frames];
  int page_faults = 0;
  int oldest_page_index = 0;

  for (int i = 0; i < memory_frames; i++) {
  memory[i] = -1;
  }

  for (int i = 0; i < n; i++) {
  int page = reference_string[i];
  int page_found = 0;

  for (int j = 0; j < memory_frames; j++) {
  if (memory[j] == page) {
  page_found = 1;
  break;
  }
  }

  if (!page_found) {
  memory[oldest_page_index] = page;
  oldest_page_index = (oldest_page_index + 1) % memory_frames;
  page_faults++;
  }
  }
  
  float fault_ratio = ((float)page_faults/n*100);

  printf("FIFO Page Faults: %2f\n", fault_ratio);
}





void simulate_LRU(int reference_string[], int n, int memory_frames) {
  int memory[memory_frames];
  int last_used[memory_frames];
  int page_faults = 0;

  for (int i = 0; i < memory_frames; i++) {
  memory[i] = -1;
  last_used[i] = -1;
  }

  for (int i = 0; i < n; i++) {
  int page = reference_string[i];
  int page_found = 0;

  for (int j = 0; j < memory_frames; j++) {
  if (memory[j] == page) {
  page_found = 1;
  last_used[j] = i;
  break;
  }
  }

  if (!page_found) {
  int least_recently_used_index = 0;
  for (int j = 1; j < memory_frames; j++) {
  if (last_used[j] < last_used[least_recently_used_index]) {
  least_recently_used_index = j;
  }
  }

  memory[least_recently_used_index] = page;
  last_used[least_recently_used_index] = i;
  page_faults++;
  }
  }
  
  float fault_ratio = ((float)page_faults/n*100);
  printf("LRU Page Faults: %f\n", fault_ratio);
}

int main() {
  int reference_string[] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8};
  int n = sizeof(reference_string) / sizeof(reference_string[0]);
  int memory_frames;

  printf("Enter the number of memory frames: ");
  scanf("%d", &memory_frames);

  simulate_FIFO(reference_string, n, memory_frames);
  simulate_LRU(reference_string, n, memory_frames);

  return 0;
}