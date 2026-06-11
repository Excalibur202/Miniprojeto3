/*
	Autor: Rui
	Data de Inicio: 01-07-2022
	Email: pedro_o1992@hotmail.com
	Desc: Ficheiro Header para estruturas da lista. 
*/

#pragma once
#ifndef DADOS
#define DADOS

#include <string>
#include <fstream>


#define TAMANHO 20

//Estrutura Pessoa
typedef struct Pessoa {
	char nome[TAMANHO];
	char freguesia[TAMANHO];
	char sexo;
	int anoNascimento;
}Pessoa;

//Estrutura Lista Ligada Dupla
typedef struct ListaPessoasIndexada {
	int index;
	Pessoa pes;
	struct ListaPessoasIndexada *head;
	struct ListaPessoasIndexada *tail;
}ListaPessoasIndexada, *ListaPessoasIndexadaApt;

/*
	ASSINATURA DAS FUNCOES
*/
void Menu();
void inicializa_array();
Pessoa NovoItemNaLista();
ListaPessoasIndexadaApt AtualizarIndexLista(ListaPessoasIndexadaApt fichas);
ListaPessoasIndexadaApt MeterListaNoFim(ListaPessoasIndexadaApt fichas);
ListaPessoasIndexadaApt MeterListaNoInicio(ListaPessoasIndexadaApt fichas);
ListaPessoasIndexadaApt InserePessoaOrdenado(ListaPessoasIndexadaApt fichas, Pessoa novaPessoa, int indice);
bool RemovePessoaPeloIndice(ListaPessoasIndexadaApt fichas, int indice);
bool AlterarPessoaLista(ListaPessoasIndexadaApt fichas, int indice);
ListaPessoasIndexadaApt ProcuraPessoaIndex(ListaPessoasIndexadaApt fichas, int indice);
ListaPessoasIndexadaApt CriarListaII(ListaPessoasIndexadaApt start);
void MostraListaII(ListaPessoasIndexadaApt fichas);
void PessoaMaisVelha(ListaPessoasIndexadaApt lista);
int ContaRaparigas(ListaPessoasIndexadaApt lista);
int ContaRapazes(ListaPessoasIndexadaApt lista, std::string freg);
ListaPessoasIndexadaApt ApagarLista(ListaPessoasIndexadaApt lista);
void GravarEmFicheiro(ListaPessoasIndexadaApt lista);

#endif // !DADOS
