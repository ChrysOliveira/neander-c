[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/_Tqfmbvi)
# Entrega Parcial 1
Chrystian Medeiros de Oliveira


## Observações
# Emulador Neander em C

Este projeto é um emulador do [Neander](https://www.inf.ufrgs.br/arq/wiki/doku.php?id=neander) escrito em C. Ele permite executar arquivos binários do Neander sem usar o software oficial.

## Funcionalidades
- Lê e executa código de máquina Neander a partir de arquivos `.mem`.
- Implementa instruções básicas do Neander.
- Exibe o estado da memória e dos registradores durante a execução.

## Instruções de Compilação
Para compilar o projeto, execute o seguinte comando no diretório do projeto:

```sh
make
```

Isso gerará um executável chamado `neander`.

## Uso
Execute o emulador com um arquivo binário Neander como argumento:

```sh
./neander <arquivo>
```

Por exemplo:

```sh
./neander multiplicacao-entrega.mem
```

## Limpar Arquivos de Compilação
Para remover os arquivos compilados, use:

```sh
make clean
```

## Estrutura de Arquivos
- `neander.c` - Arquivo fonte principal em C que implementa o emulador.
- `Makefile` - Arquivo de automação de compilação.
- Arquivos `.mem` - Programas binários de exemplo do Neander.

## Licença
Este projeto é de código aberto e gratuito para uso sob uma licença do tipo MIT.
