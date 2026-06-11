/*
	Autor: Rui
	Data de Inicio: 01-07-2022
	Email: pedro_o1992@hotmail.com
	Desc: Main do programa - aqui vem os Outputs e Inputs.
*/

// Libraria
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include "Dados.h"
using namespace std;

int main()
{
	// Variaveis
	char opcao;
	Pessoa novaPessoa;
	string freg;
	string linha;
	bool remover;
	bool alterar;
	int posicao;
	ListaPessoasIndexadaApt ordenadoStart = NULL;
	fstream ficheiro;
	ordenadoStart = CriarListaII(ordenadoStart);

	do
	{
		// Clear console
		system("cls");

		// Menu
		Menu();
		cout << "\n\n";
		cout << "Escolha uma opcao (1-9): ";
		opcao = _getche();
		cout << endl;

		switch (opcao)
		{
			case '1':
				// Adicionar 20 pessoas
				ordenadoStart = CriarListaII(ordenadoStart);
				_getch();
			break;
			case '2':
				// Apresesentar lista
				MostraListaII(ordenadoStart);
				_getch();
			break;
			case '3':
				// Inputs da nova Pessoa
				novaPessoa = NovoItemNaLista();
				cout << "Escolha uma posicao indice: ";
				cin >> posicao;
				cout << "\n";
				// Inserir Pessoa
				if (to_string(novaPessoa.anoNascimento).length() != 4 || (novaPessoa.sexo != 'F' && novaPessoa.sexo != 'M')) {
					cout << "Por favor insira as informacoes corretas.\n";
				}
				else {
					ordenadoStart = InserePessoaOrdenado(ordenadoStart, novaPessoa, posicao);
					cout << "Pessoa inserida.....\n";
				}
				_getch();
			break;
			case '4':
				PessoaMaisVelha(ordenadoStart);
				_getch();
			break;
			case '5':
				if (ContaRaparigas(ordenadoStart) <= 0)
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
				cout << "Insira uma Freguesia: ";
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
				if (!remover)
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
				if (!alterar)
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
					cout << "Por favor escolha uma das opcoes......\n";
					_getch();
				}
			break;
		}

	} while (opcao != 27);

	GravarEmFicheiro(ordenadoStart);
}