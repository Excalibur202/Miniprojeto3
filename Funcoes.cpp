/*
	Autor: Rui
	Data de Inicio: 01-07-2022
	Email: pedro_o1992@hotmail.com
	Desc: Logica do programa - Funções
*/

#include <iostream>
#include "Dados.h"
#include <string>
#include <fstream>
#include <conio.h>
#include <sstream>
using namespace std;

/*
	Menu
*/
void Menu()
{
	cout << "-------------Menu-----------------------------------------------\n";
	cout << "|| 1 : Adicionar 20 pessoas.\n";
	cout << "|| 2 : Apresentar a lista (READ).\n";
	cout << "|| 3 : Inserir pessoa (CREATE).\n";
	cout << "|| 4 : Listar membro mais velho.\n";
	cout << "|| 5 : Listar numero de raparigas.\n";
	cout << "|| 6 : Listar numero de rapazes pela a freguesia.\n";
	cout << "|| 7 : Remover um item da lista (DELETE).\n";
	cout << "|| 8 : Alterar um item da lista (UPDATE).\n";
	cout << "|| 9 : Apagar todos os itens da lista.\n";
	cout << "||";
	cout <<	"|| ESC : sair do programa";
}

//Meter o ultimo membro da Lista no fim
ListaPessoasIndexadaApt MeterListaNoFim(ListaPessoasIndexadaApt fichas)
{
	while (fichas != NULL && fichas->head != NULL)
	{
		fichas = fichas->head;
	}

	return fichas;
}

//Meter o ultimo membro da Lista no inicio
ListaPessoasIndexadaApt MeterListaNoInicio(ListaPessoasIndexadaApt fichas)
{
	while (fichas != NULL && fichas->tail != NULL)
	{
		fichas = fichas->tail;
	}

	return fichas;
}

//Ordenadar o indice da Lista Ligada Dupla
ListaPessoasIndexadaApt AtualizarIndexLista(ListaPessoasIndexadaApt fichas)
{
	ListaPessoasIndexadaApt aux = fichas;

	if (aux == NULL)
	{
		return NULL;
	}
	else
	{
		aux = MeterListaNoInicio(aux);
		int i;
		for (i = 0; aux != NULL && aux->head != NULL; i++)
		{
			aux->index = i;
			aux = aux->head;
		}

		aux->index = i;

		return aux;
	}
}

//Inserir membro na Lista Ligada Dupla de acordo com o index
ListaPessoasIndexadaApt InserePessoaOrdenado(ListaPessoasIndexadaApt fichas, Pessoa novaPessoa, int indice)
{
	ListaPessoasIndexadaApt aux = (ListaPessoasIndexadaApt)malloc(sizeof(ListaPessoasIndexada));

	aux->pes = novaPessoa;
	aux->index = indice;
	aux->head = NULL;
	aux->tail = NULL;

	if (fichas == NULL) //Lista Vazia
	{
		fichas = aux;
	}
	else
	{
		fichas = MeterListaNoFim(fichas);

		while (fichas != NULL && aux->index < fichas->index && fichas->tail != NULL) //Procurar onde inserir
		{
			fichas = fichas->tail;
		}

		if (aux->index <= 0) //Inserir no inicio da Lista
		{
			aux->head = fichas;
			fichas->tail = aux;
			fichas = aux;
		}
		else
		{
			if (aux->index == fichas->index) //Inserir no meio da lista
			{
				aux->tail = fichas->tail;
				aux->head = fichas;
				fichas->tail->head = aux;
				fichas->tail = aux;
				fichas = aux;
			}
			else  //Inserir no fim da Lista
			{
				fichas->head = aux;
				aux->tail = fichas;
				fichas = aux;
			}
		}
	}

	fichas = AtualizarIndexLista(fichas);

	return fichas;
}

//Remover membro da Lista Ligada Dupla de acordo com o index
bool RemovePessoaPeloIndice(ListaPessoasIndexadaApt fichas, int indice)
{
	ListaPessoasIndexadaApt aux = fichas;

	if (aux == NULL) //Lista Vazia
	{
		return false;
	}
	else
	{
		aux = MeterListaNoFim(aux);

		while (aux != NULL && aux->index > indice) //Procurar onde remover
		{
			aux = aux->tail;
		}

		if (aux->index == indice) //Encontrou
		{
			if (aux->tail == NULL) //Remover no inicio da Lista
			{
				aux->head->tail = NULL;
				aux->head->index = 0;
				free(aux);
			}
			else if (aux->head == NULL)  //Remover no fim da Lista
			{
				aux->tail->head = NULL;
				free(aux->head);
			}
			else //Remover no meio da Lista
			{
				aux->tail->head = aux->head;
				aux->head->tail = aux->tail;
				free(aux);
			}

			fichas = AtualizarIndexLista(fichas);

			return true;
		}
	}

	return false;
}

//Alterar membro da Lista Ligada Dupla de acordo com o index
bool AlterarPessoaLista(ListaPessoasIndexadaApt fichas, int indice) 
{
	fichas = ProcuraPessoaIndex(fichas, indice);

	if (fichas == NULL)
	{
		return false;
	}
	else
	{
		Pessoa pessoa;
		cout << "\n";
		cout << "Insira um nome: ";
		cin >> pessoa.nome;
		cout << "\n";
		cout << "Insira uma freguesia: ";
		cin >> pessoa.freguesia;
		cout << "\n";
		cout << "Insira o sexo: ";
		cin >> pessoa.sexo;
		cout << "\n";
		cout << "Insira um ano: ";
		cin >> pessoa.anoNascimento;
		cout << "\n";

		for (int i = 0; i < TAMANHO; i++)
		{
			fichas->pes.nome[i] = pessoa.nome[i];
			fichas->pes.freguesia[i] = pessoa.freguesia[i];
		}
		fichas->pes.sexo = pessoa.sexo;
		fichas->pes.anoNascimento = pessoa.anoNascimento;


		return true;
	}

	return false;
}

//Output da Lista Ligada Dupla
void MostraListaII(ListaPessoasIndexadaApt fichas)
{
	ListaPessoasIndexadaApt aux = fichas;

	if (aux == NULL)
	{
		cout << "Nao existe Lista!\n";
	}
	else
	{
		aux = MeterListaNoInicio(aux);

		while (aux != NULL)
		{
			cout << aux->index << "\t";
			cout << aux->pes.nome << "\t";

			if (strlen(aux->pes.nome) < 8)
				cout << "\t";

			cout << aux->pes.freguesia << "\t";

			if (strlen(aux->pes.freguesia) < 8)
				cout << "\t";

			cout << aux->pes.sexo << "\t";
			cout << aux->pes.anoNascimento << "\n";

			aux = aux->head;
		}
	}
}

//Procurar membro da Lista Ligada Dupla apartir do index
ListaPessoasIndexadaApt ProcuraPessoaIndex(ListaPessoasIndexadaApt fichas, int indice)
{
	if (fichas == NULL)
	{
		return NULL;
	}
	else
	{
		fichas = MeterListaNoFim(fichas);

		ListaPessoasIndexadaApt aux = fichas;

		while (aux != NULL)
		{
			if (aux->index == indice)
			{
				return aux;
			}

			aux = aux->tail;
		}

		return NULL;
	}
}

//Procurar o membro mais velho(ano de nascimento) da Lista Ligada Dupla
void PessoaMaisVelha(ListaPessoasIndexadaApt lista)
{
	if (lista == NULL)
	{
		cout << "Nao existe membro mais velho.....\n";
	}
	else
	{
		lista = MeterListaNoInicio(lista);
		string nome;
		string freguesia;
		char sexo;
		int indice;
		int anoMaisVelho = lista->pes.anoNascimento;

		while (lista != NULL && lista->head != NULL)
		{
			if (lista->pes.anoNascimento < anoMaisVelho)
			{
				anoMaisVelho = lista->pes.anoNascimento;
				nome = lista->pes.nome;
				freguesia = lista->pes.freguesia;
				sexo = lista->pes.sexo;
				indice = lista->index;
			}

			lista = lista->head;
		}

		cout << indice << "\t" << nome << "\t" << freguesia << "\t" << sexo << "\t" << anoMaisVelho << "\n";
	}
}

//Contar numero de raparigas na Lista Ligada Dupla
int ContaRaparigas(ListaPessoasIndexadaApt lista)
{
	int contador = 0;

	if (lista == NULL)
	{
		return contador;
	}
	else
	{
		lista = MeterListaNoInicio(lista);

		while (lista != NULL && lista->head != NULL)
		{
			if (lista->pes.sexo == 'F')
			{
				contador++;
			}

			lista = lista->head;
		}
	}

	return contador;
}

//Contar numero de rapazes de acordo com a freguesia na Lista Ligada Dupla
int ContaRapazes(ListaPessoasIndexadaApt lista, string freg)
{
	int contador = 0;

	if (lista == NULL)
	{
		return -1;
	}
	else
	{
		lista = MeterListaNoInicio(lista);
		while (lista != NULL && lista->head != NULL)
		{
			if (lista->pes.sexo == 'M' && lista->pes.freguesia == freg)
			{
				contador++;
			}

			lista = lista->head;
		}
	}

	return contador;
}

//Apagar Lista
ListaPessoasIndexadaApt ApagarLista(ListaPessoasIndexadaApt lista)
{
	ListaPessoasIndexada* aux;

	if (lista == NULL)
	{
		return NULL;
	}
	else
	{
		lista = MeterListaNoInicio(lista);

		while (lista != NULL)
		{
			aux = lista->head;
			free(lista);
			lista = aux;
		}

		cout << "Lista apagada....\n";
	}
	
	return lista;
}

// Gravar lista num ficheiro de texto
void GravarEmFicheiro(ListaPessoasIndexadaApt lista)
{
	ofstream ficheiro("Lista.txt");

	if (!ficheiro) {
		cout << "Verifique que o ficheiro \"Lista.txt\" se encontra no pasta.\n";
		return;
	}

	lista = MeterListaNoInicio(lista);

	while(lista != NULL)
	{
		ficheiro << lista->pes.nome << " "
			<< lista->pes.freguesia << " "
			<< lista->pes.sexo << " "
			<< lista->pes.anoNascimento
			<< "\n";
		
		lista = lista->head;
	}

	ficheiro.close();
}