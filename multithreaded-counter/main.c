#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int counter(FILE *_file) {
  int words;
  int character;
  char c;

  words = 0;
  while (!feof(_file)) {
    while ((c = fgetc(_file)) != EOF) {
      if (c == ' ' || c == '\n') {
        words++;
      }
    }
  }

  return words;
}

void *file_parser(char *filename) {
  FILE *fp;
  fp = fopen(filename, "r");

  int words = counter(fp);
  printf("%d\n", words);

  fclose(fp);

  return NULL;
}

// Para rodar .main[file1,...]
int main(int argc, char *argv[]) {
    if (argc < 2) {
      printf("Nenhum arquivo passado como argumento.");
      return 1;
    }

    pthread_t t[argc-1];

    for (int i=1; i < argc; i++) { pthread_create(&t[i-1], NULL, (void *)file_parser, argv[i]); }
    for (int i=1; i < argc; i++) { pthread_join(t[i-1], NULL); }

    return 0;
}
