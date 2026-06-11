/*
	Autor: Rui
	Data de Inicio: 01-07-2022
	Email: pedro_o1992@hotmail.com
	Desc: Funções auxiliares
*/

#include <iostream>
#include "Dados.h"
using namespace std;

Pessoa fichas[TAMANHO];

// Inicializar array de Pessoas de forma a inicializar uma lista
void inicializa_array()
{
	fichas[0] = { "Ana", "Maximinos", 'F', 1980 };
	fichas[1] = { "Bela", "Gualtar", 'F', 1980 };
	fichas[2] = { "Carlos", "Lomar", 'F', 1982 };
	fichas[3] = { "Carlota", "Lomar", 'M', 1981 };
	fichas[4] = { "Daniel", "Cividade",	'M', 1980 };
	fichas[5] = { "Diogo", "Lamaceiros", 'M', 1980 };
	fichas[6] = { "Elvira", "Maximinos", 'M', 1980 };
	fichas[7] = { "Fernanda", "Ferreiros", 'F', 1977 };
	fichas[8] = { "Fernando", "Maximinos", 'F', 1977 };
	fichas[9] = { "Gilherme", "Cividade", 'M', 1983 };
	fichas[10] = { "Hilda", "Cabreira",	 'M', 1989 };
	fichas[11] = { "Josildo", "Cividade", 'F', 1980 };
	fichas[12] = { "Josecas", "Gualtar", 'M', 1981 };
	fichas[13] = { "Maria", "Cividade", 'M', 1982 };
	fichas[14] = { "Anabela", "Gualtar", 'F', 1975 };
	fichas[15] = { "Otaviano", "Maximinos", 'F', 1980 };
	fichas[16] = { "Rui", "Maximinos", 'M', 1988 };
	fichas[17] = { "Silverio", "Maximinos", 'M', 1987 };
	fichas[18] = { "Teodoro", "Gualtar", 'M', 1980 };
	fichas[19] = { "Zacarias", "Lindoso", 'M', 1985 };
}

// Pessoa para adicionar na lista
Pessoa NovoItemNaLista() {
	
	Pessoa novaPessoa;

	cout << "\n";
	cout << "Insira um nome: ";
	cin >> novaPessoa.nome;
	cout << "\n";
	cout << "Insira uma freguesia: ";
	cin >> novaPessoa.freguesia;
	cout << "\n";
	cout << "Insira o sexo: ";
	cin >> novaPessoa.sexo;
	cout << "\n";
	cout << "Insira um ano: ";
	cin >> novaPessoa.anoNascimento;
	cout << "\n";

	return novaPessoa;
}

// Adicionar 20 items na Lista Ligada Dupla
ListaPessoasIndexadaApt CriarListaII(ListaPessoasIndexadaApt start)
{
	inicializa_array();

	for (int i = 0; i < TAMANHO; i++)
	{
		start = InserePessoaOrdenado(start, fichas[i], i);
	}

	cout << "Adicionados mais 20 na lista.....\n";

	return start;
}