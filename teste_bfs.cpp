#include <bits/stdc++.h>

using namespace std;

void bfs(int inicio, vector< vector<int> > &adj, int *dist) {
	queue<int> q;
	q.push(inicio);
	dist[inicio] = 0;//Distância do ponto inicial ao ponto inicial é 0.
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		cout << "\nDistancia de " << inicio << " a " << v << " eh " << dist[v] << endl;
		for(vector<int>::iterator e = adj[v].begin(); e != adj[v].end(); e++) {//Analisando todos vértices vizinhos do vértice v.
			if(dist[*e] == -1) {//Se a distância ainda não foi determinada.
				dist[*e] = dist[v] + 1;
				q.push(*e);
			}
		}
	}
}

void inserir_no_grafo(int from, int to, vector< vector<int> > &adj) {
	adj[from].push_back(to);
}

int main(void) {
	
	int from, to;
	int i;
	int n_v, n_a, ponto_inicial;
	int continuar;
	
	cout << "Digite o numero de vertices que havera em seu grafo: ";
	cin >> n_v;
	
	vector< vector<int> > adj(n_v);//Guardará os vizinhos de cada vértice.
	int dist[n_v];//Guardará a distância de um certo vértice inicial ao iesimo vértice.
	
	cout << "\nDigite o numero de arestas que havera em seu grafo(arestas de apenas um sentido): ";
	cin >> n_a;
	cout << "\n";
	
	for(i = 0; i < n_a; i++) {
		cout << "De quem parte a conexao: ";
		cin >> from;
		cout << "Para quem vai a conexao: ";
		cin >> to;
		inserir_no_grafo(from, to, adj);//Inserindo as conexões.
		cout << "\n";
	}
	
	for(i = 0; i < n_v; i++) {//Apenas imprimindo os vizinhos de cada vértice.
		cout << i << " = ";
		for(vector<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	
	do {
		memset(dist, -1, sizeof(dist));
		
		cout << "\nQual seu ponto inicial para verificar a distancia: ";
		cin >> ponto_inicial;
		
		bfs(ponto_inicial, adj, dist);//Iniciando o BFS a partir do ponto inicial que foi dado.
		cout << "\n";
		
		cout << "Deseja fazer nova consulta? [1-SIM][OUTRO-NAO] ";
		cin >> continuar;
	}
	while(continuar == 1);

	return 0;
}
