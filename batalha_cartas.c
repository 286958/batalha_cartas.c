#include <stdio.h>

typedef struct {
    char estado[3];
    char codigo[4];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Funcao para calcular atributos derivados
void calcular_atributos(Carta *carta) {
    carta->densidade_populacional = (float)carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib * 1000000000.0 / (float)carta->populacao; 
    // PIB em bilhoes -> converter para numero inteiro antes de dividir pela populacao
    carta->super_poder =
        (float)carta->populacao +
        carta->area +
        carta->pib +
        (float)carta->pontos_turisticos +
        carta->pib_per_capita +
        (1.0f / carta->densidade_populacional); // inverso da densidade
}

// Funcao para imprimir carta
void imprimir_carta(Carta c) {
    printf("\n--- Carta %s (%s) ---\n", c.nome, c.codigo);
    printf("Estado: %s\n", c.estado);
    printf("Populacao: %lu\n", c.populacao);
    printf("Area: %.2f km2\n", c.area);
    printf("PIB: %.2f bilhoes\n", c.pib);
    printf("Pontos Turisticos: %d\n", c.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km2\n", c.densidade_populacional);
    printf("PIB per Capita: %.2f\n", c.pib_per_capita);
    printf("Super Poder: %.2f\n", c.super_poder);
}

// Funcao para comparar cartas
void comparar_cartas(Carta c1, Carta c2) {
    printf("\n--- Comparacao de Cartas ---\n");

    printf("Populacao: Carta 1 venceu (%d)\n", c1.populacao > c2.populacao);
    printf("Area: Carta 1 venceu (%d)\n", c1.area > c2.area);
    printf("PIB: Carta 1 venceu (%d)\n", c1.pib > c2.pib);
    printf("Pontos Turisticos: Carta 1 venceu (%d)\n", c1.pontos_turisticos > c2.pontos_turisticos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", c1.densidade_populacional < c2.densidade_populacional);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", c1.pib_per_capita > c2.pib_per_capita);
    printf("Super Poder: Carta 1 venceu (%d)\n", c1.super_poder > c2.super_poder);
}

int main() {
    Carta c1, c2;

    // Entrada dos dados da carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Estado (ex: SP): ");
    scanf("%s", c1.estado);
    printf("Codigo: ");
    scanf("%s", c1.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", c1.nome);
    printf("Populacao: ");
    scanf("%lu", &c1.populacao);
    printf("Area (km2): ");
    scanf("%f", &c1.area);
    printf("PIB (em bilhoes): ");
    scanf("%f", &c1.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &c1.pontos_turisticos);

    // Entrada dos dados da carta 2
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado (ex: RJ): ");
    scanf("%s", c2.estado);
    printf("Codigo: ");
    scanf("%s", c2.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", c2.nome);
    printf("Populacao: ");
    scanf("%lu", &c2.populacao);
    printf("Area (km2): ");
    scanf("%f", &c2.area);
    printf("PIB (em bilhoes): ");
    scanf("%f", &c2.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &c2.pontos_turisticos);

    // Calcula atributos derivados
    calcular_atributos(&c1);
    calcular_atributos(&c2);

    // Exibir cartas
    imprimir_carta(c1);
    imprimir_carta(c2);

    // Comparar cartas
    comparar_cartas(c1, c2);

    return 0;
}
