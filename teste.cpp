#include <bits/stdc++.h>

using namespace std;

void bfs(int inicio, vector<int> *vector_adj, int *visi, int *dist) {
	queue<int> q;
	q.push(u);
	dist[u] = 0;
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		cout << "Distancia de " << u << " a " << v << " eh " << dist[v] << endl;
		for(vector<int>::iterator e = adj[v].begin(); e != adj[v].end(); e++) {
			if(!visi[*e]) {
				dist[*e] = dist[v] + 1;
				q.push(*e);
			}
		}
	}
}

void inserir_no_grafo(int from, int to) {
	adj[from].push_back(to);
}

int main(void) {
	
	int from, to;
	int i;
	int n, ponto_inicial;
	int continuar;
	
	printf("Digite o numero de conexoes que havera em seu grafo: ");
	scanf("%i",&n);
	
	vector<int> adjc[n];
	int visi[n];
	int dist[n];
	
	printf("\n");
	for(i = 0; i < n; i++) {
		printf("De quem parte a conexao: ");
		scanf("%i",&from);
		printf("Para quem vai a conexao: ");
		scanf("%i",&to);
		inserir_no_grafo(from, to);
		printf("\n");
	}
	
	for(i = 0; i < n; i++) {
		cout << i << " = ";
		for(vector<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	
	do {
		memset(visi, 0, sizeof(visi));
		
		printf("\nQual seu ponto inicial para verificar a distancia: ");
		scanf("%i",&ponto_inicial);
		
		bfs(ponto_inicial);
		printf("\n");
		
		printf("Deseja fazer nova consulta? [1-SIM][OUTRO-NAO] ");
		scanf("%i",&continuar);
	}
	while(continuar == 1);

	return 0;
}
