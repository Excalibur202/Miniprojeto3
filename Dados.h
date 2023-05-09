/*
	Autor: Rui
	Data de Inicio: 01-07-2022
	Email: pedro_o1992@hotmail.com
	Desc: Header File para Estruturas de Lista Ligadas. 
*/

#pragma once
#ifndef DADOS
#define DADOS

#include <string>
#include <fstream>
using namespace std;

#define TAMANHO 20

//Estrutura Pessoa
typedef struct Pessoa {
	char nome[TAMANHO];
	char freguesia[TAMANHO];
	char sexo;
	int anoNascimento;
}Pessoa;

//Estrutura Lista Ligada Simples
typedef struct ListaPessoas {
	Pessoa p;
	struct ListaPessoas *head;
}ListaPessoas, *ListaPessoasPtr;

//Estrutura Lista Ligada Dupla
typedef struct ListaPessoasIndexada {
	int index;
	Pessoa pes;
	struct ListaPessoasIndexada *head;
	struct ListaPessoasIndexada *tail;
}ListaPessoasIndexada, *ListaPessoasIndexadaApt;

//Array Global para inicializar a Lista
extern Pessoa fichas[TAMANHO];

/*
	ASSINATURA DAS FUNCOES
*/
void Menu();
void inicializa_array();
ListaPessoasPtr InserePessoaInicio(ListaPessoasPtr fichas, Pessoa pessoa);
ListaPessoasPtr CriarLista(ListaPessoasPtr start);
void MostraLista(ListaPessoasPtr fichas);
void MaisVelho(ListaPessoasPtr fichas);
ListaPessoasIndexadaApt AtualizarIndexLista(ListaPessoasIndexadaApt fichas);
ListaPessoasIndexadaApt MeterListaNoFim(ListaPessoasIndexadaApt fichas);
ListaPessoasIndexadaApt InserePessoaOrdenado(ListaPessoasIndexadaApt fichas, Pessoa novaPessoa, int indice);
bool RemovePessoaPeloIndice(ListaPessoasIndexadaApt fichas, int indice);
bool AlterarPessoaLista(ListaPessoasIndexadaApt fichas, int indice);
ListaPessoasIndexadaApt ProcuraPessoaIndex(ListaPessoasIndexadaApt fichas, int indice);
ListaPessoasIndexadaApt CriarListaII(ListaPessoasIndexadaApt start);
void MostraListaII(ListaPessoasIndexadaApt fichas);
void PessoaMaisVelha(ListaPessoasIndexadaApt lista);
int ContaRaparigas(ListaPessoasIndexadaApt lista);
int ContaRapazes(ListaPessoasIndexadaApt lista, string freg);
ListaPessoasIndexadaApt ApagarLista(ListaPessoasIndexadaApt lista);
//bool GravarListaFicheiro(ListaPessoasIndexadaApt lista, ofstream& ficheiro, string nomeFicheiro);

#endif // !DADOS
