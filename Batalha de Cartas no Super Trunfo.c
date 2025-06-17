#include <stdio.h>

struct Carta {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;   
    float area;
    float pib;                     
    int pontosTuristicos;

    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
};

int main() {
    struct Carta carta1, carta2;

    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado);

    printf("Código da carta (ex: A01): ");
    scanf("%s", carta1.codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);

    printf("População: ");
    scanf("%lu", &carta1.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);

    printf("Código da carta (ex: A01): ");
    scanf("%s", carta2.codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);

    printf("População: ");
    scanf("%lu", &carta2.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = (carta1.pib * 1000000000) / carta1.populacao;
    
    carta1.superPoder = (float)carta1.populacao + carta1.area + carta1.pib + 
                        (float)carta1.pontosTuristicos + carta1.pibPerCapita + (1.0f / carta1.densidadePopulacional);

    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = (carta2.pib * 1000000000) / carta2.populacao;
    carta2.superPoder = (float)carta2.populacao + carta2.area + carta2.pib + 
                        (float)carta2.pontosTuristicos + carta2.pibPerCapita + (1.0f / carta2.densidadePopulacional);

    int vencePopulacao = carta1.populacao > carta2.populacao ? 1 : 0;
    int venceArea = carta1.area > carta2.area ? 1 : 0;
    int vencePIB = carta1.pib > carta2.pib ? 1 : 0;
    int vencePontosTuristicos = carta1.pontosTuristicos > carta2.pontosTuristicos ? 1 : 0;
    int venceDensidade = carta1.densidadePopulacional < carta2.densidadePopulacional ? 1 : 0;
    int vencePIBperCapita = carta1.pibPerCapita > carta2.pibPerCapita ? 1 : 0;
    int venceSuperPoder = carta1.superPoder > carta2.superPoder ? 1 : 0;

    printf("\nComparação de Cartas:\n\n");

    printf("População: Carta 1 venceu (%d)\n", vencePopulacao);
    printf("Área: Carta 1 venceu (%d)\n", venceArea);
    printf("PIB: Carta 1 venceu (%d)\n", vencePIB);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", vencePontosTuristicos);
    printf("Densidade Populacional: Carta 2 venceu (%d)\n", venceDensidade ? 1 : 0);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", vencePIBperCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", venceSuperPoder);

    return 0;
}