# Emulador Neander em C

Aluno: Chrystian Medeiros de Oliveira

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
