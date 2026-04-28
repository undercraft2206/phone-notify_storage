#include <stdio.h>
#include <stdlib.h>

int main(void){
  FILE *tmp = fopen("tempo", "w");
  char storage[50];
  char storage_used[50];
  char storage_left[50];
  char percentage[50];
  system("df -H / > tempo && clear");
  fclose(tmp);
  int a = 1;
  fopen("tempo", "r");
  fscanf(tmp, "%s", &storage);
start:
  if(a != 11){
    a = a+1;
    fscanf(tmp, "%s", &storage);
    goto start;
  }
  fscanf(tmp, "%s", &storage_used);
  fscanf(tmp, "%s", &storage_left);
  fscanf(tmp, "%s", &percentage);
  char command[1000];
  sprintf(command, "curl -d \"Your server started !take a look to you storage !\npercentage: %s, storage: %s/%s, storage left: %s\" [IP]:[PORT]/[USER]", percentage, storage_used, storage, storage_left);
  system(command);
  system("clear");
  remvoe("tempo");
  return 0;
}
