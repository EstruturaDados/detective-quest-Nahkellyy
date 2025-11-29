#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash
// Este código inicial serve como base para o desenvolvimento das estruturas de navegação, pistas e suspeitos.
// Use as instruções de cada região para desenvolver o sistema completo com árvore binária, árvore de busca e tabela hash.


// Struct Sala: representa cada cômodo da mansão

typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;


// criarSala
Sala* criarSala(const char *nome) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    if (!nova) {
        printf("Erro de alocação! Encerrando...\n");
        exit(1);
    }

    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;

    return nova;
}

// explorarSalas()

void explorarSalas(Sala *atual) {
    char escolha;

    printf("\n=== EXPLORAÇÃO DA MANSÃO ===\n");

    while (1) {
        printf("\nVocê está em: %s\n", atual->nome);

        // Caso encontre um nó-folha
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Este cômodo não possui mais caminhos. Fim da exploração!\n");
            break;
        }

        printf("Escolha seu caminho:\n");
        if (atual->esquerda != NULL) printf("  e - Ir para a sala à ESQUERDA\n");
        if (atual->direita != NULL) printf("  d - Ir para a sala à DIREITA\n");
        printf("  s - Sair da exploração\n");
        printf("Opção: ");

        scanf(" %c", &escolha);

        if (escolha == 'e' && atual->esquerda != NULL) {
            atual = atual->esquerda;
        }
        else if (escolha == 'd' && atual->direita != NULL) {
            atual = atual->direita;
        }
        else if (escolha == 's') {
            printf("\nExploração encerrada pelo jogador.\n");
            break;
        }
        else {
            printf("Opção inválida ou caminho inexistente! Tente novamente.\n");
        }
    }
}

int main() {
    // Criando as salas principais
    Sala *hall = criarSala("Hall de Entrada");
    Sala *salaEstar = criarSala("Sala de Estar");
    Sala *biblioteca = criarSala("Biblioteca");
    Sala *cozinha = criarSala("Cozinha");
    Sala *jardim = criarSala("Jardim");
    Sala *adega = criarSala("Adega");

    hall->esquerda = salaEstar;
    hall->direita = biblioteca;

    salaEstar->esquerda = cozinha;
    salaEstar->direita = jardim;

    biblioteca->esquerda = adega;

    // Início da exploração
    explorarSalas(hall);

    return 0;
}


