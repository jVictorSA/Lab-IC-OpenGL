#ifndef MATEMATICA_HPP
#define MATEMATICA_HPP

// Limita um valor entre um intervalo definido por um máximo e um mínimo.
// A função está parametrizada de forma genérica para prover mais flexibilidade.
template <typename Tipo>
Tipo clamp(Tipo valor, Tipo minimo, Tipo maximo){
    if(valor < minimo){
        return minimo;
    }else if(valor > maximo){
        return maximo;
    }

    return valor;
}

#endif