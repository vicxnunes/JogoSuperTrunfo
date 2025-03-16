#include <stdio.h>
#include <stdlib.h>

int main() {
    // Definição das variáveis das cidades
    char estado1, estado2;
    char codigo1[5], codigo2[5];
    char nomeCidade1[50], nomeCidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;
    float densidadePopulacional1, densidadePopulacional2;
    float pibPerCapita1, pibPerCapita2;
    float superPoder1, superPoder2;

    // Entrada de dados da primeira cidade
    printf("\n--- Cadastro da Primeira Cidade ---\n");
    printf("Digite a letra do estado: ");
    scanf(" %c", &estado1);

    printf("Digite o código da cidade: ");
    scanf("%s", codigo1);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade1);

    printf("Digite a população da cidade: ");
    scanf("%lu", &populacao1);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB da cidade (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Entrada de dados da segunda cidade
    printf("\n--- Cadastro da Segunda Cidade ---\n");
    printf("Digite a letra do estado: ");
    scanf(" %c", &estado2);

    printf("Digite o código da cidade: ");
    scanf("%s", codigo2);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("Digite a população da cidade: ");
    scanf("%lu", &populacao2);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB da cidade (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculo das métricas
    densidadePopulacional1 = populacao1 / area1;
    densidadePopulacional2 = populacao2 / area2;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;
    superPoder1 = populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapita1 + (1.0 / densidadePopulacional1);
    superPoder2 = populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 + (1.0 / densidadePopulacional2);

    int opcao1, opcao2;
    float valor1A, valor2A, valor1B, valor2B, soma1, soma2;
    int densidade1 = 0, densidade2 = 0; // Flags para tratar a comparação inversa

    // Menu para escolha do primeiro atributo
    printf("\nEscolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional (menor vence)\n6 - PIB Per Capita\n7 - Super Poder\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao1);

    switch (opcao1) {
        case 1: valor1A = populacao1; valor2A = populacao2; break;
        case 2: valor1A = area1; valor2A = area2; break;
        case 3: valor1A = pib1; valor2A = pib2; break;
        case 4: valor1A = pontosTuristicos1; valor2A = pontosTuristicos2; break;
        case 5: valor1A = densidadePopulacional1; valor2A = densidadePopulacional2; densidade1 = 1; break;
        case 6: valor1A = pibPerCapita1; valor2A = pibPerCapita2; break;
        case 7: valor1A = superPoder1; valor2A = superPoder2; break;
        default: printf("\nOpção inválida!\n"); return 1;
    }

    // Menu para escolha do segundo atributo (não pode ser igual ao primeiro)
    printf("\nEscolha o SEGUNDO atributo para comparar (diferente do primeiro):\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional (menor vence)\n6 - PIB Per Capita\n7 - Super Poder\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao2);

    if (opcao2 == opcao1) {
        printf("\nErro: O segundo atributo deve ser diferente do primeiro!\n");
        return 1;
    }

    switch (opcao2) {
        case 1: valor1B = populacao1; valor2B = populacao2; break;
        case 2: valor1B = area1; valor2B = area2; break;
        case 3: valor1B = pib1; valor2B = pib2; break;
        case 4: valor1B = pontosTuristicos1; valor2B = pontosTuristicos2; break;
        case 5: valor1B = densidadePopulacional1; valor2B = densidadePopulacional2; densidade2 = 1; break;
        case 6: valor1B = pibPerCapita1; valor2B = pibPerCapita2; break;
        case 7: valor1B = superPoder1; valor2B = superPoder2; break;
        default: printf("\nOpção inválida!\n"); return 1;
    }

    // Soma dos atributos escolhidos (inverte a soma para densidade)
    soma1 = (densidade1 ? -valor1A : valor1A) + (densidade2 ? -valor1B : valor1B);
    soma2 = (densidade1 ? -valor2A : valor2A) + (densidade2 ? -valor2B : valor2B);

    // Exibição do resultado
    printf("\n--- Resultado da Comparação ---\n");
    printf("%s: %.2f + %.2f = %.2f\n", nomeCidade1, valor1A, valor1B, soma1);
    printf("%s: %.2f + %.2f = %.2f\n", nomeCidade2, valor2A, valor2B, soma2);

    // Determinar o vencedor considerando a densidade inversa corretamente
    if (soma1 > soma2) {
        printf("\nVencedor: %s\n", nomeCidade1);
    } else if (soma2 > soma1) {
        printf("\nVencedor: %s\n", nomeCidade2);
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}