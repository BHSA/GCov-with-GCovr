//Suíte de Testes para cobertura de código com gcov/gcvr
#include <stdio.h>

const char* cambio(int pos_alavanca);

int main() {
    printf("=== Testes da funcao cambio ===\n\n");
    
    // Ponto Morto
    printf("Teste 1 - Posicao 1: %s\n", cambio(1));
    
    // Marcha ré
    printf("Teste 2 - Posicao 2: %s\n", cambio(2));
    
    // Marchas 1-5
    printf("Teste 3 - Posicao 3: %s\n", cambio(3));
    printf("Teste 4 - Posicao 4: %s\n", cambio(4));
    printf("Teste 5 - Posicao 5: %s\n", cambio(5));
    printf("Teste 6 - Posicao 6: %s\n", cambio(6));
    printf("Teste 7 - Posicao 7: %s\n", cambio(7));
    
    // Posição inválida (teste para pos_alavanca < 1)
    printf("Teste 8 - Posicao 0: %s\n", cambio(0));
    
    // Posição inválida (teste para pos_alavanca > 1)
    printf("Teste 9 - Posicao 8: %s\n", cambio(8));
    
    // Posição inválida (negativa)
    printf("Teste 10 - Posicao -1: %s\n", cambio(-1));
    
    printf("\n=== Fim dos testes ===\n");
    
    return 0;
}