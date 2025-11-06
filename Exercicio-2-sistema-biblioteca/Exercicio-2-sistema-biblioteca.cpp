	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#define MAX_LIVROS 50
	#define TAM_STRING 100

	struct Livro {
		char nome[TAM_STRING];
		char autor[TAM_STRING];
		char editora[TAM_STRING];
		int edicao;
	};
	void limparBufferEntrada() {
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
	}

	int main() {
		struct Livro biblioteca[MAX_LIVROS];
		int totalLivros = 0;
		int opcao;

		// laço principal

		do {
			printf("Biblioteca - Parte 1 \n");
			printf("1- Cadastra novo livro \n");
			printf("2- Listar todos os livros \n");
			printf("0 - Sair \n");
			printf("-------------------------------\n");
			printf("Escolha uma opção\n");

			// Lê a opção do usuário.
			scanf_s	("%d", &opcao);
			limparBufferEntrada();

			switch (opcao) {
			case 1 : // CADASTRO DE LIVRO
				printf("Cadastro de novo livro \n");
				if (totalLivros < MAX_LIVROS) {
					printf("Digite o nome do livro: ");
					fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

					printf("Digite o autor: ");
					fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

					printf("Digite a editora: ");
					fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

					biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
					biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
					biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

					printf("Digite a edicao: ");
					scanf_s("%d", &biblioteca[totalLivros].edicao);
					limparBufferEntrada();

					totalLivros++;

					printf("\n Livro cadastro com sucesso!\n");
				}
				else {
					printf("Biblioteca cheia! não é possivel cadastrar mais livros. \n");
				}
				printf("\n Pressione Enter para continuar...");
				getchar();
				break;

			case 2: // Listagem de livros
				printf("Lista de livros cadastrados");
				if (totalLivros == 0) {
					printf("Nenhum livro cadastrado ainda. \n");
				}
				else {
					for (int i = 0; i < totalLivros; i++) {
						printf("LIVRO %d\n", i + 1);
						printf("Nome: %s\n", biblioteca[i].nome);
						printf("Autor %s\n", biblioteca[i].autor);
						printf("Editora: %s\n", biblioteca[i].editora);
						printf("Edicao: %d\n", biblioteca[i].edicao);		
					}
				} 
				printf("------------------------------------------");
				printf("\n Pressione Enter para Continuar...");
				getchar();
				break;

			case 0:
				printf("\n Saindo do sistema");
				break;

			default:
				printf("Opção inválida! TENTE NOVAMENTE");
				printf("Pressione Enter para continuar");
				getchar();
				break;
			}	
		} while (opcao != 0);

			return 0;
	}