#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;


void limpaTela(){
    system("CLS");
}

string retornaPalavraAleatoria(){
        //vetor com palavras disponiveis
        string palavras[3] = {"abacaxi", "manga", "morango"};

        //gerar um numero aleatorio
        int indiceAleatorio = rand()%3;

        return palavras[indiceAleatorio];
}

void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes, string letrasJaArriscadas, string mensagem){
    cout << mensagem << "\n";
    cout << "Palavra: " << palavraComMascara << "(Tamanho: " << tamanhoDaPalavra << ")";
    cout << "\n Tentativas Restantes: " << tentativasRestantes;
    cout << "\n";

    //exibe as letras arriscadas
    int cont;
    for(cont = 0; cont < letrasJaArriscadas.size(); cont++){
        cout << letrasJaArriscadas[cont] << ", ";
    }

}

string retornaPalavraComMascara(string palavra, int tamanhoDaPalavra){


    int cont = 0;
   string palavraComMascara;
    //coloca mascara
   while(cont < tamanhoDaPalavra){
    palavraComMascara += "_";
    cont ++;
   }
    return palavraComMascara;
}

void jogarSozinho(){

   string palavra = retornaPalavraAleatoria();

   //tamanho da palavra
   int tamanhoDaPalavra = palavra.size();
    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDaPalavra);


    /// variaveis principais
    int tentativas = 0, maximoTentativas = 9;                        //numero de tentativas e erros
    char letra;                                                      // letra arriscada pelo usuario
    int cont = 0;                                                    //auxiliar para lacos de repeticao
    string letrasJaArriscadas;                                       //acumula as tentativas do jogador
    string mensagem = "bem vindo ao jogo";                           // feedback do jogador
    bool jaDigitouLetra = false, acertouLetra = false;               // Auxiliar para saber se a letra ja foi digitada


    while(palavra != palavraComMascara && maximoTentativas - tentativas > 0 ){

         limpaTela();

        //exibe o status
      exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoTentativas - tentativas, letrasJaArriscadas, mensagem);

    //le o palpite
      cout << "\nDigite uma letra: ";
      cin >> letra;



      //percorre as letras ja arriscadas
      for(cont = 0; cont< tentativas; cont++){

        if(letrasJaArriscadas[cont] == letra){

            mensagem = "Essa letra ja foi digitada! \n";
            jaDigitouLetra = true;
        }
      }



      if(jaDigitouLetra == false){




                    letrasJaArriscadas += letra;


                    //percorre a palavra real e se a letra exister muda a palavraComMascara
                    for(cont = 0; cont < tamanhoDaPalavra; cont ++){

                        // se a letra existir na palavra escondida:
                        if(palavra[cont] == letra){

                            //faz aquela letra aparece na palavra comMascara
                            palavraComMascara[cont] = palavra[cont];

                            mensagem = "voce acertou uma letra!";

                            acertouLetra = true;
                        }

                        if(acertouLetra == false){
                                mensagem = "voce errou uma letra";

                    }else{
                        mensagem = "Voce acertou uma letra";
                        acertouLetra = false;
                    }

                    // aumente uma tentativa realizada
                      tentativas++;

        }
     //reinicia auxiliares
        jaDigitouLetra = false;
        acertouLetra = false;
      }


    }
    if(palavra == palavraComMascara){
        limpaTela();
        cout << "parabens vc venceu";
    }else{
        cout << "acabaram as tentativas";
    }


    // cout <<"A palavra secreta eh " << palavra << "(tamanho da palavra:" << tamanhoDaPalavra << ")" ;
    //cout << "\nMascara: " << palavraComMascara;
}

void menuInicial(){
    //opcao escolhida pelo usuario
    int opcao = 0;

    //laco para o usuario digitar uma opcao valida
   while(opcao < 1 || opcao > 3){
    limpaTela();
    cout << "Bem vindo ao Jogo";
    cout << "\n1 - Jogar ";
    cout << "\n2 - Sobre ";
    cout << "\n3 - Sair ";
    cout << "\nEscolha uma opcao e tecle ENTER:";
    cin >> opcao;

    switch(opcao){

    case 1:
        //inicia o jogo
        cout << "Jogo iniciado \n";
        jogarSozinho();
        break;

    case 2:
        //informacoes
        cout << "Informacoes do jogo \n";
        break;
    case 3:
        //sair
        cout << "Ate mais! \n";
        break;
    }

   }

}



int main(){


    //para gerar numeros realmente aleatorios
    srand((unsigned) time(NULL));


    menuInicial();

    return 0;
}
