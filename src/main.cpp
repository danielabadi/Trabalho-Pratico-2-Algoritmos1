#include<bits/stdc++.h>
#include <fstream>

int knapSack(int peso, int valores[], int quantidade){ 
    int matriz[quantidade + 1][peso + 1]; 
  
    for(int i = 0; i <= quantidade; i++){ 
        for(int w = 0; w <= peso; w++){ 
            if(w < valores[i - 1]){
				matriz[i][w] = matriz[i - 1][w];
            } else{
                matriz[i][w] = std::max(matriz[i - 1][w], valores[i - 1] + matriz[i - 1][w - valores[i - 1]]); 
			}
        } 
    }
    return matriz[quantidade][peso]; 
}

int main(int argc, char* argv[]){
	std::ifstream arq;
	
	arq.open(argv[1]); 
	 if(!arq.is_open()){
		 std::cout << "Arquivo nao encontrado.";
        return 0;
    }
	
	int quantidade, soma=0, peso, resultado, resto;
	
	arq >> quantidade;
	int valores[quantidade];
	for(int i = 0; i < quantidade; i++){
		arq >> valores[i];
		soma += valores[i];
	}
	if(soma%2 == 0){
		peso = soma/2;
	} else {
		peso = soma/2 + 1; //Quando a soma é um valor ímpar, sempre pego o teto da divisão
	}
	resultado = knapSack(peso, valores, quantidade);
	resto = soma - resultado; //Como já sei o valor da soma de um subconjunto, não é necessário realizar outro knapSack, basta subtrair
	std::cout << std::abs(resultado-resto) << std::endl; //A resposta é simplesmente a diferença entre os 2 subconjuntos
	arq.close();
	return 0;
}