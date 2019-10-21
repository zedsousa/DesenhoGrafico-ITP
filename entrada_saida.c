#include "entrada_saida.h"

void ImprimeTelaDeOpcoes(){
    printf("1 - Inserir um nome\n");
    printf("2 - Listar nomes e alturas\n");
    printf("3 - Listar pessoas mais velhas\n");
    printf("4 - Gravar em novo arquivo\n");
    printf("5 - Adicionar em arquivo existente\n");
    printf("6 - Recuperar dados de um arquivo\n");
    printf("7 - Sair\n");

}

int EscolheOpcao(){
    int r;
    scanf("%d", &r);
    return r;
}

void LePessoaDeTeclado(Pessoa *p){
    printf("Entre com o nome: ");
    scanf("%s", p->nome);
    printf("Entre com a altura: ");
    scanf("%f", &p->altura);
    printf("Entre com a data de nascimento (DD MM AAAA): ");
    scanf("%d %d %d", &p->nascimento.dia, &p->nascimento.mes, &p->nascimento.ano);
    return;
}



void ImprimeTodasAsPessoas(Pessoa *povo, int qtdPessoas){
    int i;
    printf("Imprimindo todas as %d pessoas: \n", qtdPessoas);
    for(i=0;i<qtdPessoas;i++){
        printf("Posiçao %d:\n", i);
        printf("\t\tNome: %s\n", povo[i].nome);
        printf("\t\tAltura: %.2f\n", povo[i].altura);
        printf("\t\tData de Nascimento: %02d/%02d/%04d\n", povo[i].nascimento.dia, povo[i].nascimento.mes, povo[i].nascimento.ano);
    }
}

void LeDataDeTeclado(Data *d){
    printf("Entre com uma data (DD MM AAAA): ");
    scanf("%d %d %d", &d->dia, &d->mes, &d->ano);
    return;
}

void ImprimeMaisVelhos(Pessoa *povo, int qtdPessoas, Data d){
    int i, maisVelho=0;
    printf("Lista das Pessoas mais velhas que a data %d/%02d/%d\n", d.dia, d.mes, d.ano);
    for(i=0;i<qtdPessoas;i++){
        maisVelho = 0;
        if(povo[i].nascimento.ano<d.ano){//eh mais velho ou igual
            maisVelho = 1;
        }
        else{
            if(povo[i].nascimento.ano==d.ano && povo[i].nascimento.mes<d.mes){
                maisVelho = 1;
            }
            else{
                if(povo[i].nascimento.mes==d.mes && povo[i].nascimento.dia<d.dia){    
                    maisVelho = 1;
                }
            }
        }
        if(maisVelho){
            printf("Posiçao %d:\n", i);
            printf("\t\tNome: %s\n", povo[i].nome);
            printf("\t\tAltura: %.2f\n", povo[i].altura);
            printf("\t\tData de Nascimento: %02d/%02d/%04d\n", povo[i].nascimento.dia, povo[i].nascimento.mes, povo[i].nascimento.ano);
        }
    }

}
