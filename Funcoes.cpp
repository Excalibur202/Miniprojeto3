/*
	Autor: Rui
	Data de Inicio: 01-07-2022
	Email: pedro_o1992@hotmail.com
	Desc: Funcoes.
*/

#include <iostream>
#include "Dados.h"
#include <string>
#include <fstream>
using namespace std;

/*
	Menu
*/
void Menu()
{
	cout << "-------------Menu-----------------------------------------------\n";
	cout << "1 : Inicializar a lista.\n";
	cout << "2 : Apresentar a lista.\n";
	cout << "3 : Inserir nova ficha, para a posicao p.\n";
	cout << "4 : Com base no ano atual quem e o mais velho da lista ?\n";
	cout << "5 : Quantas raparigas ha na lista ?\n";
	cout << "6 : Quantos rapazes ha em Maximinos ?\n";
	cout << "7 : Remover um item da Lista\n";
	cout << "8 : Alterar um item da Lista.\n";
	cout << "9 : Apagar Lista.\n\n";

	cout <<	"ESC : sair do programa";
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

		/*int contador = 0;
		while (aux != NULL && aux->head != NULL)
		{
			contador++;
			aux = aux->head;
		}

		while (aux != NULL && aux->tail != NULL)
		{
			aux->index = contador;
			contador--;
			aux = aux->tail;
		}*/

		return aux;
	}
}

//Inserir membro na Lista Ligada Simples
ListaPessoasPtr InserePessoaInicio(ListaPessoasPtr fichas, Pessoa pessoa)
{
	ListaPessoasPtr aux = (ListaPessoasPtr)malloc(sizeof(ListaPessoas));

	aux->p = pessoa;
	aux->head = NULL;

	if (fichas == NULL)
	{
		fichas = aux;
		return fichas;
	}
	else
	{
		aux->head = fichas;
		fichas = aux;
	}

	return fichas;
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
		return fichas;
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
			
			//return fichas;
		}
		else
		{
			if (aux->index == fichas->index) //Inserir no meio da lista
			{
				//ListaPessoasIndexada* temp = fichas;
				aux->tail = fichas->tail;
				aux->head = fichas;
				fichas->tail->head = aux;
				fichas->tail = aux;
				fichas = aux;
				//return fichas;
			}
			else  //Inserir no fim da Lista
			{
				//while (fichas->head != NULL) //Certificar que a Lista esta no fim
				//{
				//	fichas = fichas->head;
				//}

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
	//int direction;
	//
	//if (aux->tail == NULL) //inicio da lista
	//	direction = 0; 
	//else if (aux->head == NULL) //fim da lista
	//	direction = 1;
	//else //meio da lista
	//	direction = 2; 

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
				//aux = aux->tail;
				//free(aux->head);
				//aux->head = NULL;
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

//Inicializar Lista Ligada Simples
ListaPessoasPtr CriarLista(ListaPessoasPtr start)
{
	inicializa_array();

	for (int i = 0; i < TAMANHO; i++)
	{
		start = InserePessoaInicio(start, fichas[i]);
	}

	return start;
}

//Inicializar Lista Ligada Dupla
ListaPessoasIndexadaApt CriarListaII(ListaPessoasIndexadaApt start)
{
	inicializa_array();

	for (int i = 0; i < TAMANHO; i++)
	{
		start = InserePessoaOrdenado(start, fichas[i], i);
	}

	return start;
}

//Output da Lista Ligada Simples
void MostraLista(ListaPessoasPtr fichas)
{
	ListaPessoasPtr aux = fichas;

	while (aux != NULL)
	{
		cout << aux->p.nome << "\t";

		if (strlen(aux->p.nome) < 8)
			cout << "\t";

		cout << aux->p.freguesia << "\t";

		if (strlen(aux->p.freguesia) < 8)
			cout << "\t";

		cout << aux->p.sexo << "\t";
		cout << aux->p.anoNascimento << "\n";

		aux = aux->head;
	}
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
		while (aux != NULL && aux->tail != NULL)
		{
			aux = aux->tail;
		}

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

//Minha tentativa de Gravar Lista em Ficheiro (nao esta implementado, nem a funcionar)
bool GravarListaFicheiro(ListaPessoasIndexadaApt lista, ofstream& ficheiro, string nomeFicheiro)
{
	if (lista == NULL)
	{
		return false;
	}
	else 
	{
		ficheiro.open(nomeFicheiro, ios::out /*| ios::trunc*/);

		while (lista != NULL && lista->tail != NULL)
		{
			lista = lista->tail;
		}

		Pessoa novaP;

		while (lista != NULL && lista->head != NULL)
		{
			novaP = lista->pes;

			ficheiro << lista->index;
			ficheiro << &novaP;

			lista = lista->head;
		}
		
		return true;
	}

	return false;
}

//Procurar o membro mais velho(ano de nascimento) da Lista Ligada Simples
void MaisVelho(ListaPessoasPtr fichas)
{
	ListaPessoasPtr aux = fichas;
	string nome;
	string freguesia;
	char sexo;
	int anoMaisVelho = aux->p.anoNascimento;

	if (aux == NULL)
	{
		cout << "Nao existe.....\n";
	}
	else
	{
		while (aux != NULL)
		{
			if (aux->p.anoNascimento < anoMaisVelho)
			{
				anoMaisVelho = aux->p.anoNascimento;
				nome = aux->p.nome;
				freguesia = aux->p.freguesia;
				sexo = aux->p.sexo;
			}

			aux = aux->head;
		}

		cout << nome << "\t" << freguesia << "\t" << sexo << "\t" << anoMaisVelho << "\n";
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
		return -1;
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

////Contar numero de rapazes de acordo com a freguesia na Lista Ligada Dupla
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

//Inicializar array de Pessoas de forma a inicializar a Lista
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
