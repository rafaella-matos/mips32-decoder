#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *inFile, *outFile;
  unsigned int ir;
  // assembly decod;

  inFile = fopen(argv[1], "r");
  outFile = fopen(argv[2], "w");

  if (inFile == NULL || outFile == NULL){
      printf("Could not open file");
      return 1;
  }

	size_t len = 32; // tamanho da linha
	char *linha = malloc(len);

	// Recupera cada linha do arquivo e decodifica
	while (getline(&linha, &len, inFile) > 0) {
    decodificar(linha);
    // fprintf(outFile, decodificar(linha));
	}

  fclose(outFile);
  fclose(inFile);

  return 0;
}