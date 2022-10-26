#include <bits/stdc++.h>

using namespace std;

const int N = 5;//N é o número de vertices de nosso grafo.

vector<int> adj[10000];//Adj é o vetor principal, pois vai falar quem são os vizinhos de cada vertice.
//int vis[N];
int dist[N];

const int INF = 1e9;

void bfs(int u) {
	queue<int> q;
	q.push(u);
	dist[u] = 0;
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		cout << "Distancia de " << u << " a " << v << " eh " << dist[v] << endl;
		for(vector<int>::iterator e = adj[v].begin(); e != adj[v].end(); e++) {
			if(dist[*e] == INF) {
				dist[*e] = dist[v] + 1;
				q.push(*e);
			}
		}
	}
}

void inserir_no_grafo(int de_quem_parte_a_conexao, int para_quem_vai_a_conexao) {
	adj[de_quem_parte_a_conexao].push_back(para_quem_vai_a_conexao);
}

int main(void) {
	
	int de_quem_parte_a_conexao, para_quem_vai_a_conexao;
	int i;
	int n_conexoes, ponto_inicial;
	
	for(i = 0; i < N; i++) {
		dist[i] = INF;
	}
	
	printf("Digite o numero de conexoes que havera em seu grafo: ");
	scanf("%i",&n_conexoes);
	
	printf("\n");
	for(i = 0; i < n_conexoes; i++) {
		printf("De quem parte a conexao: ");
		scanf("%i",&de_quem_parte_a_conexao);
		printf("Para quem vai a conexao: ");
		scanf("%i",&para_quem_vai_a_conexao);
		inserir_no_grafo(de_quem_parte_a_conexao, para_quem_vai_a_conexao);
		printf("\n");
	}
	
	for(i = 0; i < N; i++) {
		cout << i << " = ";
		for(vector<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	
	printf("Qual seu ponto inicial para verificar a distancia: ");
	scanf("%i",&ponto_inicial);
	
	bfs(ponto_inicial);
	cout << endl;

	return 0;
}

