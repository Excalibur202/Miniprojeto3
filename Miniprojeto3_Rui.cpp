/*
	Autor: Rui
	Data de Inicio: 01-07-2022
	Email: pedro_o1992@hotmail.com
	Desc: Main do programa - aqui vem os Outputs e Inputs.
*/

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include "Dados.h"
using namespace std;

Pessoa fichas[TAMANHO];

int main()
{
	char opcao;
	Pessoa novaPessoa;
	string freg;
	//ListaPessoasPtr start = NULL;
	ListaPessoasIndexadaApt ordenadoStart = NULL;
	bool remover;
	bool alterar;
	//bool ficheiroGravado;
	int posicao;
	//string myPath = "/Miniprojeto3_Rui_Lista/ListaFicheiro.txt";
	//ofstream myFile(myPath);

	do
	{
		system("cls");
		//MeterListaNoFim(ordenadoStart);
		Menu();
		cout << "\n\n";
		cout << "Escolha uma opcao: ";
		opcao = _getche();
		cout << endl;

		switch (opcao)
		{
		case '1':
			//start = CriarLista(start);
			ordenadoStart = CriarListaII(ordenadoStart);
			cout << "Lista Inicializada.....\n";
			_getch();
			break;
		case '2':
			//MostraLista(start);
			//ordenadoStart = AtualizarIndexLista(ordenadoStart);
			MostraListaII(ordenadoStart);
			_getch();
			break;
		case '3':
			cout << "Escolha e Insira uma posicao: ";
			cin >> posicao;
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
			//start = InserePessoaInicio(start, novaPessoa);
			ordenadoStart = InserePessoaOrdenado(ordenadoStart, novaPessoa, posicao);
			//ordenadoStart = AtualizarIndexLista(ordenadoStart);
			cout << "Pessoa inserida.....\n";
			_getch();
			break;
		case '4':
			//MaisVelho(start);
			PessoaMaisVelha(ordenadoStart);
			_getch();
			break;
		case '5':
			if (ContaRaparigas(ordenadoStart) == -1)
			{
				cout << "Nao existem raparigas...\n";
			}
			else
			{
				cout << "Raparigas: " << ContaRaparigas(ordenadoStart) << "\n";
			}
			_getch();
			break;
		case '6':
			cout << "Insira uma Freguesia para procura: ";
			cin >> freg;
			if (ContaRapazes(ordenadoStart, freg) == -1)
			{
				cout << "Nao existem rapazes...\n";
			}
			else
			{
				cout << "Rapazes: " << ContaRapazes(ordenadoStart, freg) << "\n";
			}
			_getch();
			break;
		case '7':
			cout << "\n";
			cout << "Insira uma posicao para remover: ";
			cin >> posicao;
			remover = RemovePessoaPeloIndice(ordenadoStart, posicao);
			//ordenadoStart = AtualizarIndexLista(ordenadoStart);
			if (remover == false)
			{
				cout << "Nao existe membro na Lista!\n";
			}
			else
			{
				cout << "Ficha Removida.....\n";
			}
			_getch();
			break;
		case '8':
			cout << "Escolha e Insira uma posicao: ";
			cin >> posicao;
			alterar = AlterarPessoaLista(ordenadoStart, posicao);
			if (alterar == false)
			{
				cout << "Nao existe membro na Lista.\n";
			}
			else
			{
				cout << "Membro alterado....\n";
			}
			_getch();
			break;
		case '9':
			ordenadoStart = ApagarLista(ordenadoStart);
			_getch();
			break;
		default:
			if (opcao != 27) {
				cout << "Por favor escolha uma das opcoes anteriores......\n";
				_getch();
			}
			break;
		}

	} while (opcao != 27);
}