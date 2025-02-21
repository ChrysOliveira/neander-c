#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void print_memory(uint8_t *bytes, int size, uint8_t ac, uint8_t pc, bool z,
                  bool n) {
  size_t offset = 0;

  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  printf("AC: %03d  | PC: %03d\n", ac, pc);
  printf("Z : %s | N : %s\n", z ? "true": "false", n ? "true" : "false");

  while (offset < size) {
    printf("%08zx: ", offset);

    for (size_t i = 0; i < 16; i++) {
      if (offset + i < size)
        printf("%02x ", bytes[offset + i]);
      else
        printf("   ");
    }

    printf("\n");
    offset += 16;
  }

  offset += 16;
}

int calcula_posicao(uint8_t hex) {
  uint8_t offset = 4;
  return hex * 2 + offset;
}

int main(int argc, char const *argv[]) {

  uint8_t ac = 0, pc = 0;
  bool z = 0, n = 0;

  const char *file_name = argv[1];

  /* FILE *file = fopen("soma.mem", "rb"); */
  /* FILE *file = fopen("multiplicacao.mem", "rb"); */
  /* FILE *file = fopen("multiplicacao-negativo.mem", "rb"); */
  FILE *file = fopen(file_name, "rb");
  uint8_t bytes[516];
  fread(bytes, 1, 516, file);
  fclose(file);

  print_memory(bytes, 516, ac, pc, z, n);

  while (bytes[pc] != 0xF0) {

    switch (bytes[pc]) {
    case 0x00:
      break;
    case 0x10:
      bytes[calcula_posicao(bytes[pc + 2])] = ac;
      break;
    case 0x20:
      ac = bytes[calcula_posicao(bytes[pc + 2])];
      break;
    case 0x30:
      ac += bytes[calcula_posicao(bytes[pc + 2])];
      break;
    case 0x40:
      ac += bytes[calcula_posicao(bytes[pc + 2])] || ac;
      break;
    case 0x50:
      ac += bytes[calcula_posicao(bytes[pc + 2])] && ac;
      break;
    case 0x60:
      ac += ~ac;
      break;
    case 0x80:
      pc = calcula_posicao(bytes[pc + 2]);
      continue;
      break;
    case 0x90:
      if (n) {
        pc = calcula_posicao(bytes[pc + 2]);
        continue;
      }
      break;
    case 0xA0:
      if (z) {
        pc = calcula_posicao(bytes[pc + 2]);
        continue;
      }
      break;
    }

    if (ac == 0) {
      z = true;
    } else {
      z = false;
    }

    if (ac < 0) {
      n = true;
    } else {
      n = false;
    }

    pc += 4;
  }

  print_memory(bytes, 516, ac, pc, z, n);

  return 0;
}
