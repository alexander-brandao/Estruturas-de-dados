//
//  main.cpp
//  ListasEncadeadas2
//
//  Created by Alex Costa on 12/09/2020.
//  Copyright © 2020 Alex Costa. All rights reserved.
//

#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>


using namespace std;
//----------------- funcoes ----------------------//

// estrutura com 2 parametros e um ponteiro
struct pessoa{
    string nome;
    int rg;
    struct pessoa *proximo;
};
//------------------------------------//

// funcao que retorna o tamanho da Lista
int retornaTamanho(pessoa *ponteiroEncadeada){
    
    
    if (ponteiroEncadeada->nome == "") {
        return 0;
    }
    
    //Tamanho da Lista
    int tamanho = 0;
    
    //ponteiro cursor auxiliar
    pessoa *p = ponteiroEncadeada;
    
    while (p != NULL) {
        
        //atualiza o cursor auxiliar
        p = p->proximo;
        
        //contador de tamanho
        tamanho++;
    }
    
    //returna a variavel tamanho para a funcao
    return tamanho;
}
//-------------------------------------//

// funcao que imprime a lista na tela
void imprimeEncadeada(pessoa *ponteiroEncadeada){
    
    //ponteiro cursor auxiliar
    pessoa *p = ponteiroEncadeada;
    
    while (p != NULL) {
        
        cout << p->nome << ", rg: " << p->rg << "\n";
        
        p = p->proximo;
    }
}

//--------------------------------------//

//funcao que adicionar um node no inicio da Lista
void adcComecoEncadeada(pessoa *&ponteiroEncadeada,string nome, int rg){
    
    //cria uma nova estrutura
    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    
    
    //tratamento de erro para lista vazia
    if (ponteiroEncadeada->nome == "") {
        novoValor->proximo = NULL;
    }else{
        novoValor->proximo = ponteiroEncadeada;
    }
    
    // direciona o ponteiro principal para novoValor
    ponteiroEncadeada = novoValor;
    
}
//----------------------------------------------//
void adcFimEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg){
    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;
    
    //ponteiro cursor auxiliar
    pessoa *p = ponteiroEncadeada;
    
    while (p != NULL) {
        
        // quando chega ao ultimo elemento, faz ele apontar para o proximo valor
        if(p->proximo == NULL){
            p->proximo = novoValor;
            return;
        }
        //atualiza o cursor;
        p = p->proximo;
    }
}
//---------------------------------------------//

void adcPosicaoEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg, int posicao){
    
    //cria uma nova estrutura
    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;
    
    pessoa *p = ponteiroEncadeada;
    
    //contador de possicoes
    int cont = 0;
    while (cont <= posicao) {
        
        //quando chega uma posicao antes da posicao desejada
        if (cont == posicao -1) {
            
            //ponteiro auxiliar
            pessoa *aux = new pessoa;
            
            //armazena o proximo valor
            aux->proximo = p->proximo;
            
            //coloca um novo valor como proximo do escolhido
            p->proximo = novoValor;
            
            //faz com que o novo valor aponte para o proximo
            novoValor->proximo = aux->proximo;
            
            free(aux);
        }
        //atualiza o cursor 
        p = p->proximo;
        cont++;
    }
}
//-------------------------------------------//

void removeIncicioEncadeada(pessoa *&ponteiroEncadeada){
    
    // se so existir um membro na lista
    if (ponteiroEncadeada->proximo == NULL) {
        
        
        //cria uma nova estrutura
        pessoa *novoValor = new pessoa;
        novoValor->nome = "";
        novoValor->rg = 0;
        novoValor->proximo = NULL;
        
        ponteiroEncadeada = novoValor;
    }else{
        
    //faz o ponteiro inicial apontar para o proximo valor
    ponteiroEncadeada = ponteiroEncadeada->proximo;
    }
}

//-------------------------------------------//

void removeFimEncadeada(pessoa *&ponteiroEncadeada){
    
    //auxiliares
    pessoa *p = new pessoa;
    pessoa *aux = new pessoa;
    
    //ponteiro cursor auxiliar
    p = ponteiroEncadeada;
    
    while (p->proximo != NULL) {
        aux = p;
        p = p->proximo;
    }
    // muda o final da lis para o penultimo elemento
    aux->proximo = NULL;
}

//-------------------------------------------//
void removePosicaoEncadeada(pessoa *&ponteiroEncadeada, int posicao){
    
    //ponteiro cursor auxiliar
    pessoa *p = ponteiroEncadeada;
    
    //contador de posicoes
    int cont = 0;
    
    while (cont <=0) {
        
        
        if (cont == posicao -1) {
            //cria um auxiliar
            pessoa *aux = new pessoa;
            
            //auxiliar recebe o elemento que sera eliminado
            aux = p->proximo;
            
            p->proximo = aux->proximo;
            free(aux);
        }
        //passa o cursor para o proximo elemento
        p = p->proximo;
        
        //regista uma movimentacao
        cont ++;
    }
}

//------------------------------------------//

string retornaNomeEncadeada(pessoa *&ponteiroEncadeada, int rg){
    
    string nome;
    //ponteiro cursor auxiliar
    pessoa *p = ponteiroEncadeada;
    
    //percorre a lista
    while (p != NULL) {
        
        if (p->rg == rg) {
            
            nome = p->nome;
            
            return nome;
        }
        p = p->proximo;
        
    }
    return nome;
}
int main() {
    //variavel
    int funcaoDesejada =1;
    
    // cria o ponteiro principal para apontar para o primeiro elemento da lista encadeada
    pessoa *ponteiroEncadeada = new pessoa;
    ponteiroEncadeada->nome = "";
    ponteiroEncadeada->rg = 0;
    ponteiroEncadeada->proximo = NULL;
    
     /*
    //cria primeiro elemento da lista
    pessoa *novoPrimeiroValor = new pessoa;
    novoPrimeiroValor->nome = "john";
    novoPrimeiroValor->rg = 1234;
    novoPrimeiroValor->proximo = NULL;
    
    // aponta o ponteiro pricipal para o primeiro elemento
    ponteiroEncadeada = novoPrimeiroValor;
    
    //cria segundo elemento da lista
    pessoa *novoSegundoValor = new pessoa;
    novoSegundoValor->nome = "Carol";
    novoSegundoValor->rg = 4321;
    novoSegundoValor->proximo = NULL;
    
    //aponta o ponteiro prncipal para o segundo valor
    novoPrimeiroValor->proximo = novoSegundoValor;
    */
    
    //menu
    while (funcaoDesejada < 9 && funcaoDesejada > 0) {
    
        
    cout << "\n ****** Operacoes: ****** \n";
    cout << "\n 1 - Insercao de um node no inicio da Lista \n";
    cout << "\n 2 - Insercao de um node no fim da Lista \n";
    cout << "\n 3 - Insercao de um node na posicao N \n";
    cout << "\n 4 - Retirar um node do inicio da Lista\n";
    cout << "\n 5 - Retirar um node do fim da Lista\n";
    cout << "\n 6 - Retirar um node da posicao N \n";
    cout << "\n 7 - Procurar um node com o campo RG \n";
    cout << "\n 8 - Imprimir a Lista \n";
    cout << "\n 9 - Sair do Sistema \n";
    cout << "\n Tamanho da Lista: " << retornaTamanho(ponteiroEncadeada) << "\n";
    
        // condicoes para imprimir a lista
        if (retornaTamanho(ponteiroEncadeada) == 0) {
            cout << "\n Lista vazia";
        }else{
            imprimeEncadeada(ponteiroEncadeada);
        }
    
    cout << "\n\n\n";
        
    cout << "\n Escolha um numero e pressione ENTER: \n";
    
    
    //variaveis para valores novos
        string nome;
        int rg, posicao;
        
    cin >> funcaoDesejada;
        
        switch (funcaoDesejada) {
            case 1:
                cout << "\n Funcao escolhida: 1 - Insercao de um node no inicio da Lista \n";
                
                //lendo valores do usuario
                cout << "Digite o nome: \n";
                cin >> nome;
                cout << "Digite RG: \n";
                cin >> rg;
                
                adcComecoEncadeada(ponteiroEncadeada,nome,rg);
                
                break;
            case 2:
                cout << "\n Funcao escolhida: 2 - Insercao de um node no fim da Lista \n";
                
                //lendo valores do usuario
                cout << "Digite o nome: \n";
                cin >> nome;
                cout << "Digite RG: \n";
                cin >> rg;
                
                if (retornaTamanho(ponteiroEncadeada) == 0) {
                    adcFimEncadeada(ponteiroEncadeada, nome, rg);
                }else{
                adcFimEncadeada(ponteiroEncadeada,nome,rg);
                }
                
                break;
            case 3:
                cout << "\n Funcao escolhida: 3 - Insercao de um node na posicao N \n";
                
                //lendo valores do usuario
                cout << "Digite a posicao: \n";
                cin >> posicao;
                cout << "Digite o nome: \n";
                cin >> nome;
                cout << "Digite RG: \n";
                cin >> rg;
              
                if(posicao == 0){
                    adcComecoEncadeada(ponteiroEncadeada, nome, rg);
                }else if(posicao == retornaTamanho(ponteiroEncadeada)-1){
                    adcFimEncadeada(ponteiroEncadeada, nome, rg);
                }else {
                    adcPosicaoEncadeada(ponteiroEncadeada, nome, rg, posicao);
                }
                
                
                break;
            case 4:
                cout << "\n Funcao escolhida: 4 - Retirar um node do inicio da Lista \n";
                
                removeIncicioEncadeada(ponteiroEncadeada);
                break;
            case 5:
                cout << "\n Funcao escolhida: 5 - Retirar um node do fim da Lista\n \n";
                
                if (retornaTamanho(ponteiroEncadeada) == 1) {
                    removeIncicioEncadeada(ponteiroEncadeada);
                }else{
                    removeFimEncadeada(ponteiroEncadeada);
                }
                
                
                break;
            case 6:
                cout << "\n Funcao escolhida: 6 - Retirar um node da posicao N \n";
                
                cout << "\n Digite a posicao: ";
                cin >> posicao;
                
                if (posicao == 0) {
                    
                    removeIncicioEncadeada(ponteiroEncadeada);
                }else if(posicao == retornaTamanho(ponteiroEncadeada) -1){
                    removeFimEncadeada(ponteiroEncadeada);
                }else{
                    removePosicaoEncadeada(ponteiroEncadeada, posicao);
                }
                
                break;
            case 7:
                cout << "\n Funcao escolhida: 7 - Procurar um node com o campo RG \n";
                
                cout << "digite o RG: ";
                cin >> rg;
                
                cout << "O nome do rg"<< rg << "Eh" << retornaNomeEncadeada(ponteiroEncadeada,rg);
                break;
            case 8:
                cout << "\n Funcao escolhida: 8 - Imprimir a Lista \n";
                
                imprimeEncadeada(ponteiroEncadeada);
                break;
            case 9:
                cout << "\n Funcao escolhida: 9 - Sair do Sistema \n";
                break;
                
                
                
            default:
                break;
        }
    }
    return 0;
}
