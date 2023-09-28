#include "Arvore.h"
#include <iostream>

ArvoreBinaria::ArvoreBinaria()
{
raiz = NULL;
}

void ArvoreBinaria::Insere(TipoItem item){
InsereRecursivo(raiz,item);
}

void ArvoreBinaria::InsereRecursivo(TipoNo* &p, TipoItem item){
if(p==NULL){
p = new TipoNo();
p->item = item;
}
else{
if(item.GetChave() < p->item.GetChave())
InsereRecursivo(p->esq, item);
else
InsereRecursivo(p->dir, item);
}
}

void ArvoreBinaria::PreOrdem(TipoNo *p){
if(p!=NULL){
p->item.Imprime();
PreOrdem(p->esq);
PreOrdem(p->dir);
}
}

void ArvoreBinaria::InOrdem(TipoNo *p){
if(p!=NULL){
InOrdem(p->esq);
p->item.Imprime();
InOrdem(p->dir);
}
}

void ArvoreBinaria::PosOrdem(TipoNo *p){
if(p!=NULL){
PosOrdem(p->esq);
PosOrdem(p->dir);
p->item.Imprime();
}
}

void ArvoreBinaria::CaminhaNivel(){
FilaArranjo F; // fila de apontadores para nos
TipoNo *p;
F.Enfileira(raiz);
while(!F.Vazia()) {
p = F.Desenfileira();
if(p!=NULL) {
p->Item.Imprime();
F.Enfileira(p->esq);
F.Enfileira(p->dir);
}
}
}

void ArvoreBinaria::Limpa(){
ApagaRecursivo(raiz);
raiz = NULL;
}

void ArvoreBinaria::ApagaRecursivo(TipoNo *p){
if(p!=NULL){
ApagaRecursivo(p->esq);
ApagaRecursivo(p->dir);
delete p;
}
}

ArvoreBinaria::~ArvoreBinaria()
{
Limpa();
}