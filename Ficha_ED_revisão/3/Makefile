# Nome do arquivo de saída
OUTPUT = ex3_pont

# Compilador
CC = gcc

# Arquivo fonte
SOURCE = ex3_pont.c

# Regra padrão
all:
    $(CC) $(SOURCE) -o $(OUTPUT)

# Regra para executar o programa
run: all
    ./$(OUTPUT)

# Regra para limpar os arquivos de saída
clean:
    rm -f $(OUTPUT)