#include <stdio.h>

const char* cambio(int pos_alavanca) {
    if (pos_alavanca == 1) {
        return "Ponto morto";
    } else if (pos_alavanca == 2) {
        return "Marcha re";
    } else if (pos_alavanca >= 3 && pos_alavanca <= 7) {
        switch(pos_alavanca) {
            case 3: return "Marcha 1";
            case 4: return "Marcha 2";
            case 5: return "Marcha 3";
            case 6: return "Marcha 4";
            case 7: return "Marcha 5";
        }
    }
    return "Posicao invalida";
}