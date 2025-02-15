#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {

  uint8_t ac = 0b0, pc = 4;
  bool z = 0, n = 0;

  printf("%02x", ac);

  FILE *file = fopen("soma.mem", "rb");

  uint8_t bytes[516];

  fread(bytes, 1, 516, file);

  fclose(file);

  /* for (int i = 0; i < 516; i += 2) { */
  /*   if (i != 0 && i % 16 == 0) { */
  /*     printf("\n"); */
  /*   } */
  /*   printf("[%03d] %02x ", i, bytes[i]); */
  /* } */

  int aa = -1;
  while (bytes[pc] != 0xf0) {
    switch (bytes[pc]) {
    case 0x10:

      bytes[bytes[pc + 2]] = ac;
      break;
    case 0x20:
      break;
    case 0x30:
      break;
    }

    for (int i = 0; i < 516; i += 2) { if (i != 0 && i % 16 == 0) {
        printf("\n");
      }
      printf("[%03d] %02x ", i, bytes[i]);
    }

    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    


    pc += 2;
    aa++;
  }
  printf("Deu bosta\n");

  printf("\n");

  return 0;
}
