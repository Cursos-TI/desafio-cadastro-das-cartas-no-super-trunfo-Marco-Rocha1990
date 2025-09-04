#include <stdio.h>

/*
  Desafio: Super Trunfo (nível Mestre)
 - Lê duas cartas (população como unsigned long int)
  - Calcula densidade populacional e PIB per capita
  - Calcula "Super Poder"
  - Compara atributo a atributo (imprime 1 se Carta 1 vence, 0 se Carta 2 vence)
*/

typedef struct {
  
    /* -------- Carta 1 -------- */
    char  estado;                     // Ex.: 'A'..'H'
    char  codigo[4];                 // Ex.: "A01" (3 chars + '\0')
    char  cidade[50];               // Nome da cidade (até 49 chars)
    unsigned long int populacao;   // Habitantes
    float area;                   // km²
    float pib;                   // PIB (em bilhões, por ex.)
    int   pontos;               // Pontos turísticos
    
                    // Calculados:
    float superPoder;        // Variável extra para desafio
    float densidade;        // Habitantes por km²     
    float pibPerCapita;    // PIB per capita

} Carta;

 static const float BILHAO = 1000000000.0f;

 void lerCarta(Carta* c, int idx) {
    printf("\n=== Cadastro da Carta %d ===\n", idx);
    printf("Estado (A-H): ");
    scanf(" %c", &c->estado);

    printf("Codigo (ex: A01): ");
    scanf(" %3s", c->codigo);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", c->cidade);

    printf("Populacao (inteiro nao negativo): ");
    scanf(" %lu", &c->populacao);

    printf("Area (em km2): ");
    scanf(" %f", &c->area);

    printf("PIB (em bilhoes de reais): ");
    scanf(" %f", &c->pib);

    printf("Numero de Pontos Turisticos: ");
    scanf(" %d", &c->pontos);
 }


    void calcularAtributosDerivados(Carta* c) {
    // densidade: pop / area (protege contra area zero)
    c->densidade = (c->area > 0.0f) ? ((float)c->populacao / c->area) : 0.0f;

    // PIB per capita: (PIB em bilhoes -> reais) / populacao (protege contra pop zero)
    c->pibPerCapita = (c->populacao > 0UL)
        ? ((c->pib * BILHAO) / (float)c->populacao)
        : 0.0f;

    // Super Poder:
    // soma de: populacao + area + pib + pontos + pibPerCapita + (1/densidade)
    // (elenco conversões explícitas para ficar claro)
    float invDensidade = (c->densidade > 0.0f) ? (1.0f / c->densidade) : 0.0f;

    c->superPoder =
        (float)c->populacao +            // pode dominar a soma; é por design do enunciado
        c->area +
        c->pib +                         // em bilhões
        (float)c->pontos +
        c->pibPerCapita +                // em reais
        invDensidade;                    // inverso da densidade
}

void imprimirCarta(const Carta* c, int idx) {
    printf("\n=== Carta %d ===\n", idx);
    printf("Estado: %c\n", c->estado);
    printf("Codigo: %s\n", c->codigo);
    printf("Nome da Cidade: %s\n", c->cidade);
    printf("Populacao: %lu\n", c->populacao);
    printf("Area: %.2f km2\n", c->area);
    printf("PIB: %.2f bilhoes de reais\n", c->pib);
    printf("Numero de Pontos Turisticos: %d\n", c->pontos);
    printf("Densidade Populacional: %.2f hab/km2\n", c->densidade);
    printf("PIB per Capita: %.2f reais\n", c->pibPerCapita);
    printf("Super Poder: %.2f\n", c->superPoder);
}

int main(void) {
    Carta c1, c2;

    // Entrada
    lerCarta(&c1, 1);
    lerCarta(&c2, 2);

    // Cálculos derivados
    calcularAtributosDerivados(&c1);
    calcularAtributosDerivados(&c2);

    // Exibição das cartas com os cálculos
    imprimirCarta(&c1, 1);
    imprimirCarta(&c2, 2);

    // Comparações (1 => Carta 1 venceu, 0 => Carta 2 venceu)
    // Regra especial: densidade MENOR vence, todos os outros MAIOR vence.
    int venceuPop       = (c1.populacao   > c2.populacao);
    int venceuArea      = (c1.area        > c2.area);
    int venceuPib       = (c1.pib         > c2.pib);
    int venceuPontos    = (c1.pontos      > c2.pontos);
    int venceuDensidade = (c1.densidade   < c2.densidade); // menor vence
    int venceuPibCapita = (c1.pibPerCapita> c2.pibPerCapita);
    int venceuSuper     = (c1.superPoder  > c2.superPoder);

    printf("\n=== Comparacao de Cartas ===\n");
    printf("Populacao: Carta 1 venceu (%d)\n", venceuPop);
    printf("Area: Carta 1 venceu (%d)\n", venceuArea);
    printf("PIB: Carta 1 venceu (%d)\n", venceuPib);
    printf("Pontos Turisticos: Carta 1 venceu (%d)\n", venceuPontos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", venceuDensidade);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", venceuPibCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", venceuSuper);

    return 0;
}
