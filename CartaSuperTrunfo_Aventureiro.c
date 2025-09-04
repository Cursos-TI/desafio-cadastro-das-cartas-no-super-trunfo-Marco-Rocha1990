#include <stdio.h>

/*
  Desafio: Super Trunfo (nível Aventureiro)
  - Lê os dados de 2 cartas
  - Armazena em variáveis
  - Exibe tudo formatado
  - Sem if/else e sem laços
*/

int main(void) {
    /* -------- Carta 1 -------- */
    char  estado1;           // Ex.: 'A'..'H'
    char  codigo1[4];        // Ex.: "A01" (3 chars + '\0')
    char  cidade1[50];       // Nome da cidade (até 49 chars)
    int   populacao1;        // Habitantes
    float area1;             // km²
    float pib1;              // PIB (em bilhões, por ex.)
    int   pontos1;           // Pontos turísticos
    float densidade1;       // Habitantes por km²
    float pib_per_capita1;  // PIB per capita


    /* -------- Carta 2 -------- */
    char  estado2;
    char  codigo2[4];
    char  cidade2[50];
    int   populacao2;
    float area2;
    float pib2;
    int   pontos2;
    float densidade2;       // Habitantes por km²
    float pib_per_capita2; // PIB per capita


    /* ===== Entrada de dados – CARTA 1 ===== */
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Codigo (ex: A01): ");
    scanf(" %3s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", cidade1);   // lê até a quebra de linha

    printf("Populacao: ");
    scanf("%d", &populacao1);

    printf("Area (em km2): ");
    scanf("%f", &area1);

    printf("PIB (em bilhoes): ");
    scanf("%f", &pib1);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos1);

    densidade1 = (float)populacao1 / area1;  // cálculo da densidade
    pib_per_capita1 = (pib1 * 1000000000.0f) / (float)populacao1; // PIB per capita


    /* ===== Entrada de dados – CARTA 2 ===== */
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Codigo (ex: B03): ");
    scanf(" %3s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", cidade2);

    printf("Populacao: ");
    scanf("%d", &populacao2);

    printf("Area (em km2): ");
    scanf("%f", &area2);

    printf("PIB (em bilhoes): ");
    scanf("%f", &pib2);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos2);

    densidade2 = (float)populacao2 / area2;  // cálculo da densidade
    pib_per_capita2 = (pib2 * 1000000000.0f) / (float)populacao2; // PIB per capita


    /* ===== Saída formatada ===== */
    printf("\n=== Carta 1 ===\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontos1);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade1);  
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);

    printf("\n=== Carta 2 ===\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontos2);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade2);  
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);
    

    return 0;
}
